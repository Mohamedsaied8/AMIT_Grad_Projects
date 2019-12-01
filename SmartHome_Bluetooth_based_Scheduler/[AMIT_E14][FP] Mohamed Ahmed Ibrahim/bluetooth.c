/*
 * bluetooth.c
 *
 * Created: 3/22/2019 8:24:50 PM
 *  Author: Mohamed Ahmed
 */ 

#include "Types.h"
#include "Dio.h"
#include "Dio_cfg.h"
#include "UART.h"


void bluetooth (uint8 text)
{
	UART_Init();
	UART_Send_data(text);
}

