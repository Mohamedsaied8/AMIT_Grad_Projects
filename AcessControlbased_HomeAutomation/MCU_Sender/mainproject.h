/*
 * mainproject.h
 *
 * Created: 25/9/2019 1:06:59 PM
 *  Author: Ali
 */ 


#ifndef MAINPROJECT_H_
#define MAINPROJECT_H_
#include "delay by counter.h"
#include "keypad.h"
#include "LCD.h"
#include "UART.h"
#include "std_types.h"
void inti_of_program();
void true_password();
void false_password();
void reset_a_3times();
extern uint8 key,Ack;
#endif /* MAINPROJECT_H_ */