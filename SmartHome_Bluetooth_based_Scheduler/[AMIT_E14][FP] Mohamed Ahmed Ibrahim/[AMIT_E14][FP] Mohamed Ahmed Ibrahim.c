/*
 * _AMIT_E14__FP__Mohamed_Ahmed_Ibrahim.c
 *
 * Created: 3/24/2019 10:37:38 PM
 *  Author: Mohamed Ahmed
 */ 


#include <avr/io.h>
#include "Types.h"
#include "Dio.h"
#include "Timer.h"
#include "Schedular.h"
#include "ADC.h"
#include "Amit_LCD.h"
#include "UART.h"

int main(void)
{
	Dio_Init();
	Timer_Init();
	ADC_Init();
	Lcd_Init();
	Lcd_Clear();
	UART_Init();
	Start_Os();
}