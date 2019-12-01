
#ifndef DIO_H_
#define DIO_H_

#include "Dio_cfg.h"


extern void  Dio_WritePin (Dio_port_t port_num, uint8 pin_num, uint8 Level);
extern uint8 Dio_ReadPin  (Dio_port_t port_num, uint8 pin_num);
extern void  Dio_Init     (void);


#endif /* DIO_H_ */
