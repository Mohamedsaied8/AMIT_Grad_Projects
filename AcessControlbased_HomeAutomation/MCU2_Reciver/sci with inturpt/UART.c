/*
 * sciinturpt1.c
 *
 * Created: 8/20/2019 11:54:46 AM
 *  Author: omar
 */ 
#include "UART.h"
int f1=1,Num_Count=0,tc=0,f,c_u=0,counter_if_wrong=0;
void sci_initilized()
{
	sei();
	UCSRA|=0x00;
	UCSRB|=(1<<RXCIE)|(1<<RXEN)|(1<<TXEN);
	UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UBRRH=0x00;
	UBRRL=103;
}
void UART_sendbyte( char data)
{
	while (!(UCSRA&(1<<UDRE)))
	{
	}
	
	UDR=data;
}
void start_checkpassword()
{
	 
	if (f1==1)
	{
		
		if(Password[8]==3)
		{
			for( f=0;f<4;f++)
			{
				if(Password[f]==Password[f+4])
				{
					Num_Count++;
					if(Num_Count==4)
					{
						f1=2;
						MotorInit();	
						Num_Count=0;
					}
					
				}
				else
				{
					f1=3;
				}
				
			}
		}
	}
	if (f1==2)
	{
		UART_sendbyte('C');
		_delay_ms(10000);
		UART_sendbyte('S');
		f1=1;
		Password[8]=2;
		counter_if_wrong=0;
	}
	if (f1==3)
	{
		PORTA|=(1<<PA4);
		UART_sendbyte('W');
		if(counter_if_wrong<2)
		{
			_delay_ms(10000);
		    UART_sendbyte('S');
		}
		f1=1;
		Password[8]=1;
		if(counter_if_wrong==2)
		{
			f1=4;
			counter_if_wrong=0;
		}
		counter_if_wrong++;
	}
	if (f1==4)
	{
		UART_sendbyte('Q');
	}
	
}

