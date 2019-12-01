/*
 * LCD.h
 *
 * Created: 17/03/2019 03:54:40 ص
 *  Author: ALi
 */ 


#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#include <util/delay.h>

void LCD_sendCommand(unsigned char command);
void LCD_init();
void LCD_sendData(char data);
void LCD_cls();
void LCD_string(char * str);
void LCD_goToRowColumn(unsigned char row,unsigned char col);




#endif /* LCD_H_ */