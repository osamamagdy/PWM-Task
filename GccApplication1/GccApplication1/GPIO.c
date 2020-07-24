/*
 * GPIO.c
 *
 * Created: 7/23/2020 12:10:00 AM
 *  Author: Osama
 */ 

#include "GPIO.h"
#include <avr/io.h>

void GPIOInit(void)
{
	// Configuring the direction of OC1A & OC1B as output pins
	DDRB |= (1<<OC1A) | (1<<OC1B);
}
