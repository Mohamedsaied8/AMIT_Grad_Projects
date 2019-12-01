/*
 * UART.c
 *
 * Created: 8/17/2019 11:51:47 AM
 *  Author: omar
 usra  tx we data flag  come from transmiteer u only get the flag  of reciver of u one who recive
 */ 
#include "UART.h"
void UART_init()
{
	UCSRA|=0x00;
	UCSRB|=(1<<RXEN)|(1<<TXEN);
	UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UBRRL=103;
}
void UART_sendbyte(uint8 data)
{
	while (!(UCSRA&(1<<UDRE)))
	{
	}
	
	UDR=data;
}
uint8 UART_recievebyte()
{
	while (!(UCSRA&(1<<RXC)))
	{
	}
	return UDR;
}
