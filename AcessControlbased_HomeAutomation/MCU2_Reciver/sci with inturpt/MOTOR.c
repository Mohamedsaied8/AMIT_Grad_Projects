/*
 * tofwi.c
 *
 * Created: 9/1/2019 2:06:05 PM
 *  Author: omar
 */ 
#include "MOTOR.h"
#include "UART.h"
 void MotorInit() // timer initialize   to activate interrupt
 {
	 DDRA=0XFF;
	 sei();
	 TCCR0=0X85;
	 TIMSK=0X01;
 }
 void MotorStop()
 {
	 DDRA=0XFF;
	 TCCR0=0X00;
	 TIMSK=0X00;
 }
 void MotorStart()
 {
	 if(tc>20&&tc<40)
	 {
		 PORTA&=!(1<<PA5);
		 PORTA=PORTA^(1<<PA6);
		 PORTA=PORTA^(1<<PA7);
		 PORTA=PORTA^(1<<PA4);
	 }
	 if(tc<20&&tc>=0)
	 {
		 PORTA&=!(1<<PA6);
		 PORTA=PORTA^(1<<PA5);
		 PORTA=PORTA^(1<<PA7);
		 PORTA=PORTA^(1<<PA4);
	 }
	 tc++;
	 if(tc>=40)
	 {tc=0;
		 MotorStop();
		 PORTA=0x00;
	 }
	 
 }