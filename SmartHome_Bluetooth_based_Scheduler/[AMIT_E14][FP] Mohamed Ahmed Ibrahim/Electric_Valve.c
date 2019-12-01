/*
 * Electric_Valve.c
 *
 * Created: 3/22/2019 9:13:40 PM
 *  Author: Mohamed Ahmed
 */ 

#include "Types.h"
#include "Dio.h"
#include "relay.h"
#include "Electric_Valve.h"


void Elec_Valve(uint8 level)
{
	if (HIGH==level)
	{
		Relay_Handler(HIGH);
	} 
	else
	{
		Relay_Handler(LOW);
	}
	
}