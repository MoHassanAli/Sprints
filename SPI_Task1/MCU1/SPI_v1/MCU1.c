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
    SPI_VidInitMaster();
    while (1) 
    {
		SPI_VidSendByte('A');
    }
}

