

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


typedef enum
{
	STD_TYPES_u8_ERROR_OK,

}EEPROM_Error_States;

uint8_t EEPROM_u8WriteDataByte(uint32_t Copy_u16ByteAddress, uint8_t Copy_u8Data);
uint8_t EEPROM_u8ReadDataByte(uint32_t Copy_u16ByteAddress,uint8_t * Copy_pu8ReturnData);

#endif /* EEPROM_INTERFACE_H_ */
