/*! 

 * @file    I2C.h
 * @brief   I2C driver 
 * @author  Ahmed Nasr Eldin 
 * @date    24/4/2015
 * @version 1.0
*/


#ifndef I2C_H_
#define I2C_H_
/******************************************************************************************************************************
	                                 included files
******************************************************************************************************************************/
#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"
/******************************************************************************************************************************
	                                   Definitions
******************************************************************************************************************************/
#define NormalMode 1          //Normal Mode 100 KB/s 
#define FastMode 2            //Fast Mode 400 KB/s 
#define HighSpeedMode 3       //High Speed Mode 3.4 MB/s Caution High Speed mode Not Supported for Atmega16 
#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start 
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave
/******************************************************************************************************************************
	                                   Functions Prototypes
******************************************************************************************************************************/
/** ---------------------------------------------------------------------------------------------------------------
@brief This function is responsible for Initializing I2C HW
*@param this function takes Speed Mode Type , InterruptEn to work with Interrupt or Polling ,
                            GeneralCall to Enable/Disable General call for I2C ,
							SlaveAddress : address of the Controller and will be used if controller become slave
[Returns] : This function returns void
--------------------------------------------------------------------------------------------------------------- **/
void TWI_Init(uint8 SpeedMode,uint8 InterruptEn,uint8 GenrealCall,uint8 SlaveAddress);
/** ---------------------------------------------------------------------------------------------------------------
@brief This function is responsible for sending start bit of I2C frame
*@param this function takes void
[Returns] : This function returns void
--------------------------------------------------------------------------------------------------------------- **/
void TWI_Start(void);
/** ---------------------------------------------------------------------------------------------------------------
@brief This function is responsible for sending start Stop of I2C frame
*@param this function takes void
[Returns] : This function returns void
--------------------------------------------------------------------------------------------------------------- **/
void TWI_Stop(void);
/** ---------------------------------------------------------------------------------------------------------------
@brief This function is responsible for sending data 
*@param this function takes data to be sent
[Returns] : This function returns void
--------------------------------------------------------------------------------------------------------------- **/
void TWI_Write(unsigned char data);
/** ---------------------------------------------------------------------------------------------------------------
@brief This function is responsible for reading and Send Acknowledge
*@param this function takes void
[Returns] : This function returns data read with I2C
--------------------------------------------------------------------------------------------------------------- **/
unsigned char TWI_ReadWithACK(void);
/** ---------------------------------------------------------------------------------------------------------------
@brief This function is responsible for reading data without Acknowledge
*@param this function takes void
[Returns] : This function returns data read with I2C
--------------------------------------------------------------------------------------------------------------- **/ 
unsigned char TWI_ReadWithNACK(void); 
/** ---------------------------------------------------------------------------------------------------------------
@brief This function is responsible for getting the status from status Register
*@param this function takes void
[Returns] : This function returns the status from last operation
--------------------------------------------------------------------------------------------------------------- **/
unsigned char TWI_GetStatus(void);


#endif /* I2C_H_ */