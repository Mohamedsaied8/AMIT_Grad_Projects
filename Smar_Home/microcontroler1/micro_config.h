/*
 * micro_config.h
 *
 * Created: 1/3/2015 11:28:01 PM
 *  Author: Mohamed Tarek
 */ 


#ifndef MICRO_CONFIG_H_
#define MICRO_CONFIG_H_


#ifndef F_CPU
#define F_CPU 1000000UL //1MHz Clock frequency
#endif  

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#endif /* MICRO_CONFIG_H_ */