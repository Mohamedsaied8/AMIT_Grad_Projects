/*
 * TEMP_SENSOR.c
 *
 * Created: 3/24/2019 10:13:18 PM
 *  Author: Mohamed Ahmed
 */ 

#include "Types.h"
#include "ADC.h"

sint8 temp;

void Temp_Sensor(void)
{
	temp = ((ADC_Conversion(ADC1)/12.89*1000) - 40000)/1000;
}