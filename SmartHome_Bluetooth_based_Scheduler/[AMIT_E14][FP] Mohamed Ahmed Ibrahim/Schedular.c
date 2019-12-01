/*
 * schedular.c
 *
 * Created: 2/16/2019 4:52:30 PM
 *  Author: Mohamed Ahmed
 */ 

#define TASK_NUM (sizeof(Os_Cfg))/(sizeof(Os_Cfg_t))

#include "Types.h"
#include "Dio.h"
#include "Timer.h"
#include "ADC.h"
#include "TEMP_SENSOR.h"
#include "Smoke_Sensor.h"
#include "Led.h"
#include "Button.h"
#include "Amit_LCD.h"
#include "Electric_Valve.h"
#include "bluetooth.h"
#include "Schedular.h"


uint8 Button_Flag = 0, Alarm_Flag = 0;

void LCD_Display(void)
{
	if (Alarm_Flag == 1 || Button_Flag == 1)
	{
		Lcd_Clear();
		Lcd_Write_String("FIRE ALARM !!");
	}
	else
	{
		sint8 Temp_LCD = temp;
		
		Lcd_Clear();
		Lcd_Write_String("temp:");
		
		if (Temp_LCD < 0)
		{
			Lcd_Write_Char('-');
			Temp_LCD *= -1;
		}
		
		NUM_to_ASCII(Temp_LCD);
		Lcd_Write_String(ASCII);
		
		Lcd_Set_Cursor(2, 0);
		
		NUM_to_ASCII(smoke);
		Lcd_Write_String("smoke:");
		Lcd_Write_String(ASCII);
	}
}

void Fire_Condition(void)
{
	if ((temp >= 35) || (smoke >= 512))
	{
		Alarm_Flag = 1;
	}
	else
	{
		Alarm_Flag = 0;
	}
	
	if (Button_Read_actual(BUTTON0) == 1)
	{
		Button_Flag = 1;
	}
	else if (Button_Read_actual(BUTTON1) == 1)
	{
		Button_Flag = 0;
	}
}

void Alarm_Init(void)
{
	if (Alarm_Flag == 1 || Button_Flag == 1)
	{
		Elec_Valve(HIGH);
		Led1_Toggle();
		Led2_Toggle();
		Led3_Toggle();
		Buzzer_Toggle();
		bluetooth('w');
	}
	else
	{
		Elec_Valve(LOW);
		Led_Handler(LED0, LOW);
		Led_Handler(LED1, LOW);
		Led_Handler(LED2, LOW);
		Buzzer_Handler(LOW);
	}
}

const Os_Cfg_t Os_Cfg []=
{
	{20, Button0_Task},
	{20, Button1_Task},
	{100, Smoke_Sensor},
	{100,Temp_Sensor},
	{200, LCD_Display},
	{200, Fire_Condition},
	{200, Alarm_Init}
	
};

void Start_Os(void)
{
	uint8 i=0;
	uint32 tmp = 0;
	while(1)
	{
		if (1==Timer_Flag)
		{
			tmp = Timer_Counter;
			for (i=0;i<TASK_NUM;i++)
			{
				if (0== (tmp % Os_Cfg[i].Periodity))
				{
					Os_Cfg[i].ptr_f();
				}
				Timer_Flag=0;
			}
		}
	}
}
