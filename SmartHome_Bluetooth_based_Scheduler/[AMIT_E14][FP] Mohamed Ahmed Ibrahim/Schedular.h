/*
 * schedular.h
 *
 * Created: 2/16/2019 4:53:28 PM
 *  Author: Mohamed Ahmed
 */ 


#ifndef SCHEDULAR_H_
#define SCHEDULAR_H_



typedef struct
{
	uint16 Periodity ;
	void (*ptr_f) (void) ;
}Os_Cfg_t;


extern void Start_Os(void);


#endif /* SCHEDULAR_H_ */
