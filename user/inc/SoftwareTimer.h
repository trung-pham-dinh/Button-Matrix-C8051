#ifndef SOFTWARETIMER
#define SOFTWARETIMER



#define ST_NO_TIMERS 2


void timer_run();
void ST_delay(unsigned int mils);
unsigned char ST_get_flag(unsigned char timer);
void ST_set_timer(unsigned char timer, unsigned int mils);

#endif