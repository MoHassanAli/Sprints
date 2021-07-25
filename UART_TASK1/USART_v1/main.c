/*
 * USART_v1.c
 *
 * Created: 7/13/2021 10:39:13 PM
 * Author : Mohamed
 */ 

#include "MCAL/UART.h"
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
int main(void)
{
	uint8_t Str[20];
	UART_init();
	while(1)
	{
		UART_receiveString(Str); 
		UART_sendString(Str); 
		
	}
}

