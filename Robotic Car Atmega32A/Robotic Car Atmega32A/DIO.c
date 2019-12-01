/*
 * DIO.c
 *
 * Created: 4/29/2019 12:43:04 AM
 *  Author: mahmo
 */ 

#include "STD_types.h"
#include "Utills.h"
#include "DIO.h"

//Direction
#define DIO_DDRA (*(volatile u8*)0x3A)
#define DIO_DDRB (*(volatile u8*)0x37)
#define DIO_DDRC (*(volatile u8*)0x34)
#define DIO_DDRD (*(volatile u8*)0x31)

//Write
#define DIO_PORTA (*(volatile u8*)0x3B)
#define DIO_PORTB (*(volatile u8*)0x38)
#define DIO_PORTC (*(volatile u8*)0x35)
#define DIO_PORTD (*(volatile u8*)0x32)

//Read
#define DIO_PINA (*(volatile u8*)0x39)
#define DIO_PINB (*(volatile u8*)0x36)
#define DIO_PINC (*(volatile u8*)0x33)
#define DIO_PIND (*(volatile u8*)0x30)

extern void DIO_SetPinDir(u8 PinNum, u8 PinDir){
	if(PORTA0<= PinNum && PinNum<=PORTA7){
		assign_bit(DIO_DDRA, PinNum%8 ,PinDir);
	}
	if(PORTB0<= PinNum && PinNum<=PORTB7){
		assign_bit(DIO_DDRB, PinNum%8 ,PinDir);
	}
	if(PORTC0<= PinNum && PinNum<=PORTC7){
		assign_bit(DIO_DDRC, PinNum%8 ,PinDir);
	}
	if(PORTD0<= PinNum && PinNum<=PORTD7){
		assign_bit(DIO_DDRD, PinNum%8 ,PinDir);
	}
}


extern void DIO_SetPortDir(u8 PortNum, u8 PortDir){
	switch(PortNum){
		case 0 :
		DIO_DDRA= PortDir;
		break;
		case 1 :
		DIO_DDRB= PortDir;
		break;
		case 2 :
		DIO_DDRC= PortDir;
		break;
		case 3 :
		DIO_DDRD= PortDir;
		break;
		default:
		break;
	}
}

extern void DIO_WritePortValue(u8 PortNum, u8 PortValue){
	switch(PortNum){
		case 0 :
		DIO_PORTA= PortValue;
		break;
		case 1 :
		DIO_PORTB= PortValue;
		break;
		case 2 :
		DIO_PORTC= PortValue;
		break;
		case 3 :
		DIO_PORTD= PortValue;
		break;
		default:
		break;
	}
}

extern void DIO_WritePinValue(u8 PinNum, u8 PinValue){
	if(PORTA0<= PinNum && PinNum<=PORTA7){
		assign_bit(DIO_PORTA, PinNum%8 ,PinValue);
	}
	if(PORTB0<= PinNum && PinNum<=PORTB7){
		assign_bit(DIO_PORTB, PinNum%8 ,PinValue);
	}
	if(PORTC0<= PinNum && PinNum<=PORTC7){
		assign_bit(DIO_PORTC, PinNum%8 ,PinValue);
	}
	if(PORTD0<= PinNum && PinNum<=PORTD7){
		assign_bit(DIO_PORTD, PinNum%8 ,PinValue);
	}
}

extern u8 DIO_ReadPortValue(u8 PortNum){
	u8 ReturnPortValue;
	switch(PortNum){
		case 0 :
		ReturnPortValue= DIO_PINA;
		break;
		case 1 :
		ReturnPortValue= DIO_PINB;
		break;
		case 2 :
		ReturnPortValue= DIO_PINC;
		break;
		case 3 :
		ReturnPortValue= DIO_PIND;
		break;
		default:
		break;
		return ReturnPortValue;
	}
}

extern u8 DIO_ReadPinValue(u8 PinNum){
	u8 ReturnPinValue ;
	if(PORTA0<= PinNum && PinNum<=PORTA7){
		ReturnPinValue= get_bit(DIO_PORTA, PinNum%8);
	}
	if(PORTB0<= PinNum && PinNum<=PORTB7){
		ReturnPinValue= get_bit(DIO_PORTB, PinNum%8);
	}
	if(PORTC0<= PinNum && PinNum<=PORTC7){
		ReturnPinValue= get_bit(DIO_PORTC, PinNum%8);
	}
	if(PORTD0<= PinNum && PinNum<=PORTD7){
		ReturnPinValue= get_bit(DIO_PORTD, PinNum%8);
	}
	return ReturnPinValue;
}
