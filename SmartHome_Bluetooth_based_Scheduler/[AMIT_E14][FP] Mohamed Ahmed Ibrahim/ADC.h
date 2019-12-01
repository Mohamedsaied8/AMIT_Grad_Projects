/*
 * ADC.h
 *
 * Created: 2/23/2019 12:37:22 PM
 *  Author: Mohamed Ahmed
 */ 


#ifndef ADC_H_
#define ADC_H_

typedef enum
{ADC0=0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
}ADC_Channel_t;


extern uint16 ADC_Value;

extern void ADC_Init(void);
extern uint16 ADC_Conversion(ADC_Channel_t Channel);




#endif /* ADC_H_ */

