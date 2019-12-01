/*
 * sci with inturpt.c
 *
 * Created: 8/20/ 
 this will be the sender
 */ 
#include "External_EEPROM.h"
#include "UART.h"
#include "MOTOR.h"
char x[4];
int i=0,c=0,n=0;
ISR(TIMER0_OVF_vect)
{ 
	MotorStart();
}
ISR(USART_RXC_vect)
{
	EEPROM_WriteByte(i, UDR);
	_delay_ms(10);
	EEPROM_ReadByte(i, &Password[i]); // Read 0xFF from the external EEPROM
	_delay_ms(10);
	EEPROM_WriteByte(0x0008, i); // Write 0xFF in the external EEPROM
	_delay_ms(10);
	EEPROM_ReadByte(0x0008, &Password[8]); // Read 0xFF from the external EEPROM
	_delay_ms(10);
	if (i<3)
	UART_sendbyte('S');
	i++;
	if(i==4)
	{
		i=0;
	}

}

int main(void)
{DDRA=0xff;
	DDRC=0xff;
	
	sci_initilized ();
	EEPROM_Init();
	EEPROM_Saved_Password();
	UART_sendbyte('S');
   while (1)
   {
	   start_checkpassword();
	   
   }
   

}

