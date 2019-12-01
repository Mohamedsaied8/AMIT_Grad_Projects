/*
 * Robotic Car Atmega32A.c
 *
 * Created: 8/3/2019 2:30:17 AM
 * Author : mahmo
 */ 

#define  F_CPU 16000000UL
#include "Utills.h"
#include "STD_types.h"
#include <avr/io.h>
#include "LCD.h"
#include "LCD_cfg.h"
#include "USART.h"




int main(void)
{
    /* Replace with your application code */
	LCD_Init();
	UART_Init();
	DDRC = 0b11110000;
	PORTC = 0;
// 	DDRA =  0b00000001;
// 	PORTA = 0b00000001;
    while (1) 
    {
		unsigned char x;
		x = UART_RecieveData();
		LCD_WriteData(x);
		
		if (x == '2'){
			PORTC = 0b10010000;
		}
		else if (x== '4'){
			PORTC = 0b01100000;
		}
		else if (x == '1'){
			PORTC = 0b10100000;
		}
		else if (x == '3') {
			PORTC = 0b01010000;
		}
		else{
			PORTC = 0;
		}
    }
}

