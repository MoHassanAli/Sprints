/*
 * I2C_private.h
 *
 *  Created on: Jul 16, 2021
 *      Author: Mohamed
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_


typedef enum
{
	I2C_Ok,
	I2C_SC_Error,
	I2C_RSC_Error,
	I2C_SLA_W_Error,
	I2C_SLA_R_Error,
	I2C_DATA_Error,
	I2C_MR_DATA_Error,
	I2C_SR_Error

}I2C_Error_States;


void I2C_voidMasterInit(void);

void I2C_voidSlaveInit(uint8_t Copy_u8SlaveAdd);

I2C_Error_States I2C_enuSendStartCondition(void);

I2C_Error_States I2C_enuSendReStartCondition(void);

I2C_Error_States I2C_enuSendSlaveAddWithWrite(uint8_t Copy_u8SlaveAdd);

I2C_Error_States I2C_enuSendSlaveAddWithRead(uint8_t Copy_u8SlaveAdd);

I2C_Error_States I2C_enuMasterSendDataByte(uint8_t Copy_u8Data);

I2C_Error_States I2C_enuMasterReadDataByte(uint8_t * Copy_pu8Data);

I2C_Error_States I2C_U8SlaveReceive(uint8_t *Copy_u8Data);


void I2C_voidSendStopCondition(void);



#endif /* I2C_INTERFACE_H_ */
