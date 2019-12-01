/*
 * PWM.c
 *
 * Created: 5/4/2019 10:27:21 AM
 *  Author: mahmo
 */ 

#define F_CPU (16000000UL)
#include "STD_types.h"
#include "Utills.h"
#include <avr/io.h>
#include "PWM.h"

extern void Timer1_PWM_Init(){
	TCCR1A = 0b10000010;
	TCCR1B = 0b00011100;
	ICR1   = 1250; //Same job as OCR in Timer0 compare match 
	DDRD   =  0b00100000;
}

extern u16 Timer1_PWM_Read(){
	u16 duty_Read;
	set_bit(TCCR1B,7);
	set_bit(TCCR1B,6);	
	set_bit(TIMSK,5);
	duty_Read = OCR1A;
	return duty_Read;
}

