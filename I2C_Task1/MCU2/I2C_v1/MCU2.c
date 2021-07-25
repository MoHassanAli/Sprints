/*
 * I2C_v1.cpp
 *
 * Created: 7/18/2021 3:46:13 PM
 * Author : Mohamed
 */ 
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO_Interface.h"
#include "MCAL/I2C_interface.h"


int main(void)
{
    uint8_t DataRecieved;
	
	I2C_voidSlaveInit(1);
	DIO_VidSetPortDirection(PortB,255);
	I2C_enuMasterReadDataByte(&DataRecieved);
	DIO_VidSetPortValue(PortB,DataRecieved);
	
    while (1) 
    {
		
		
		
	
		
		
    }
}

