#ifndef MATRIXREADING
#define MATRIXREADING

#include "PinLib.h"
 
#define MR_ROW 4 // edit this
#define MR_COL 3 // edit this
#define MR_PORT 2 // edit this
#define MR_SAMPLE_PERIOD 10// edit this (ms)

void MR_init();
void MR_readState();
uint8_t MR_IsPressed(uint8_t r, uint8_t c);
void MR_readClick();
uint8_t MR_IsClick(uint8_t r, uint8_t c);
void MR_sampling(); // call this function each 1ms(should put this in timer interrupt ISR)

#endif