/*
 * Led.c
 *
 * Created: 2/9/2019 9:55:10 AM
 *  Author: Mohamed Ahmed
 */ 
#include "Types.h"
#include "Dio.h"
#include "Led.h"

void Led_Handler(Led_Name_t Led , uint8 Level)
{
	switch(Led)
	{
		case LED0:
		Dio_WritePin(PD,7,Level);
		break;
		
		case LED1:
		Dio_WritePin(PD,6,Level);
		break;
		
		case LED2:
		Dio_WritePin(PD,5,Level);
		break;
		
		default:
		break;
	}
}


void Led1_Toggle(void)
{
	static uint8 F_State1=0;
	if (1==F_State1)
	{
		Dio_WritePin(PD,7,HIGH);
		F_State1=0;
	}
	else
	{
		Dio_WritePin(PD,7,LOW);
		F_State1=1;
	}
}

void Led2_Toggle(void)
{
	static uint8 F_State2=0;
	if (1==F_State2)
	{
		Dio_WritePin(PD,6,HIGH);
		F_State2=0;
	}
	else
	{
		Dio_WritePin(PD,6,LOW);
		F_State2=1;
	}
}



void Led3_Toggle(void)
{
	static uint8 F_State3=0;
	if (1==F_State3)
	{
		Dio_WritePin(PD,5,HIGH);
		F_State3=0;
	}
	else
	{
		Dio_WritePin(PD,5,LOW);
		F_State3=1;
	}
}


