/*
 * Timer1.c
 *
 * Created: 7/23/2020 12:14:16 AM
 *  Author: Osama
 */ 

#include "Timer1.h"

void Timer1Init()
{
	// Choosing phase correct mode with ICR1
	TCCR1A |= (1<<WGM11) | (1<<COM1A1) | (1<<COM1A0) | (1<<COM1B1) ; // Choosing inverter mode for OCR1A and non-inverter mode for OCR1B
	TCCR1B |= (1<<WGM13) | (1<<CS10); //And setting prescaler to none
	ICR1 = 100; // Setting the TOP count to have a priodic time 200 us
	OCR1A = 50 ;// The duty cycle is 50%
	OCR1B = 50;
	
}