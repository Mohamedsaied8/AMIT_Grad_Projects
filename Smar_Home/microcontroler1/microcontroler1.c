/*
 * Exercise6.c
 *
 * Created: 1/23/2014 9:50:20 PM
 *  Author: Mohamed Tarek
 */ 
#include "mainproject.h"
int main(void)
{
	LCD_init();// LCD initialization
	UART_init();// UART initialization
    while(1)
    { 
		n=UART_recievebyte();//the function going to receive first UART and give it to valuable "n" to know if he want to go inti, true, false and system closed.
	    inti_of_program();//the LCD going to ask for password for true password type 2333.
	    true_password();//will enter this function when the password is true by receive 2 ON UDR.
		false_password();//will enter this function when password is wrong by receive 3 on UDR.
		reset_a_3times();//if user enter password 3 times wrong the system just stop and cant accept any thing from keypad.
    }
}