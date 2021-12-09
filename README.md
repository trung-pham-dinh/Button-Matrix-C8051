# Button-Matrix-C8051
Button scanning on C8051F920 

Firstly, call MR_init() in the beginning \
Secondly, call MR_sampling() each 1ms, should put it in TIMER ISR \
Thirdly, call MR_readClick() and MR_readState() in superloop \
Finally, call MR_IsClick() to check if button is clicked. 
