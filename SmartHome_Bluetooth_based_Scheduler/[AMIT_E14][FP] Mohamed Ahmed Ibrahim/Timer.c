/*
 * Timer.c
 *
 * Created: 2/15/2019 6:52:46 PM
 *  Author: Mohamed Ahmed
 */ 

#include "Types.h"
#include "Timer.h"
#include <avr/interrupt.h>
#include <avr/io.h>

volatile uint8 Timer_Flag=0;
volatile uint32 Timer_Counter=0;

void Timer_Init(void)
{
	TCCR1B=(1<<WGM12)|(1<<CS10);
	OCR1A=11999;
	TIMSK=(1<<OCIE1A);
	sei();
}
	
ISR(TIMER1_COMPA_vect)
	{
		Timer_Counter++;
		Timer_Flag=1;
		
		
	}

