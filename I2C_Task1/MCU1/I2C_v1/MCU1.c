/*
 * I2C_v1.cpp
 *
 * Created: 7/18/2021 3:46:13 PM
 * Author : Mohamed
 */ 

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/I2C_interface.h"


int main(void)
{
    I2C_voidMasterInit();
	I2C_enuSendStartCondition();
	I2C_enuSendSlaveAddWithWrite(1);
	I2C_enuMasterSendDataByte('A');
	I2C_voidSendStopCondition();
    while (1) 
    {
		
    }
}

