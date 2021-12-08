#include "PinLib.h"

#include "compiler_defs.h"
#include "C8051F930_defs.h"
#include <intrins.h>

sbit P0_0 = P0^0;
sbit P0_1 = P0^1;
sbit P0_2 = P0^2;
sbit P0_3 = P0^3;
sbit P0_4 = P0^4;
sbit P0_5 = P0^5;
sbit P0_6 = P0^6;
sbit P0_7 = P0^7;

sbit P1_0 = P1^0;
sbit P1_1 = P1^1;
sbit P1_2 = P1^2;
sbit P1_3 = P1^3;
sbit P1_4 = P1^4;
sbit P1_5 = P1^5;
sbit P1_6 = P1^6;
sbit P1_7 = P1^7;

sbit P2_0 = P2^0;
sbit P2_1 = P2^1;
sbit P2_2 = P2^2;
sbit P2_3 = P2^3;
sbit P2_4 = P2^4;
sbit P2_5 = P2^5;
sbit P2_6 = P2^6;
sbit P2_7 = P2^7;

//void PL_WritePin(uint8_t port, uint8_t pin, uint8_t logic) { // this function sometime work wrong because of the hardware transition(0->1) may be slow, detail in problem.txt
//unsigned char i;
//	switch(port) {
//		case PL_PORT_0:
//			P0 = (logic)? P0|pin : P0&(~pin);
//			break;
//		case PL_PORT_1:
//			P1 = (logic)? P1|pin : P1&(~pin);
//			break;
//		case PL_PORT_2:
//			P2 = (logic)? P2|pin : P2&(~pin);
//			break;
//	}
//	for (i = 0; i < 1; i++) _nop_();
//}

//uint8_t PL_ReadPin(uint8_t port, uint8_t pin) {
//	switch(port) {
//		case PL_PORT_0:
//			return (P0 & pin) != 0 ;
//		case PL_PORT_1:
//			return (P1 & pin) != 0;
//		case PL_PORT_2:
//			return (P2 & pin) != 0;
//		default:
//			break;
//	}
//	return 0;
//}

void PL_WritePin(PL_PIN pin, uint8_t logic) {
	switch(pin) {
		case PL_00:
			P0_0 = logic;
			break;
		case PL_01:
			P0_1 = logic;
			break;
		case PL_02:
			P0_2 = logic;
			break;
		case PL_03:
			P0_3 = logic;
			break;
		case PL_04:
			P0_4 = logic;
			break;
		case PL_05:
			P0_5 = logic;
			break;
		case PL_06:
			P0_6 = logic;
			break;
		case PL_07:
			P0_7 = logic;
			break;
		
		case PL_10:
			P1_0 = logic;
			break;
		case PL_11:
			P1_1 = logic;
			break;
		case PL_12:
			P1_2 = logic;
			break;
		case PL_13:
			P1_3 = logic;
			break;
		case PL_14:
			P1_4 = logic;
			break;
		case PL_15:
			P1_5 = logic;
			break;
		case PL_16:
			P1_6 = logic;
			break;
		case PL_17:
			P1_7 = logic;
			break;
			
		case PL_20:
			P2_0 = logic;
			break;
		case PL_21:
			P2_1 = logic;
			break;
		case PL_22:
			P2_2 = logic;
			break;
		case PL_23:
			P2_3 = logic;
			break;
		case PL_24:
			P2_4 = logic;
			break;
		case PL_25:
			P2_5 = logic;
			break;
		case PL_26:
			P2_6 = logic;
			break;
		case PL_27:
			P2_7 = logic;
			break;
		default:
			break;
	}
}

uint8_t PL_ReadPin(PL_PIN pin) {
	switch(pin) {
		case PL_00:
			return P0_0;
		case PL_01:
			return P0_1;
			break;
		case PL_02:
			return P0_2;
			break;
		case PL_03:
			return P0_3;
			break;
		case PL_04:
			return P0_4;
			break;
		case PL_05:
			return P0_5;
			break;
		case PL_06:
			return P0_6;
			break;
		case PL_07:
			return P0_7;
			break;
		
		case PL_10:
			return P1_0;
		case PL_11:
			return P1_1;
			break;
		case PL_12:
			return P1_2;
			break;
		case PL_13:
			return P1_3;
			break;
		case PL_14:
			return P1_4;
			break;
		case PL_15:
			return P1_5;
			break;
		case PL_16:
			return P1_6;
			break;
		case PL_17:
			return P1_7;
			
		case PL_20:
			return P2_0;
			break;
		case PL_21:
			return P2_1;
			break;
		case PL_22:
			return P2_2;
			break;
		case PL_23:
			return P2_3;
			break;
		case PL_24:
			return P2_4;
			break;
		case PL_25:
			return P2_5;
			break;
		case PL_26:
			return P2_6;
			break;
		case PL_27:
			return P2_7;
			break;
		default:
			break;
	}
	return 0;
}

void PL_TogglePin(PL_PIN pin) {
	switch(pin) {
		case PL_00:
			P0_0 = !P0_0;
			break;
		case PL_01:
			P0_1 = !P0_1;
			break;
		case PL_02:
			P0_2 = !P0_2;
			break;
		case PL_03:
			P0_3 = !P0_3;
			break;
		case PL_04:
			P0_4 = !P0_4;
			break;
		case PL_05:
			P0_5 = !P0_5;
			break;
		case PL_06:
			P0_6 = !P0_6;
			break;
		case PL_07:
			P0_7 = !P0_7;
			break;
		
		case PL_10:
			P1_0 = !P1_0;
			break;
		case PL_11:
			P1_1 = !P1_1;
			break;
		case PL_12:
			P1_2 = !P1_2;
			break;
		case PL_13:
			P1_3 = !P1_3;
			break;
		case PL_14:
			P1_4 = !P1_4;
			break;
		case PL_15:
			P1_5 = !P1_5;
			break;
		case PL_16:
			P1_6 = !P1_6;
			break;
		case PL_17:
			P1_7 = !P1_7;
			break;
			
		case PL_20:
			P2_0 = !P2_0;
			break;
		case PL_21:
			P2_1 = !P2_1;
			break;
		case PL_22:
			P2_2 = !P2_2;
			break;
		case PL_23:
			P2_3 = !P2_3;
			break;
		case PL_24:
			P2_4 = !P2_4;
			break;
		case PL_25:
			P2_5 = !P2_5;
			break;
		case PL_26:
			P2_6 = !P2_6;
			break;
		case PL_27:
			P2_7 = !P2_7;
			break;
		default:
			break;
	}
}