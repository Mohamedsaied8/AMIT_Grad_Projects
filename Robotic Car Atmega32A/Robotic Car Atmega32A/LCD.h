/*
 * LCD.h
 *
 * Created: 4/29/2019 1:15:06 AM
 *  Author: mahmo
 */ 


#ifndef LCD_H_
#define LCD_H_

#define LCD_Clear (unsigned char)0x01
#define LCD_DisplayOn (unsigned char)0x0E

extern void LCD_Init(void);

extern void LCD_WriteData(unsigned char data);
extern void LCD_WriteCmd(unsigned char cmd);

extern void LCD_WriteString(unsigned char* string);
extern void LCD_SetPosition(unsigned char row , unsigned char col);

extern void LCD_WriteDecimalNum(long unsigned int num);

#endif /* LCD_H_ */