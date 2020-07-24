/*
 * Timer1.c
 *
 * Created: 7/23/2020 12:14:16 AM
 *  Author: Osama
 */ 

#include "Timer1.h"

void Timer1Init()
{
	//Note: the initial value of registers is logical 0 so if we want to write 1 0 and it is the first use,
    // we will just set the logical 1 only (the logical 0 is set by default).
	TCCR1A |= (1<<WGM11); //Choosing phase correct mode (with adjustable TOP value) by setting WGM13:0 --> 1 0 1 0 
	TCCR1B |= (1<<WGM13); //Note: WGM13 and WGM12 are located in TCCR1B
	
	/*
	For Phase correct mode:
	 Choosing inverter mode for OCR1A and non-inverted mode for OCR1B
	When COM1A1:0 ---> 1 1 , it means to set OC1A on compare match when up-counting,
	and clear OC1A on compare match when down counting.
	
	When COM1B1:0 ---> 1 0 , it means to clear OC1B on compare match when up-counting,
	and set OC1A on compare match when down counting.
	*/
	/////////This is to make two complementary waves////////////
	
	TCCR1A |= (1<<COM1A1); 
	TCCR1A |= (1<<COM1A0);
	TCCR1A |= (1<<COM1B1) ; 
	
	
	
	/*
	To have a periodic time of 200 us, 
	we divide the internal clock frequency(8*10^6Hz) / 2 * the wave freguency (5000Hz) = 800
	(i.e. when the TCNT1 counts up to 800 ticks, it means 200 micro seconds have passed)
	Since the TCNT1 is a 16-bit register that can hold up to 65535, we don't need a prescaler 
	If we choosed a duty cycle of 50% on OC1A pin, we mean to make the OCR1A half of the ICR1 (0.5*800=400)
	The other wave must have a dead time of 10 us (this is 5% of the periodic time).
	But we need to make a dead time in counting up and counting down.
	So, we make the second wave on the OC1B pin uses a duty cycle of 40% ( this is 10% less than the previous one)	
	-----> OCR1B = 0.4*ICR1 = 0.4 * 800 = 320 
	*/
	
	
	TCCR1B |= (1<<CS10); // Setting prescaler to none
	
	ICR1 = 800; // Setting the TOP count to have a periodic time 200 us
	OCR1A = 400 ;// The duty cycle is 50%
	OCR1B = 320; // The duty cycle is 40%
	
}