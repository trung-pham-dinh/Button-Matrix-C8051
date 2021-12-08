#include "MatrixReading.h"

#include "compiler_defs.h"
#include "C8051F930_defs.h"

#define MR_PRESSED 1
#define MR_RELEASED 0

#define MR_DELAY_FOR_CHANGE 10 // delay for state of the pin change completely from 0->1

static uint8_t row,col;

static uint8_t buttonState[MR_ROW][MR_COL];
static uint8_t debouncePreState[MR_ROW][MR_COL];
static uint8_t debounceCurState[MR_ROW][MR_COL];

static uint8_t sample_period = MR_SAMPLE_PERIOD;

static uint8_t delay = MR_DELAY_FOR_CHANGE;

typedef enum {
	MR_VLD_RELEASED,
	MR_VLD_PRESSED
} MR_STATE;

static MR_STATE click_state[MR_ROW][MR_COL];
static uint8_t click_flag[MR_ROW][MR_COL];

void MR_init() {
	uint8_t i = 0, j = 0;
	for(; j < MR_COL; j++) {
		for(i = 0; i < MR_ROW; i++) {
			buttonState[i][j] = debouncePreState[i][j] = debounceCurState[i][j] = MR_RELEASED;
			click_state[i][j] = MR_VLD_RELEASED;
			click_flag[i][j] = 0;
		}
	}
}

void MR_readState() { // read more about algorithm in algorithm.txt
	uint8_t i,j;
	
	if(sample_period) return;
	sample_period = MR_SAMPLE_PERIOD;
	
	P2 = 0x8F; // set all rows and reset all columns
	
	delay = MR_DELAY_FOR_CHANGE;
	while(delay--);
	
	row = P2 & 0x8F; // read rows
	
	delay = MR_DELAY_FOR_CHANGE;
	while(delay--);
	
	P2 = row | 0xF0; // reset the rows which are read
	
	delay = MR_DELAY_FOR_CHANGE;
	while(delay--);
	
	col = (P2>>4);
	
	for(i = 0; i < MR_ROW ; i++) {
			for(j= 0; j < MR_COL; j++) {
					debouncePreState[i][j] = debounceCurState[i][j];
					debounceCurState[i][j] = ((row & (0x01<<i)) == 0) && ((col & (0x01<<j)) == 0);
					if(debounceCurState[i][j] == debouncePreState[i][j]) {
						buttonState[i][j] = debounceCurState[i][j];
					}
			}
	}
}

void MR_sampling() {
	if(sample_period) {
		sample_period--;
	}
}

uint8_t MR_IsPressed(uint8_t r, uint8_t c) {
	return buttonState[r][c] == MR_PRESSED;
}

void MR_readClick() {
	uint8_t i = 0, j = 0;
	for(; i < MR_ROW; i++) {
		for(j = 0; j < MR_COL; j++) {
			
			switch(click_state[i][j]) {
				case MR_VLD_RELEASED:
					if(MR_IsPressed(i,j)) {
						click_state[i][j] = MR_VLD_PRESSED;
					}
					break;
				case MR_VLD_PRESSED:
					if(!MR_IsPressed(i,j)) {
						click_flag[i][j] = 1;
						click_state[i][j] = MR_VLD_RELEASED;
					}
					break;
			}
			
		}
	}
}

uint8_t MR_IsClick(uint8_t r, uint8_t c) {
	if(click_flag[r][c]) {
		click_flag[r][c] = 0;
		return 1;
	}
	return 0;
}

