/*! 

 * @file    I2C.C
 * @brief   I2C source file driver 
 * @author  Ahmed Nasr Eldin 
 * @date    24/4/2015
 * @version 1.0
*/
/******************************************************************************************************************************
	                                 included files
******************************************************************************************************************************/
#include "I2C.h"

void TWI_Init(uint8 SpeedMode,uint8 InterruptEn,uint8 GenrealCall,uint8 SlaveAddress)
{
	SET_BIT(TWCR,TWEN); /*Enable TWI */
    // Bit Rate: 400.000 kbps using zero pre-scaler TWPS=00 and F_CPU=8Mhz
	#if F_CPU==8000000UL
	switch (SpeedMode)
	{
		case NormalMode :
		    //TWBR = 0x08 ;
			TWBR = 32 ;
			TWSR = 0x00 ;
			break;		
		case FastMode :
		    TWBR = 0x02;
			TWSR = 0x00;
			break ;
	   
	}
	#else if F_CPU=12000000UL
	switch (SpeedMode)
	{
		case NormalMode :
		TWBR = 0x0D ;  /*make TWBR = 26 to get 100 Kb/s with 12 KHz TWSR=1 prescaler =1  */
		TWSR = 0x01 ;
		break;
		case FastMode :
		
		TWBR = 0x07;
		TWSR = 0x00;
		break ;
	}
	#endif
    // Two Wire Bus address my address if any master device want to call me: 0x1 (used in case this MC is a slave device)
    // General Call Recognition: Off
	
    TWAR = SlaveAddress; // my address = 0x01 :) 
	TWAR &=0x7F;        /*to make LSB always by Zero */ 
	/*if General call enabled */ 
	if(GenrealCall)
	{
		SET_BIT(TWAR,TWGCE);    /*set general call bit */
	}
/*if interrupt enable */
if(InterruptEn)
	{
		SET_BIT(TWCR,TWEA);
	}
}
	
void TWI_Start(void)
{
    /* 
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1 
	 */
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    
    // Wait for TWINT flag set in TWCR Register (start bit is send successfully) 
    while(BIT_IS_CLEAR(TWCR,TWINT));
}

void TWI_Stop(void)
{
    /* 
	 * Clear the TWINT flag before sending the stop bit TWINT=1
	 * send the stop bit by TWSTO=1
	 * Enable TWI Module TWEN=1 
	 */
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void TWI_Write(uint8 data)
{
    // Put data On TWI data Register
    TWDR = data;
    /* 
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */ 
    TWCR = (1 << TWINT) | (1 << TWEN);
    // Wait for TWINT flag set in TWCR Register(data is sent successfully) 
    while(BIT_IS_CLEAR(TWCR,TWINT));
}

uint8 TWI_ReadWithACK(void)
{
	/* 
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1 
	 */ 
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    // Wait for TWINT flag set in TWCR Register (data received successfully) 
    while(BIT_IS_CLEAR(TWCR,TWINT));
    // Read Data
    return TWDR;
}

uint8 TWI_ReadWithNACK(void)
{
	/* 
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */
    TWCR = (1 << TWINT) | (1 << TWEN);
    // Wait for TWINT flag set in TWCR Register (data received successfully) 
    while(BIT_IS_CLEAR(TWCR,TWINT));
    // Read Data
    return TWDR;
}

uint8 TWI_GetStatus(void)
{
    uint8 status;
    status = TWSR & 0xF8; //masking to eliminate first 3 bits 
    return status;
}
