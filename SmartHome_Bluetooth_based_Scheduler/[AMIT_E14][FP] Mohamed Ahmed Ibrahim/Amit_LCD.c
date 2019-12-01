#define F_CPU 12000000UL
#include "Types.h"
#include "Dio.h"
#include "Amit_LCD.h"
#include <util/delay.h>


uint8 ASCII[5];

void Lcd_Data(uint8 data)
{
	if(data & 1)
	Dio_WritePin(PA,4,1);
	else
	Dio_WritePin(PA,4,0);
	
	if(data & 2)
	Dio_WritePin(PA,5,1);
	else
	Dio_WritePin(PA,5,0);
	
	if(data & 4)
	Dio_WritePin(PA,6,1);
	else
	Dio_WritePin(PA,6,0);
	
	if(data & 8)
	Dio_WritePin(PA,7,1);
	else
	Dio_WritePin(PA,7,0);
}
void Lcd_command(uint8 a)
{
	Dio_WritePin(PB,1,0);             // => PB,1 = 0
	Lcd_Data(a);
	Dio_WritePin(PB,3,1);            // => E = 1
	_delay_ms(1);
	Dio_WritePin(PB,3,0);             // => E = 0
	_delay_ms(1);
}

void Lcd_Clear(void)
{
	Lcd_command(0);
	Lcd_command(1);
}

void Lcd_Set_Cursor(uint8 a, uint8 b)
{
	uint8 temp,z,y;
	if(a == 1)
	{
		temp = 0x80 + b;
		z = temp>>4;
		y = (0x80+b) & 0x0F;
		Lcd_command(z);
		Lcd_command(y);
	}
	else if(a == 2)
	{
		temp = 0xC0 + b;
		z = temp>>4;
		y = (0xC0+b) & 0x0F;
		Lcd_command(z);
		Lcd_command(y);
	}
}

void Lcd_Init(void)
{
	Lcd_Data(0x00);
	_delay_ms(20);
	///////////// Reset process from datasheet /////////
	Lcd_command(0x03);
	_delay_ms(5);
	Lcd_command(0x03);
	_delay_ms(11);
	Lcd_command(0x03);
	/////////////////////////////////////////////////////
	Lcd_command(0x02);
	Lcd_command(0x02);
	Lcd_command(0x08);
	Lcd_command(0x00);
	Lcd_command(0x0C);
	Lcd_command(0x00);
	Lcd_command(0x06);
}

void Lcd_Write_Char(uint8 a)
{
	uint8 temp,y;
	temp = a&0x0F;
	y = a&0xF0;
	Dio_WritePin(PB,1,1);             // => PB,1 = 1
	Lcd_Data(y>>4);             //Data transfer
	Dio_WritePin(PB,3,1);
	_delay_ms(1);
	Dio_WritePin(PB,3,0);
	_delay_ms(1);
	Lcd_Data(temp);
	Dio_WritePin(PB,3,1);
	_delay_ms(1);
	Dio_WritePin(PB,3,0);
	_delay_ms(1);
}

void Lcd_Write_String(uint8 *a)
{
	uint8 i;
	for(i=0;a[i]!='\0';i++)
	Lcd_Write_Char(a[i]);
}

void Lcd_Shift_Right(void)
{
	Lcd_command(0x01);
	Lcd_command(0x0C);
}

void Lcd_Shift_Left(void)
{
	Lcd_command(0x01);
	Lcd_command(0x08);
}
//End LCD 4 Bit Interfacing Functions

void NUM_to_ASCII(uint16 NUM)
{

	uint8 asccc[4]={0};
	uint8 No_Digit;

	asccc[0]	= NUM/1000;
	asccc[0]	+=  48;      // :ASCII of 0 = 48
	uint16 val1	= NUM%1000;
	
	asccc[1]	= val1/100;
	asccc[1]	+=  48;
	val1		= val1%100;
	
	asccc[2]	= val1/10;
	asccc[2]	+=  48;
	val1		= val1%10;
	
	asccc[3]	= val1/1;
	asccc[3]	+=  48;
	val1		= val1%1;
	
	for (No_Digit=0;No_Digit<=3;No_Digit++)
	{
		ASCII[No_Digit] = asccc[No_Digit];
	}
	
	ASCII[4] = '\0';
	
}
