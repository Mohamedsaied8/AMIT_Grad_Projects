/*
 * Timer.c
 *
 * Created: 5/3/2019 10:48:26 AM
 *  Author: mahmo
 */ 

#define F_CPU (16000000UL)
#include "STD_types.h"
#include "Utills.h"
//#include "DIO.h"
#include "avr/io.h"
//#include "RIGISTERS.h"
#include "Timer.h"
/*
extern void Timer0_Init(){
	TCCR0 = 0b00000101;
	TIMSK = 0b00000001;
	set_bit(SREG,7);
}
*/
extern void Timer0_InitCM(){
	TCCR0 = 0b00001101;
	OCR0  = 125;
	TIMSK = 0b00000011;
	set_bit(SREG,7);
}

