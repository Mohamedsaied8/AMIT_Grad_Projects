/*
 * Led.h
 *
 * Created: 2/9/2019 9:53:05 AM
 *  Author: Mohamed Ahmed
 */ 


#ifndef LED_H_
#define LED_H_

typedef enum
{
	LED0=0,
	LED1,
	LED2
}Led_Name_t;

extern void Led_Handler(Led_Name_t Led , uint8 Level);
extern void Led1_Toggle(void) ;
extern void Led2_Toggle(void);
extern void Led3_Toggle(void);

#endif /* LED_H_ */

