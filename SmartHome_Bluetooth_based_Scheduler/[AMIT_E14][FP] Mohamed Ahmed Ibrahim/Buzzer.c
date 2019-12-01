/*
 * Buzzer.c
 *
 * Created: 2/9/2019 6:07:25 PM
 *  Author: Mohamed Ahmed
 */ 

#include "Types.h"
#include "Dio.h"
#include "Buzzer.h"

void Buzzer_Handler(uint8 level)
{
	if (level==HIGH)
	{
		Dio_WritePin(PD,4,HIGH);
	}
	else
	{
		Dio_WritePin(PD,4,LOW);
	}
}

void Buzzer_Toggle(void)
{
	static uint8 F_State=0;
	if (1==F_State)
	{
		Dio_WritePin(PD,4,HIGH);
		F_State=0;
	}
	else
	{
		Dio_WritePin(PD,4,LOW);
		F_State=1;
	}
}



