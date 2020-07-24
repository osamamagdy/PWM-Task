/*
 * GccApplication1.c
 *
 * Created: 7/22/2020 1:49:51 PM
 * Author : Osama
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include "GPIO.h"
#include "Timer1.h"
int main(void)
{
	// Making it outputs
	
	GPIOInit();
	
	// Timer1 
	
	Timer1Init();
	
    /* Replace with your application code */
    while (1) 
    {
		/*
		We don't need to write any code in here, 
		we configure our registers to automatically generate pulses when the counter reaches the value of OCRnX.
		Anyway, we must make an infinite loop inside the main function to make the micro controller works repeatedly
		*/
    }
}
 
