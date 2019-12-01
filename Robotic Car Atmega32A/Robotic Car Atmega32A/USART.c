/*
 * USART.c
 *
 * Created: 5/11/2019 9:47:35 AM
 *  Author: mahmo
 */ 

#define F_CPU (16000000UL)
#include "STD_types.h"
#include "Utills.h"
#include "avr/io.h"
#include "USART.h"


extern void UART_Init(void){
	set_bit(DDRD,1);
	clr_bit(DDRD,0);
	UCSRC = 0b10000110;
	UBRRL = 103;
	set_bit(UCSRB,3);
	set_bit(UCSRB,4);
	
}

extern u8 UART_RecieveData(void){
	while(get_bit(UCSRA,7) == 0);
 	return UDR;
	

}

extern void UART_TransData(u8 data){
 	while(get_bit(UCSRA,5) == 0);
 	UDR = data;


}
