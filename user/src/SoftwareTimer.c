#include "SoftwareTimer.h"

#include "compiler_defs.h"
#include "C8051F930_defs.h"

static unsigned int counter[ST_NO_TIMERS];
static unsigned char flag[ST_NO_TIMERS];
static unsigned int delay;
static unsigned char i;


void ST_set_timer(unsigned char timer, unsigned int mils) {
	if(timer >= ST_NO_TIMERS) return;
	counter[timer] = mils;
}

unsigned char ST_get_flag(unsigned char timer) {
	if(timer >= ST_NO_TIMERS) return 0;
	
	if(flag[timer] == 1) {
		flag[timer] = 0;
		return 1;
	}
	return 0;
}

void ST_delay(unsigned int mils) {
	delay = mils;
	while(delay);
}


void timer_run() { // must be put in 1ms interrupt timer ISR
	for(i=0; i < ST_NO_TIMERS; i++) {
		if(counter[i]) {
			counter[i]--;
			if(!counter[i]) {
				flag[i] = 1;
			}
		}
	}
	if(delay) {
		delay--;
	}
}