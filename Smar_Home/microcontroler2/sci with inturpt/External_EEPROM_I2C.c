/*
 * External_EEPROM_I2C.c
 *
 * Created: 3/12/2014 12:05:19 PM
 */
 

#include "External_EEPROM.h"
#include "sciinturpt.h"
char x=0;
int i=0,c=0;
ISR(USART_RXC_vect)
{
	
	x=UDR;
	if(x=='2')
	PORTC=49;
}
int main(void)
{DDRC=0xff;
	
	sci_initilized ();
	
	/*EEPROM_Init();
	EEPROM_WriteByte(0x0001, 2); // Write 0xFF in the external EEPROM
	_delay_ms(10);
	EEPROM_ReadByte(0x0001, &b[0]); // Read 0xFF from the external EEPROM
    _delay_ms(100);
	/ *EEPROM_WriteByte(0x0002, 3);
	_delay_ms(10);
	EEPROM_ReadByte(0x0002, &b[1]);
	EEPROM_WriteByte(0x0003, '4'); // Write 0xFF in the external EEPROM
	_delay_ms(10);
	EEPROM_ReadByte(0x0003, &b[2]); // Read 0xFF from the external EEPROM
	_delay_ms(100);
	EEPROM_WriteByte(0x0004, '5');
	_delay_ms(10);
	EEPROM_ReadByte(0x0005, &b[3]);* /*/
	
	
	while(1)
	{
		
		

		//PORTD = val; // out the read value from the external EEPROM
	}
	return 0;
}
