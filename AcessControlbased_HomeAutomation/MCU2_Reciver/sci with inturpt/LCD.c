/*
 * LCD.c
 *
 * Created: 17/03/2019 03:54:21 ص
 *  Author: Ali
 */ 
#include "LCD.h"

void LCD_sendCommand(unsigned char command)
{
PORTB &=~((1<<PB1)|(1<<PB2)) ;
_delay_ms(5);
PORTA&=0x0f ;
PORTA=command ;
PORTB |=(1<<PB3) ;
_delay_ms(20) ;
PORTB &=~(1<<PB3) ;
PORTA&=0x0f ;
PORTA=((command<<4) &0xF0) ;
PORTB |=(1<<PB3) ;
_delay_ms(20) ;
PORTB &=~(1<<PB3) ;
_delay_ms(20);
}
void LCD_init()
{
	DDRA |=0xf0 ; /*data port */
	DDRB |= 0x0f; /*Cntrl */
	//LCD_sendCommand(0x20);
	LCD_sendCommand(0x02); /* return cursor to home */
	LCD_sendCommand(0x28);       // 4-bit mode - 2 line - 5x8 font.
	LCD_sendCommand(0x0C);       // Display no cursor - no blink.
	LCD_sendCommand(0x06);       // Automatic Increment - No Display shift.
	LCD_sendCommand(0x80);       // Address DDRAM with 0 offset 80h., access address 0
}
void LCD_sendData(char data)
{
PORTB &=~((1<<PB2)) ;
PORTB |=(1<<PB1) ;  /*RS = 1 */
_delay_ms(5);
PORTA&=0x0f ;
PORTA=data ;
PORTB |=(1<<PB3) ;
_delay_ms(5) ;
PORTB &=~(1<<PB3) ;
PORTA&=0x0f ;
PORTA=((data<<4) & 0xF0) ;
PORTB |=(1<<PB3) ;
_delay_ms(5) ;
PORTB &=~(1<<PB3) ;
_delay_ms(20);
}
void LCD_string(char * str)
{
while((*str) != 0)
{
	LCD_sendData(*str);
str++;
}
}
void LCD_cls()
{
	LCD_sendCommand(0x01);
}
void LCD_goToRowColumn(unsigned char row,unsigned char col)
{
	unsigned char Address;
	
	/* first of all calculate the required address */
	switch(row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
		case 2:
				Address=col+0x10;
				break;
		case 3:
				Address=col+0x50;
				break;
	}	
	/*void lcd_gtrc(unsigned char row,unsigned  char col)		
	{LCD_sendCommand(0x80|col);
		LCD_sendCommand(0x80|col|0x40);
	}*/
			
	/* to write to a specific address in the LCD 
	 * we need to apply the corresponding command 0b10000000+Address */
	LCD_sendCommand(Address| 0x80); 
}