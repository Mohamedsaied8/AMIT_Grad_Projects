/*
 * UART.h
 *
 * Created: 8/17/2019 11:51:32 AM
 *  Author: omar
 */ 


#ifndef UART_H_
#define UART_H_
#include <avr/io.h>
#include "std_types.h"
void UART_init();
void UART_sendbyte(uint8 data);
uint8 UART_recievebyte();
void UART_sendstring();
void UART_recievestring();

#endif /* UART_H_ */