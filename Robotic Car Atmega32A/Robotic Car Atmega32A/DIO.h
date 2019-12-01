/*
 * DIO.h
 *
 * Created: 4/29/2019 12:42:50 AM
 *  Author: mahmo
 */ 


#ifndef DIO_H_
#define DIO_H_

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define PORTA0 0
#define PORTA1 1
#define PORTA2 2
#define PORTA3 3
#define PORTA4 4
#define PORTA5 5
#define PORTA6 6
#define PORTA7 7

#define PORTB0 8
#define PORTB1 9
#define PORTB2 10
#define PORTB3 11
#define PORTB4 12
#define PORTB5 13
#define PORTB6 14
#define PORTB7 15

#define PORTC0 16
#define PORTC1 17
#define PORTC2 18
#define PORTC3 19
#define PORTC4 20
#define PORTC5 21
#define PORTC6 22
#define PORTC7 23

#define PORTD0 24
#define PORTD1 25
#define PORTD2 26
#define PORTD3 27
#define PORTD4 28
#define PORTD5 29
#define PORTD6 30
#define PORTD7 31

#define INPUT 0
#define OUTPUT 1
#define HIGH 1
#define LOW 0

extern void DIO_SetPortDir(u8 PortNum, u8 PortDir);
extern void DIO_SetPinDir(u8 PinNum, u8 PinDir);
extern void DIO_WritePortValue(u8 PortNum, u8 PortValue);
extern void DIO_WritePinValue(u8 PinNum, u8 PinValue);
extern u8 DIO_ReadPortValue(u8 PortNum);
extern u8 DIO_ReadPinValue(u8 PinNum);

#endif /* DIO_H_ */