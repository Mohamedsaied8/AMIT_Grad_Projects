/*
 * USART.h
 *
 * Created: 5/11/2019 9:47:51 AM
 *  Author: mahmo
 */ 


#ifndef USART_H_
#define USART_H_



extern void UART_Init(void);
extern unsigned char UART_RecieveData(void);
extern void UART_TransData(unsigned char data);




#endif /* USART_H_ */