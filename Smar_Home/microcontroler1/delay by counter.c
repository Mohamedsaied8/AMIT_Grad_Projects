/*
 * delay_by_counter.c
 *
 * Created: 8/31/2019 1:44:12 PM
 *  Author: omar
 */ 
#include "delay by counter.h"
void  delaycounter (void) //this function used to slow the response of keypad to prevent fill LCD and UART on Proteus
 {int counter=0;
	   while (counter<=10000)
	   {      
		   counter++;   
	   }
 }