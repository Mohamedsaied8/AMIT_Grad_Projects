/*! 

 * @file    EEPROM.h
 * @brief   EEPROM Driver 
 * @author  Ahmed Nasr Eldin 
 * @date    24/4/2015
 * @version 1.0
*/


#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_

#define ERROR 0
#define SUCCESS 1

#include "I2C.h"
extern volatile uint8 b[9];
void EEPROM_Init(void);
unsigned char EEPROM_WriteByte(uint16 u16addr, uint8 u8data);
unsigned char EEPROM_ReadByte(uint16 u16addr, uint8 *u8data);
void eprom_passwordstored();
 
#endif /* EXTERNAL_EEPROM_H_ */