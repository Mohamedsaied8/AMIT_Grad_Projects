/*
 * LCD.c
 *
 * Created: 17/03/2019 03:54:21 ص
 *  Author: user
 */
#include "LCD.h"
#include "std_types.h"


void LCD_sendCommand(unsigned char command)
{
	/*
	RS=0;RW=0;
	Data_PORT = cmd;
	EN=1;
	delay_ms(5);
	EN=0;
	Data_PORT =((cmd<<4) & 0xF0);
	EN=1;
	delay_ms(5);
	EN=0;*/
	PORTC &= ~((1 << PC1) | (1 << PC2));
	_delay_ms(5);
	PORTD = command;
	PORTC |= (1 << PC3);
	_delay_ms(20);
	PORTC &= ~(1 << PC3);
	PORTD &= 0x0f;
	PORTD = ((command << 4) & 0xF0);
	PORTC |= (1 << PC3);
	_delay_ms(20);
	PORTC &= ~(1 << PC3);
	_delay_ms(20);
}
void LCD_init()
{
	DDRD |= 0xf0; /*data port */
	DDRC |= 0x0f; /*Cntrl */
	//LCD_sendCommand(0x20);
	LCD_sendCommand(0x02); /* return cursor to home */

	LCD_sendCommand(0x28);       // 4-bit mode - 2 line - 5x8 font.
	LCD_sendCommand(0x0C);       // Display no cursor - no blink.
	LCD_sendCommand(0x06);       // Automatic Increment - No Display shift.
	LCD_sendCommand(0x80);       // Address DDRAM with 0 offset 80h., access address 0
}
void LCD_sendData(uint8 data)
{
	PORTC &= ~((1 << PC2));
	PORTC |= (1 << PC1);  /*RS = 1 */
	_delay_ms(5);
	PORTD &= 0x0f;
	PORTD = data;
	PORTC |= (1 << PC3);
	_delay_ms(5);
	PORTC &= ~(1 << PC3);
	PORTD &= 0x0f;
	PORTD = ((data << 4) & 0xF0);
	PORTC |= (1 << PC3);
	_delay_ms(5);
	PORTC &= ~(1 << PC3);
	_delay_ms(20);
}
void LCD_string(uint8* str)
{
	while ((*str) != 0)
	{
		LCD_sendData(*str);
		str++;
	}
}
void LCD_cls()
{
	LCD_sendCommand(0x01);
}
void LCD_goToRowColumn(unsigned char row, unsigned char col)
{
	unsigned char Address;

	/* first of all calculate the required address */
	switch (row)
	{
	case 0:
		Address = col;
		break;
	case 1:
		Address = col + 0x40;
		break;
	case 2:
		Address = col + 0x10;
		break;
	case 3:
		Address = col + 0x50;
		break;
	}
	/*void lcd_gtrc(unsigned char row,unsigned  char col)
	{LCD_sendCommand(0x80|col);
		LCD_sendCommand(0x80|col|0x40);
	}*/

	/* to write to a specific address in the LCD
	 * we need to apply the corresponding command 0b10000000+Address */
	LCD_sendCommand(Address | 0x80);
}