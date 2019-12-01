/*
 * mainproject.h
 *
 * Created: 9/3/2019 1:06:59 PM
 *  Author: omar
 */ 


#ifndef MAINPROJECT_H_
#define MAINPROJECT_H_
#include "delay by counter.h"// library for the delay with out using _delay_ms() to increase the respones and prevent to unstuck them.
#include "keypad.h"// library for using the keypad.
#include "LCD.h"//library for using the LCD.
#include "UART.h"// library for using UART.
#include "std_types.h"//library for using some define standard
void inti_of_program();//the LCD going to ask for password for true password type 2333.
void true_password();//will enter this function when the password is true by receive 2 ON UDR/"n".
void false_password();//will enter this function when password is wrong by receive 3 on UDR/"n".
void reset_a_3times();//if user enter password 3 times wrong the system just stop and cant accept any thing from keypad by receive 4 on UDR/"n".
extern uint8 key,n;// variable "key" for receive the button that pressed in keypad  and variable "n" for receive the UDR from microcontroler 2.
#endif /* MAINPROJECT_H_ */