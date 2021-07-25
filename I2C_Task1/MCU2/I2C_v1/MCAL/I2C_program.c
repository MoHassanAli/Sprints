


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "I2C_interface.h"
#include "I2C_private.h"





void I2C_voidMasterInit(void)
{
	/* Set frequency 400 khz , prescalar value 0 */
	CLR_BIT(TWSR,TWSR_TWPS1);
	CLR_BIT(TWSR,TWSR_TWPS0);
	TWBR = 0x02;

	/* Enable ACK */
	SET_BIT(TWCR,TWCR_TWEA);

	/* Enable I2C */
	SET_BIT(TWCR,TWCR_TWEN);


}

void I2C_voidSlaveInit(uint8_t Copy_u8SlaveAdd)
{
	/* Set Slave Address In TWAR */
	TWAR = Copy_u8SlaveAdd<<1;


	/* Enable ACK */
	SET_BIT(TWCR,TWCR_TWEA);

	/* Enable I2C */
	SET_BIT(TWCR,TWCR_TWEN);
	
	/* Slave Hears */
	while(!(TWCR&(1<<TWCR_TWINT)));


}

I2C_Error_States I2C_enuSendStartCondition(void)
{
	I2C_Error_States Local_enuState = I2C_Ok;

	/* Start Condition */
	SET_BIT(TWCR,TWCR_TWSTA);

	/* Clear Flag */
	SET_BIT(TWCR,TWCR_TWINT);


	/* Polling On The Flag */
	while(!GET_BIT(TWCR,TWCR_TWINT));

	/* Check Status code */
	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MT_SC_ACK)
	{
		Local_enuState = I2C_SC_Error;
	}
	else
	{

	}
	return Local_enuState;
}

I2C_Error_States I2C_enuSendReStartCondition(void)
{
	I2C_Error_States Local_enuState = I2C_Ok;
	/* Start Condition */
	SET_BIT(TWCR,TWCR_TWSTA);

	/* Clear Flag */
	SET_BIT(TWCR,TWCR_TWINT);


	/* Polling On The Flag */
	while(!GET_BIT(TWCR,TWCR_TWINT));

	/* Check Status code */
	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MT_RSC_ACK)
	{
		Local_enuState = I2C_RSC_Error;
	}
	else
	{

	}
	return Local_enuState;
}

I2C_Error_States I2C_enuSendSlaveAddWithWrite(uint8_t Copy_u8SlaveAdd)
{
	I2C_Error_States Local_enuState = I2C_Ok;
	/* Write Slave Address */
	TWDR = Copy_u8SlaveAdd<<1;
	/* Write W Bit */
	CLR_BIT(TWDR,0);

	/* Clear Start Condition  */
	CLR_BIT(TWCR,TWCR_TWSTA);

	/* Clear Flag */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Polling On the Flag */
	while(!GET_BIT(TWCR,TWCR_TWINT));

	/* Check Status code */
	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MT_SLA_W_ACK)
	{
		Local_enuState = I2C_SLA_W_Error;
	}
	else
	{

	}
	return Local_enuState;

}

I2C_Error_States I2C_enuSendSlaveAddWithRead(uint8_t Copy_u8SlaveAdd)
{
	I2C_Error_States Local_enuState = I2C_Ok;
	/* Write Slave Address */
	TWDR = Copy_u8SlaveAdd<<1;
	/* Write W Bit */
	SET_BIT(TWDR,0);

	/* Clear Start Condition  */
	CLR_BIT(TWCR,TWCR_TWSTA);

	/* Clear Flag */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Polling On the Flag */
	while(!GET_BIT(TWCR,TWCR_TWINT));

	/* Check Status code */
	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MR_SLA_R_ACK)
	{
		Local_enuState = I2C_SLA_R_Error;
	}
	else
	{

	}
	return Local_enuState;

}

I2C_Error_States I2C_enuMasterSendDataByte(uint8_t Copy_u8Data)
{
	I2C_Error_States Local_enuState = I2C_Ok;
	/* Write Data on The Data register */
	TWDR = Copy_u8Data;


	/* Clear Flag */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Polling On the Flag */
	while(!GET_BIT(TWCR,TWCR_TWINT));

	/* Check Status code */
	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MT_DATA_ACK)
	{
		Local_enuState = I2C_DATA_Error;
	}
	//else
	//{

	//}

	return Local_enuState;

}

I2C_Error_States I2C_enuMasterReadDataByte(uint8_t * Copy_pu8Data)
{
	I2C_Error_States Local_enuState = I2C_Ok;

	/* Clear flag */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Polling on the Flag */
	while(!GET_BIT(TWCR,TWCR_TWINT));
	/* Check Status code */
	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MR_DATA_ACK)
	{
		Local_enuState = I2C_MR_DATA_Error;
	}
	else
	{
		*Copy_pu8Data = TWDR;
	}


	return Local_enuState;
}

/* I2C_Error_States I2C_U8SlaveReceive(uint8_t *Copy_u8Data)
{
	I2C_Error_States Local_enuState = I2C_Ok;
	TWCR |= (1<<7);
	while (!(TWCR & (1<<7)));
	if ((TWSR & 0xF8) != 0x80)
	{
		Local_enuState = I2C_SR_Error;
	}else{
		
		*Copy_u8Data=TWDR;
		
	}
	return Local_enuState;
}*/
void I2C_voidSendStopCondition(void)
{
	//Stop Condition
	SET_BIT(TWCR,TWCR_TWSTO);

	//Clear Flag
	SET_BIT(TWCR,TWCR_TWINT);


}
