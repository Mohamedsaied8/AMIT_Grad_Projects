/*
 * ADC.c
 *
 * Created: 5/2/2019 10:02:42 PM
 *  Author: mahmo
 */ 

#define F_CPU (16000000UL)
#include "STD_types.h"
#include "Utills.h"
#include "dio.h"
#include "Rigisters.h"
#include "ADC.h"
#include "util/delay.h"


extern void ADC_Init(){
	
	
	DIO_SetPinDir(PORTA0,0);
	ADCMUX = 0b01000000;
	ADCSRA = 0b11110111;
	//SFOIR  = 0b00000000;
	
}

extern u16 ADC_Read(){
	set_bit(ADCSRA,6);
	while(get_bit(ADCSRA,4)==0){}
	set_bit(ADCSRA,4);
	return ADCF;

}