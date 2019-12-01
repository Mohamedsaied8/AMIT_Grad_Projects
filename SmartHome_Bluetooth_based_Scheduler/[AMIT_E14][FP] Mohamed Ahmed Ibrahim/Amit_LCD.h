#ifndef AMIT_LCD_H_
#define AMIT_LCD_H_

extern void Lcd_Data(uint8 data);
extern void Lcd_command(uint8 a);
extern void Lcd_Clear(void);
extern void Lcd_Set_Cursor(uint8 a, uint8 b);
extern void Lcd_Init(void);
extern void Lcd_Write_Char(uint8 a);
extern void Lcd_Write_String(uint8 *a);
extern void Lcd_Shift_Right(void);
extern void Lcd_Shift_Left(void);

extern void NUM_to_ASCII(uint16 NUM);
extern uint8 ASCII[5];

#endif
