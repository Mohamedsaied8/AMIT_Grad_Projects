/*
 * RIGISTERS.h
 *
 * Created: 5/1/2019 3:06:38 PM
 *  Author: mahmo
 */ 


#ifndef RIGISTERS_H_
#define RIGISTERS_H_

//external interrupt registers
#define GICR (*(volatile u8*)0x5B)
#define GIFR (*(volatile u8*)0x5A)
#define MCUCR (*(volatile u8*)0x55)
#define MCUCSR (*(volatile u8*)0x54)
#define SREG (*(volatile u8*)0x5F)

//ADC registers
#define ADCMUX (*(volatile u8*)0x27)
#define ADCSRA (*(volatile u8*)0x26)
#define ADCH (*(volatile u8*)0x25)
#define ADCL (*(volatile u8*)0x24)
#define SFOIR (*(volatile u8*)0x50)

#define ADCF (*(volatile u16*)0x24)

//Timer registers
#define TCNT0 (*(volatile u16*)0x52)
#define TCCR0 (*(volatile u16*)0x53)
#define TIFR  (*(volatile u16*)0x58)
#define TIMSK (*(volatile u16*)0x59)
#define OCR0  (*(volatile u16*)0x5C)



#endif /* RIGISTERS_H_ */