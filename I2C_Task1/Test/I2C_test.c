/*
 * I2C_test.c
 *
 * Created: 7/25/2021 12:56:51 AM
 *  Author: Mohamed
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "assert.h"
#include "stdio.h"


#define TWCR_TWINT               7
#define TWCR_TWEA                6
#define TWCR_TWSTA               5
#define TWCR_TWSTO               4
#define TWCR_TWWC                3
#define TWCR_TWEN                2
#define TWCR_TWIE                0


/* TWSR PINS */
#define TWSR_TWPS1               1
#define TWSR_TWPS0               0



#define I2C_STATUS_CODE_MASK   0xF8
/* Status Codes */
/* Master Transmit */

#define I2C_MT_SC_ACK          0x08
#define I2C_MT_RSC_ACK         0x10
#define I2C_MT_SLA_W_ACK       0x18
#define I2C_MT_DATA_ACK        0x28



/* Master Receive */

#define I2C_MR_SC_ACK          0x08
#define I2C_MR_RSC_ACK         0x10
#define I2C_MR_SLA_R_ACK       0x40
#define I2C_MR_DATA_ACK        0x80





typedef enum
{
	I2C_Ok,
	I2C_SC_Error,
	I2C_RSC_Error,
	I2C_SLA_W_Error,
	I2C_SLA_R_Error,
	I2C_DATA_Error,
	I2C_MR_DATA_Error,
	I2C_SR_Error,
	NO_E

}I2C_Error_States;


uint8_t TWDR;
uint8_t TWAR;
uint8_t TWSR;
uint8_t TWBR;
uint8_t TWCR;


uint8_t I2C_voidMasterInit(void)
{

	CLR_BIT(TWSR,TWSR_TWPS1);
	CLR_BIT(TWSR,TWSR_TWPS0);
	TWBR = 0x32;

	/* Enable ACK */
	SET_BIT(TWCR,TWCR_TWEA);

	/* Enable I2C */
	SET_BIT(TWCR,TWCR_TWEN);
	return NO_E;

}

uint8_t I2C_voidSlaveInit(uint8_t Copy_u8SlaveAdd)
{
	/* Enable I2C */
	SET_BIT(TWCR,TWCR_TWEN);

	/* Set Slave Address In TWAR */
	TWAR = Copy_u8SlaveAdd<<1;


	/* Enable ACK */
	SET_BIT(TWCR,TWCR_TWEA);


	return NO_E;


}

I2C_Error_States I2C_enuSendStartCondition(void)
{
	I2C_Error_States Local_enuState = I2C_Ok;

	/* Start Condition */
	SET_BIT(TWCR,TWCR_TWSTA);

	/* Clear Flag */
	SET_BIT(TWCR,TWCR_TWINT);


	/* Check Status code */
	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MT_SC_ACK)
	{
		Local_enuState = I2C_SC_Error;
	}
	else
	{

	}
	return NO_E;
}

I2C_Error_States I2C_enuMasterSendDataByte(uint8_t Copy_u8Data)
{
	I2C_Error_States Local_enuState = I2C_Ok;
	/* Write Data on The Data register */
	TWDR = Copy_u8Data;


	/* Clear Flag */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Check Status code */
	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MT_DATA_ACK)
	{
		Local_enuState = I2C_DATA_Error;
	}
	//else
	//{

	//}

	return NO_E;

}

uint8_t I2C_enuMasterReadDataByte(void)
{
	I2C_Error_States Local_enuState = I2C_Ok;
	uint8_t data;

	/* Clear flag */
	SET_BIT(TWCR,TWCR_TWINT);

	data = TWDR;



	return data;
}

void I2C_voidSendStopCondition(void)
{
	//Stop Condition
	SET_BIT(TWCR,TWCR_TWSTO);

	//Clear Flag
	SET_BIT(TWCR,TWCR_TWINT);


}


void SPI_MasterInitTest(void)
{
	assert(I2C_voidMasterInit() == NO_E);
	assert(TWCR == 68);
}

void I2C_SendDataTest(void)
{
	assert(I2C_enuMasterSendDataByte('a')==NO_E);
}


void I2C_ReadDataTest(void)
{
	assert(I2C_enuMasterReadDataByte()=='a');
}

void main()
{
	SPI_MasterInitTest();
	I2C_SendDataTest();
	I2C_ReadDataTest();
	printf("No Error");
}
