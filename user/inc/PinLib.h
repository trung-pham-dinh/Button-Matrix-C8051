#ifndef PINLIB
#define PINLIB

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

typedef enum {
	PL_00,
	PL_01,
	PL_02,
	PL_03,
	PL_04,
	PL_05,
	PL_06,
	PL_07,

	PL_10,
	PL_11,
	PL_12,
	PL_13,
	PL_14,
	PL_15,
	PL_16,
	PL_17,

	PL_20,
	PL_21,
	PL_22,
	PL_23,
	PL_24,
	PL_25,
	PL_26,
	PL_27,
} PL_PIN;


void PL_WritePin(PL_PIN pin, uint8_t logic);
uint8_t PL_ReadPin(PL_PIN pin);
void PL_TogglePin(PL_PIN pin);
#endif