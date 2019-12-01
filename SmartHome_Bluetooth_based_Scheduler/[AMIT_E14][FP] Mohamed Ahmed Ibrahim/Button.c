/*
 * CFile1.c
 *
 * Created: 2/8/2019 7:46:37 PM
 *  Author: Mohamed Ahmed
 */ 


#include "Types.h"
#include "Dio.h"
#include "Button.h"

static uint8 Actual_Button0;
static uint8 Actual_Button1;
static uint8 Actual_Button2;

uint8 Button_Read(Button_Name_t Button_Num)
{
	uint8 Button_Level=0;
	switch(Button_Num)
	{
		case  BUTTON0:
		Button_Level=Dio_ReadPin(PD,0);
		break;
		
		case BUTTON1:
		
		Button_Level=Dio_ReadPin(PD,1);
		break;
		
		case BUTTON2:
		
		Button_Level=Dio_ReadPin(PD,2);
		break;
		
		default:
		break;
	}
	return Button_Level;
}

void Button0_Task(void)
{
	static uint8 Count0 = 0;
	static uint8 Old_Button0 = 0;
	uint8 New_Button0 = 0;
	
	New_Button0 = Dio_ReadPin(PD,0);
	
	if (Old_Button0 == New_Button0)
	{
		Count0++;
	}
	else
	{
		Count0 = 0;
	}
	
	if (Count0 > 2)
	{
		Actual_Button0 = New_Button0;
	}
	
	Old_Button0 = New_Button0;
}


void Button1_Task(void)
{
	
	static uint8 Count1 = 0;
	static uint8 Old_Button1 = 0;
	uint8 New_Button1 = 0;
	
	New_Button1 = Dio_ReadPin(PD,1);
	
	if (Old_Button1 == New_Button1)
	{
		Count1++;
	}
	else
	{
		Count1 = 0;
	}
	
	if (Count1>2)
	{
		Actual_Button1 = New_Button1;
	}
	Old_Button1 = New_Button1;
}


void Button2_Task(void)
{
	static uint8 Count2 = 0;
	static uint8 Old_Button2 = 0;
	uint8 New_Button2 = 0;
	
	New_Button2 = Dio_ReadPin(PD,2);
	
	if (Old_Button2 == New_Button2)
	{
		Count2++;
	}
	else
	{
		Count2 = 0;
	}
	
	if (Count2>2)
	{
		Actual_Button2 = New_Button2;
	}
	Old_Button2 = New_Button2;
}


uint8 Button_Read_actual(Button_Name_t Button_Name)
{
	uint8 Button_Level=0;
	
	switch(Button_Name)
	{
		case BUTTON0 :
		
		Button_Level = Actual_Button0;
		break;
		
		case BUTTON1 :
		
		Button_Level = Actual_Button1;
		break;
		
		case BUTTON2 :
		
		Button_Level = Actual_Button2;
		break;
		
		default:	break;
	}
	
	return Button_Level;
}

