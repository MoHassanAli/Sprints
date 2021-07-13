/*
 * AVR_DIO.c
 *
 * Created: 7/10/2021 5:41:34 PM
 * Author : Mohamed
 */ 


#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO_Interface.h"


int main(void)
{
      DIO_VidSetPinDirection(PortA, PIN0, OUTPUT);
      DIO_VidSetPinValue(PortA, PIN0, HIGH);
    while (1) 
    {
    }
}

