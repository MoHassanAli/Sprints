

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "I2C_interface.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"

EEPROM_Error_States EEPROM_u8WriteDataByte(uint32_t Copy_u16ByteAddress, uint8_t Copy_u8Data)
{
	EEPROM_Error_States Local_enuState = STD_TYPES_u8_ERROR_OK;
	/* Start Condition */
	I2C_enuSendStartCondition();

	/* Send Slave Address with W operation */
	I2C_enuSendSlaveAddWithWrite( (EEPROM_FIXED_ADDRESS | (EEPROM_A2_VALUE << 2) | ((Copy_u16ByteAddress >> 8) & 3)) );

	/* Send Byte Address */
	I2C_enuMasterSendDataByte((uint8_t)Copy_u16ByteAddress);

	/* Send Data */
	I2C_enuMasterSendDataByte(Copy_u8Data);


//	/* Send Data */
//	I2C_enuMasterSendDataByte(10);

	/* Stop Condition */
	I2C_voidSendStopCondition();

	return Local_enuState;
}

EEPROM_Error_States EEPROM_sendString(uint32_t Copy_u16ByteAddress, uint8_t *Str)
{
	EEPROM_Error_States Local_enuState = STD_TYPES_u8_ERROR_OK;
	/* Start Condition */
	I2C_enuSendStartCondition();

	/* Send Slave Address with W operation */
	I2C_enuSendSlaveAddWithWrite( (EEPROM_FIXED_ADDRESS | (EEPROM_A2_VALUE << 2) | ((Copy_u16ByteAddress >> 8) & 3)) );

	/* Send Byte Address */
	I2C_enuMasterSendDataByte((uint8_t)Copy_u16ByteAddress);

	uint8_t i =0;
	while(Str[i] != '\0')
	{
		I2C_enuMasterSendDataByte(Str[i]);
		i++;
	}
	/* Stop Condition */
	I2C_voidSendStopCondition();

	return Local_enuState;
}

EEPROM_Error_States EEPROM_u8ReadDataByte(uint32_t Copy_u16ByteAddress,uint8_t * Copy_pu8ReturnData)
{
	EEPROM_Error_States Local_enuState = STD_TYPES_u8_ERROR_OK;
	/* Start Condition */
	I2C_enuSendStartCondition();

	/* Send Slave Address With W */
	I2C_enuSendSlaveAddWithWrite( (EEPROM_FIXED_ADDRESS | (EEPROM_A2_VALUE << 2) | ((Copy_u16ByteAddress >> 8) & 3)) );

	/* Send Byte Address */
	I2C_enuMasterSendDataByte((uint8_t)Copy_u16ByteAddress);

	/* Repeated Start Condition */
	I2C_enuSendReStartCondition();

	/* Send Slave Address With R */
	I2C_enuSendSlaveAddWithRead( (EEPROM_FIXED_ADDRESS | (EEPROM_A2_VALUE << 2) | ((Copy_u16ByteAddress >> 8) & 3)) );

	/* Read Data */
	I2C_enuMasterReadDataByte(Copy_pu8ReturnData);

	/* Stop Condition */
	I2C_voidSendStopCondition();

	return Local_enuState;
}


