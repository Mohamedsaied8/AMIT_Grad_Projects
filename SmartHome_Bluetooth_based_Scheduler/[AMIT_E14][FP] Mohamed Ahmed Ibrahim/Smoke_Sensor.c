/*
 * Smoke_Sensor.c
 *
 * Created: 3/24/2019 10:14:25 PM
 *  Author: Mohamed Ahmed
 */ 

#include "Types.h"
#include "ADC.h"

uint16 smoke;

void Smoke_Sensor(void)
{
	smoke = ADC_Conversion(ADC0);
}
