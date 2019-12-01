/*
 * IncFile1.h
 *
 * Created: 8/20/2019 11:54:18 AM
 *  Author: omar
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include <avr/io.h>
#include <avr/interrupt.h>
#include "LCD.h"
#include "External_EEPROM.h"
 void sci_initilized ();
 void start_checkpassword();
 void UART_sendbyte(char data);
 extern int f1 ,tc;
#endif /* INCFILE1_H_ */