/*
 * sci with inturpt.c
 *
 * Created: 8/20/ 
 this will be the sender
 */ 
#include "External_EEPROM.h"
#include "uartinturpt.h"
#include "tofwi.h"
char x[4];
int i=0,c=0,n=0;
ISR(TIMER0_OVF_vect)
{ 
	timer_dcmotor_start();
}
ISR(USART_RXC_vect)
{
	EEPROM_WriteByte(i, UDR);
	_delay_ms(10);
	EEPROM_ReadByte(i, &b[i]); // Read 0xFF from the external EEPROM
	_delay_ms(10);
	EEPROM_WriteByte(0x0008, i); // Write 0xFF in the external EEPROM
	_delay_ms(10);
	EEPROM_ReadByte(0x0008, &b[8]); // Read 0xFF from the external EEPROM
	_delay_ms(10);
	if (i<3)
	UART_sendbyte('1');
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
	eprom_passwordstored();
	UART_sendbyte('1');
   while (1)
   {
	   start_checkpassword();
	   
   }
   

}

