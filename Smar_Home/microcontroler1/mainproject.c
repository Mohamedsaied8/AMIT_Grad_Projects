/*
 * mainproject.c
 *
 * Created: 9/3/2019 1:15:49 PM
 *  Author: omar
 */ 
#include "mainproject.h"
uint8 key,n;
uint8 x=0;
//**************************************************************************************************************************************************
void inti_of_program()//the LCD going to ask for password for true password type 2333.
{
	if(n=='1')
	{
		if(x==0)
		{
			LCD_cls();//it's function we call to clear the LCD.
			LCD_sendCommand(0x80);//it's function we call to make courser reach first row and first coloum.
			LCD_string("password:");//it's function we call to write on the LCD "password:".
		}
		x++;//the counter x will be add by 1 ever time it pass by that line.
		key = KeyPad_getPressedKey();//get the pressed button from keypad .
		delaycounter();//this function used to slow the response of keypad to prevent fill LCD and UART on Proteus.
		UART_sendbyte(key);// send  to microcontroler 2 the key as UDR.
		if((key >= '0') && (key <= '9'))
		{
			LCD_sendData(key);//type on the LCD  the key we pushed if it in range (0-9).
			if(x==4)//if the x start to count  4 time it reset to o to  go to if (x=0) condition.
			{x=0;
			}
		}
	}
	
}
//**************************************************************************************************************************************************
void true_password()//will enter this function when the password is true by receive 2 ON UDR.
{
	 if (n=='2')
	 {
		 LCD_sendCommand(0x80);//it's function we call to make courser reach first row and first coloum.
		 LCD_string("true password");//it's function we call to write on the LCD "true password".
	 }
	
}
//**************************************************************************************************************************************************
void false_password()//will enter this function when password is wrong by receive 3 on UDR/"n".
{
	if (n=='3')
	{
		LCD_sendCommand(0x80);//it's function we call to make courser reach first row and first coloum.
		LCD_string("wrong password");//it's function we call to write on the LCD "wrong password".
		_delay_ms(1000);//that will delay for few time to  not allow any one type on keypad and buzzer have time to work to call for security
	}
}
//**************************************************************************************************************************************************
void reset_a_3times()//if user enter password 3 times wrong the system just stop and cant accept any thing from keypad by receive 4 on UDR/"n".
{
	  if (n=='4')
	  {
		  LCD_sendCommand(0x80);
		  LCD_string("wrong password ");
		  LCD_goToRowColumn(1,0);
		  LCD_string("3 times reset ");
	  }	
}

//**************************************************************************************************************************************************