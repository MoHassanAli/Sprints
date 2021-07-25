/*
 * SPI_v1.c
 *
 * Created: 7/14/2021 9:08:52 PM
 * Author : Mohamed
 */ 

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO_Interface.h"
#include "MCAL/SPI_Interface.h"


int main(void)
{
	uint8_t DataRecieved;
    SPI_VidInitSlave();
	DIO_VidSetPortDirection(PortC,255);
    while (1) 
    {
		DataRecieved = SPI_U8RecieveByte();
		DIO_VidSetPortValue(PortC,DataRecieved);
    }
}

