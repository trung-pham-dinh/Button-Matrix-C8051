#include "MatrixReading.h"

#include "compiler_defs.h"
#include "C8051F930_defs.h"

#define MR_PRESSED 0
#define MR_RELEASED 1

static PL_PIN rowpin[MR_ROW] = {PL_20,PL_21,PL_22,PL_23}; // edit this
static PL_PIN colpin[MR_COL] = {PL_24,PL_25,PL_26}; // edit this

static uint8_t buttonState[MR_ROW][MR_COL];
static uint8_t debouncePreState[MR_ROW][MR_COL];
static uint8_t debounceCurState[MR_ROW][MR_COL];

static uint8_t colIndex = 0;

static uint8_t sample_period = MR_SAMPLE_PERIOD;

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
			PL_WritePin(rowpin[i], 1); // enable input mode for all row
			buttonState[i][j] = debouncePreState[i][j] = debounceCurState[i][j] = MR_RELEASED;
			click_state[i][j] = MR_VLD_RELEASED;
			click_flag[i][j] = 0;
		}
		PL_WritePin(colpin[j], 1); // disable all column
	}
}

void MR_readState() {
	uint8_t i = 0;
	
	if(sample_period) return;
	sample_period = MR_SAMPLE_PERIOD;
	
	
	
	PL_WritePin(colpin[colIndex], 0); // enable column to read
	
	for(; i < MR_ROW; i++) {
		debouncePreState[i][colIndex] = debounceCurState[i][colIndex];
		debounceCurState[i][colIndex] = PL_ReadPin(rowpin[i]);
		if(debounceCurState[i][colIndex] == debouncePreState[i][colIndex]) {
			buttonState[i][colIndex] = debounceCurState[i][colIndex];
		}
	}
	PL_WritePin(colpin[colIndex], 1); // disable column
	
	colIndex++;
	if(colIndex == MR_COL) {
		colIndex = 0;
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

