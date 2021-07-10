/*
 * AVR_Timer.c
 *
 * Created: 7/10/2021 11:14:05 PM
 * Author : Mohamed
 */ 

#include "std_type.h"
#include "DIO_Interface.h"
#include "Timer_Interface.h"

#define F_CPU 8000000


int main(void)
{
	Timer0_Init();
    DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	
	
  
    while (1) 
    {
		
		
		
		Timer0_Delay(1000000);
		
		
		
    }
}

