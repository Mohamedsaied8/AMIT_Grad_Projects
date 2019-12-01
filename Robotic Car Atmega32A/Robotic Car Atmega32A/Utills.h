/*
 * IncFile1.h
 *
 * Created: 30-Mar-19 7:39:22 PM
 *  Author: Hamdy.Fouad
 */ 


#ifndef UTILS_H_
#define UTILS_H_


char temp;

#define set_bit(reg,bitno)	reg|=(1<<bitno)
#define clr_bit(reg,bitno)	reg&=( ~(1<<bitno) )
#define toggle_bit(reg,bitno)	reg^=(1<<(bitno))
//#define assign_bit(reg,bitnum,value) (value) ? set_bit(reg,bitnum): clr_bit(reg,bitnum)
#define assign_bit(reg,bitno,value)	do{ clr_bit(reg,bitno); reg|=((value)<<bitno); }while(0)

#define set_nibbleLow(reg)	reg=reg|0b00001111
#define clr_nibbleLow(reg)	reg=reg&0b11110000
#define toggle_nibbleLow(reg)	reg=reg^0b00001111
#define assign_nibbleLow(reg,value)	do{ clr_nibbleLow(reg); reg=reg|value; }while(0)

#define set_port_high(reg)   reg|=0b11111111
#define set_port_low(reg)    reg&=0b00000000
#define set_port_direction_output(reg)   reg|=0b11111111
#define set_port_direction_input(reg)   reg&=0b00000000
//#define set_port_value(reg,value)  ((value) ? set_port_high(reg); : set_port_low(reg););
//#define set_port_direction(reg,status)  ( (status) ? set_port_direction_output(reg); : set_port_direction_input(reg); )
#define  set_port_direction(reg,value)  if(value){set_port_direction_output(reg);}else{set_port_direction_input(reg);}
#define  set_port_value(reg,value)  if(value){set_port_high(reg);}else{set_port_low(reg);}

#define set_nibbleHigh(reg)	reg=reg|0b11110000
#define clr_nibbleHigh(reg)	reg=reg&0b00001111
#define toggle_nibbleHigh(reg)	reg=reg^0b11110000
#define assign_nibbleHigh(reg,value)	do{ clr_nibbleHigh(reg); reg=reg|value<<4; }while(0)

#define get_bit(reg,bitno)	( reg&(1<<bitno) )>>bitno
#define get_nibbleLow(reg)	reg&0b00001111
#define get_nibbleHigh(reg)	(reg&0b11110000)>>4

#define cir_shiftRight(reg,shiftno)	reg= (reg<<( sizeof(reg)*8 -shiftno)) | (reg>>shiftno)
#define cir_shiftLeft(reg,shiftno)	reg= (reg>>( sizeof(reg)*8 -shiftno)) | (reg<<shiftno)

#endif /* UTILS_H_ */