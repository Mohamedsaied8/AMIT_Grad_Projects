/*
 * LCD.h
 *
 * Created: 17/03/2019 03:54:40 ص
 *  Author: user
 */ 


#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#include <util/delay.h>
#include "std_types.h"
void LCD_sendCommand(unsigned char command);
void LCD_init();
void LCD_sendData(uint8 data);
void LCD_cls();
void LCD_string(uint8 * str);
void LCD_goToRowColumn(unsigned char row,unsigned char col);




#endif /* LCD_H_ */