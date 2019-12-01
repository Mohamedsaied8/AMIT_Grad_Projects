/*
 * ADC.c
 *
 * Created: 2/23/2019 12:36:52 PM
 *  Author: Mohamed Ahmed
 */ 
#include <avr/io.h>
#include "Types.h"
#include "ADC.h"

uint16 ADC_Value = 0;

void ADC_Init(void)
{
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	SET_BIT(ADMUX,6);
	SET_BIT(ADCSRA,7);
}

uint16 ADC_Conversion(ADC_Channel_t Channel)
{
	
	uint16 ADC_Value;
	
	ADMUX &= 0b11100000;
	
	switch (Channel)
	{
		
		case ADC0 :
		break;
		case ADC1 :	SET_BIT(ADMUX,0);
		break;
		case ADC2 :	SET_BIT(ADMUX,1);
		break;
		case ADC3 :	SET_BIT(ADMUX,1);SET_BIT(ADMUX,0);
		break;
		case ADC4 :	SET_BIT(ADMUX,2);
		break;
		case ADC5 :	SET_BIT(ADMUX,2);SET_BIT(ADMUX,0);
		break;
		case ADC6 :	SET_BIT(ADMUX,2);SET_BIT(ADMUX,1);
		break;
		case ADC7 :	SET_BIT(ADMUX,2);SET_BIT(ADMUX,1);SET_BIT(ADMUX,0);
		break;

		default:
		break;
	}
	
	
	SET_BIT(ADCSRA,6);
	
	while(1)
	{
		if (LOW==READ_BIT(ADCSRA,6))
		{
			ADC_Value=ADC;
			break;
		}
	}
	
	return ADC_Value;
}


