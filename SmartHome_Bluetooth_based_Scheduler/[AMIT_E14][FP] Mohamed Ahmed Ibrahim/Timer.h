/*
 * Timer.h
 *
 * Created: 2/15/2019 7:00:50 PM
 *  Author: Mohamed Ahmed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

extern void Timer_Init(void);
extern volatile uint8 Timer_Flag;
extern volatile uint32 Timer_Counter;

#endif /* TIMER_H_ */