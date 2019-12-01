

#include "Types.h"
#include "Dio.h"
#include <avr/io.h>

extern const Dio_pin_state_t Pin_state[LAST_PIN];

void  Dio_WritePin (Dio_port_t port_num, uint8 pin_num, uint8 Level)
{

    switch(port_num)
    {
        case PA:
			if ( HIGH == Level)
			{
				SET_BIT(PORTA,pin_num);
			}
			else 
			{
				CLEAR_BIT(PORTA,pin_num);
			}
        break;
        case PB:
			if ( HIGH == Level)
			{
				SET_BIT(PORTB,pin_num);
			}
			else 
			{
				CLEAR_BIT(PORTB,pin_num);
			}        
		break;
        case PC:
			if ( HIGH == Level)
			{
				SET_BIT(PORTC,pin_num);
			}
			else 
			{
				CLEAR_BIT(PORTC,pin_num);
			}
        break;
        case PD:
			if ( HIGH == Level)
			{
				SET_BIT(PORTD,pin_num);
			}
			else 
			{
				CLEAR_BIT(PORTD,pin_num);
			}
        break;

		default:
		
        break;
    }
} /* END OF Dio_WritePin () */


uint8 Dio_ReadPin  (Dio_port_t port_num, uint8 pin_num)
{

	uint8 pin_Level = LOW;
	
    switch(port_num)
    {
        case PA:
			pin_Level = READ_BIT(PINA,pin_num);
        break;
        case PB:
			pin_Level = READ_BIT(PINB,pin_num);
        break;
        case PC:
			pin_Level = READ_BIT(PINC,pin_num);
        break;
        case PD:
			pin_Level = READ_BIT(PIND,pin_num);
        break;
        
        default:
        break;
    }
    
    return pin_Level;
} /* END OF Dio_ReadPin () */


void Dio_Init (void)
{
    Dio_port_t port;
    uint8 pin,i;

    for(i=0;i<LAST_PIN;i++)
    {
        port = i / 8;
        pin  = i % 8;

        switch(port)
        {
            case PA:
				if (OUTPUT == Pin_state[i])
				{
					SET_BIT(DDRA,pin);
				}
				else 
				{
					CLEAR_BIT(DDRA,pin);
					if (INPULLUP == Pin_state[i])
					{
						SET_BIT(PORTA,pin);
					}
				}
            break;
            case PB:
				if (OUTPUT == Pin_state[i])
				{
					SET_BIT(DDRB,pin);
				}
				else 
				{
					CLEAR_BIT(DDRB,pin);
					if (INPULLUP == Pin_state[i])
					{
						SET_BIT(PORTB,pin);
					}
				}
            break;
            case PC:
				if (OUTPUT == Pin_state[i])
				{
					SET_BIT(DDRC,pin);
				}
				else 
				{
					CLEAR_BIT(DDRC,pin);
					if (INPULLUP == Pin_state[i])
					{
						SET_BIT(PORTC,pin);
					}
				}
            break;
            case PD:
				if (OUTPUT == Pin_state[i])
				{
					SET_BIT(DDRD,pin);
				}
				else 
				{
					CLEAR_BIT(DDRD,pin);
					if (INPULLUP == Pin_state[i])
					{
						SET_BIT(PORTD,pin);
					}
				}
            break;
            
			default:
            
            break;
        }
    }
} /* END OF Dio_Init () */
