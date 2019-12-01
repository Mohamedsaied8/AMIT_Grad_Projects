/*
 * UART.h
 *
 * Created: 2/23/2019 8:17:27 PM
 *  Author: Mohamed Ahmed
 */ 


#ifndef UART_H_
#define UART_H_

extern void UART_Init(void);
extern void UART_Send_data(uint8 data);
extern uint8 UART_Recieve_data(void);



#endif /* UART_H_ */