/*
 * EEPROM_v1.c
 *
 * Created: 7/18/2021 8:01:17 PM
 * Author : Mohamed
 */ 

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO_Interface.h"
#include "MCAL/EEPROM_interface.h"
#include "MCAL/I2C_interface.h"
#include "MCAL/UART.h"
#include "util/delay.h"
#include "string.h"


int main(void)
{
	
	uint8_t DataRecived[50];
	uint8_t Address;
	uint8_t ActualData;
	uint8_t Read;
	
	DIO_VidSetPortDirection(PortA,255);
	//DIO_VidSetPortDirection(PortD,255);
	DIO_VidSetPinDirection(PortD,PIN0,INPUT);
	DIO_VidSetPinDirection(PortD,PIN1,OUTPUT);
	I2C_voidMasterInit();
	UART_init();
    while (1) 
    {
		
		UART_sendString((uint8_t*)"Enter your Operation: \r");
		UART_receiveString(DataRecived);
		
		if (strcmp(DataRecived,"WRITE") == 0)
		{
			UART_sendString((uint8_t*)"Enter Address: \r");
			UART_receiveString(DataRecived);
			Address = ConvertFromAscitoInt(DataRecived);
			UART_sendByte(Address);
			UART_sendString((uint8_t*)"\rOK \rEnter Data: \r");
			ActualData = UART_recieveByte();
			UART_sendString((uint8_t*)"\rOK\r");
			EEPROM_u8WriteDataByte(Address,ActualData);			
		}
		
		if(strcmp(DataRecived,"READ") == 0)
		{
			UART_sendString((uint8_t*)"Enter Address To Read: \r");
			UART_receiveString(DataRecived);
			Address = ConvertFromAscitoInt(DataRecived);
			_delay_ms(50);
			EEPROM_u8ReadDataByte(Address,&Read);
			DIO_VidSetPortValue(PortA,Read);
		}
		
		
    }
}

