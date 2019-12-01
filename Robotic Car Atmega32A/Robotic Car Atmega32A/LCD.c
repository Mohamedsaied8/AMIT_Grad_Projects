/*
 * LCD.c
 *
 * Created: 4/29/2019 1:14:49 AM
 *  Author: mahmo
 */ 

#define F_CPU (16000000UL)
#include "STD_types.h"
#include "Utills.h"
#include "DIO.h"
#include "LCD_cfg.h"
#include "LCD.h"
#include "util\delay.h"

extern void LCD_Init(void)
{
	_delay_ms(20);
	DIO_SetPortDir(LCD_dataPORT , 0xF0); //Setting Data Pins as output
	
	DIO_SetPinDir(LCD_RegisterSelect , HIGH);
	DIO_SetPinDir(LCD_ReadWrite , HIGH);
	DIO_SetPinDir(LCD_Enable , HIGH);
	
	LCD_WriteCmd(0x33);
	_delay_ms(100);
	LCD_WriteCmd(0x32);
	_delay_ms(100);
	LCD_WriteCmd(0x28);
	_delay_ms(2);
	
	LCD_WriteCmd(LCD_DisplayOn);
	_delay_ms(100);
	LCD_WriteCmd(LCD_Clear);
	_delay_ms(2);
}

extern void LCD_WriteCmd(unsigned char cmd)
{
	DIO_WritePinValue(LCD_D7,get_bit(cmd , 7));
	DIO_WritePinValue(LCD_D6,get_bit(cmd , 6));
	DIO_WritePinValue(LCD_D5,get_bit(cmd , 5));
	DIO_WritePinValue(LCD_D4,get_bit(cmd , 4));
	
	DIO_WritePinValue(LCD_RegisterSelect,LOW); //COMMAND
	DIO_WritePinValue(LCD_ReadWrite,LOW); //WRITE
	
	DIO_WritePinValue(LCD_Enable,HIGH);
	_delay_ms(2);
	DIO_WritePinValue(LCD_Enable,LOW);
	_delay_ms(2);
	
	
	DIO_WritePinValue(LCD_D7,get_bit(cmd , 3));
	DIO_WritePinValue(LCD_D6,get_bit(cmd , 2));
	DIO_WritePinValue(LCD_D5,get_bit(cmd , 1));
	DIO_WritePinValue(LCD_D4,get_bit(cmd , 0));
	
	DIO_WritePinValue(LCD_Enable,HIGH);
	_delay_ms(2);
	DIO_WritePinValue(LCD_Enable,LOW);
	_delay_ms(2);
	
	
	
}
extern void LCD_WriteData(unsigned char data)
{
	DIO_WritePinValue(LCD_D7,get_bit(data , 7));
	DIO_WritePinValue(LCD_D6,get_bit(data , 6));
	DIO_WritePinValue(LCD_D5,get_bit(data , 5));
	DIO_WritePinValue(LCD_D4,get_bit(data , 4));
	
	DIO_WritePinValue(LCD_RegisterSelect,HIGH); //DATA
	DIO_WritePinValue(LCD_ReadWrite,LOW); //WRITE
	
	DIO_WritePinValue(LCD_Enable,HIGH);
	_delay_ms(2);
	DIO_WritePinValue(LCD_Enable,LOW);
	_delay_ms(2);
	
	
	DIO_WritePinValue(LCD_D7,get_bit(data , 3));
	DIO_WritePinValue(LCD_D6,get_bit(data , 2));
	DIO_WritePinValue(LCD_D5,get_bit(data , 1));
	DIO_WritePinValue(LCD_D4,get_bit(data , 0));
	
	DIO_WritePinValue(LCD_Enable,HIGH);
	_delay_ms(2);
	DIO_WritePinValue(LCD_Enable,LOW);
	_delay_ms(2);
}

extern void LCD_WriteString(unsigned char* string){
	u8 stringCount=0;
	while(string[stringCount]!='\0'){
		LCD_WriteData(string[stringCount]);
		stringCount++;
	}
}

extern void LCD_SetPosition(unsigned char row , unsigned char col){
	if(row==1){
		LCD_WriteCmd(128+col);
	}
	if(row==2){
		LCD_WriteCmd(128+64+col);
	}
}

extern void LCD_WriteDecimalNum(long unsigned int num){ //123
	long unsigned int number2=1;
	long unsigned int remainder=0;
	if(num == 0){
		LCD_WriteData('0');
	}
	while(0 !=num){
		remainder=num%10; //3 -- 2 -- 1
		number2 =  (number2*10 )+ remainder; //13 -- 132 -- 1321
		num = num/10; //12 - 1 - 0
	}
	while(1 != number2){
		remainder=number2 %10;
		LCD_WriteData(remainder + '0');
		number2 /= 10;
	}
}