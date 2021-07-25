/*
 * SPI_v1.c
 *
 * Created: 7/14/2021 9:08:52 PM
 * Author : Mohamed
 */ 

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO_Interface.h"
#include "MCAL/SPI_Interface.h"
#include "MCAL/UART.h"


int main(void)
{
    uint8_t str[100];
	
	UART_init();
	SPI_VidInitMaster();
    while (1) 
    {
		
		UART_receiveString(str);
		SPI_VidSendString(str);
    }
}

