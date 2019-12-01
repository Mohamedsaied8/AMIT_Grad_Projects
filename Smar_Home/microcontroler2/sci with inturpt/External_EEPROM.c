/*! 

 * @file    I2C.
 * @brief   I2C source file driver 
 * @author  Ahmed Nasr Eldin 
 * @date    24/4/2015
 * @version 1.0
*/
#include "External_EEPROM.h"
 volatile uint8 b[9];

void EEPROM_Init(void)
{
	/*Initialize TWI to work at 400 kHZ 
	                 Disable Interrupt
					 Disable General Call
					 set The Micro controller address for 1
	*/ 
	TWI_Init(FastMode,0,0,1); 
}

uint8 EEPROM_WriteByte(uint16 u16addr, uint8 u8data)
{
    TWI_Start();
    if (TWI_GetStatus() != TW_START)
        return ERROR;
		
    //write the device address and so we need to get A8 A9 A10 address bits and R/W=0 (write)
    TWI_Write((uint8)(0xA0 | ((u16addr & 0x0700)>>7)));
    if (TWI_GetStatus() != TW_MT_SLA_W_ACK)
        return ERROR; 
		 
    //send the required location address
    TWI_Write((uint8)(u16addr));
    if (TWI_GetStatus() != TW_MT_DATA_ACK)
        return ERROR;
		
    //write byte to eeprom
    TWI_Write(u8data);
    if (TWI_GetStatus() != TW_MT_DATA_ACK)
        return ERROR;
		
    TWI_Stop();
	
    return SUCCESS;
}

uint8 EEPROM_ReadByte(uint16 u16addr, uint8 *u8data)
{
    TWI_Start();
    if (TWI_GetStatus() != TW_START)
        return ERROR;
		
    //write the device address and so we need to get A8 A9 A10 address bits and R/W=0 (write)
    TWI_Write((uint8)((0xA0) | ((u16addr & 0x0700)>>7)));
    if (TWI_GetStatus() != TW_MT_SLA_W_ACK)
        return ERROR;
		
    //send the required location address
    TWI_Write((uint8)(u16addr));
    if (TWI_GetStatus() != TW_MT_DATA_ACK)
        return ERROR;
		
    //send a repeated start
    TWI_Start();
    if (TWI_GetStatus() != TW_REP_START)
        return ERROR;
		
    //write the device address and so we need to get A8 A9 A10 address bits and R/W=1 (Read)
    TWI_Write((uint8)((0xA0) | ((u16addr & 0x0700)>>7) | 1));
    if (TWI_GetStatus() != TW_MT_SLA_R_ACK)
        return ERROR;
		
    *u8data = TWI_ReadWithNACK();
    if (TWI_GetStatus() != TW_MR_DATA_NACK)
        return ERROR;
		
    TWI_Stop();
    return SUCCESS;
}
 void eprom_passwordstored()
 {
	 EEPROM_WriteByte(0x0011, '2'); // Write 0xFF in the external EEPROM
	 _delay_ms(10);
	 EEPROM_ReadByte(0x0011, &b[4]); // Read 0xFF from the external EEPROM
	 _delay_ms(10);
	 EEPROM_WriteByte(0x0012, '3'); // Write 0xFF in the external EEPROM
	 _delay_ms(10);
	 EEPROM_ReadByte(0x0012, &b[5]); // Read 0xFF from the external EEPROM
	 _delay_ms(10);
	 EEPROM_WriteByte(0x0014, '3'); // Write 0xFF in the external EEPROM
	 _delay_ms(10);
	 EEPROM_ReadByte(0x0014, &b[6]); // Read 0xFF from the external EEPROM
	 _delay_ms(10);
	 EEPROM_WriteByte(0x0015, '3'); // Write 0xFF in the external EEPROM
	 _delay_ms(10);
	 EEPROM_ReadByte(0x0015, &b[7]); // Read 0xFF from the external EEPROM
	 _delay_ms(10);
 }
