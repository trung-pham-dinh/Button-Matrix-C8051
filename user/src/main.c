#include "compiler_defs.h"
#include "C8051F930_defs.h"
#include "peripherals.h"

#include "MatrixReading.h"
#include "PinLib.h"

uint8_t i,j;


PL_PIN led[4][3] = {{PL_00, PL_01, PL_02},
										{PL_03, PL_04, PL_05},
										{PL_06, PL_07, PL_10},
										{PL_11, PL_12, PL_13}};

void main() {
	PCA0MD = 0;	// watchdog disable
	Init_Device();
	P0 = P1 = P2 = 0;
	
	MR_init();
	
	
	while(1) {
		MR_readState();
		MR_readClick();
		
		for(i= 0; i < 4; i++) {
			for(j=0; j<3; j++) {
				if(MR_IsClick(i,j)) {
					PL_TogglePin(led[i][j]);
				}
			}
		}
	}
}


void TIMER_ISR() interrupt INTERRUPT_TIMER0 { // 1ms interrupt period
	MR_sampling();
	
	TL0 = LOW_RELOAD_0;
  TH0 = HIGH_RELOAD_0;
}