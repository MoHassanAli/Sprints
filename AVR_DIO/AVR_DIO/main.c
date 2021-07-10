/*
 * AVR_DIO.c
 *
 * Created: 7/10/2021 5:41:34 PM
 * Author : Mohamed
 */ 


#include "DataTypes.h"
#include "BIT_Math.h"
#include "DIO_Interface.h"


int main(void)
{
      DIO_voidSetPinDirection(PORT_A, PIN0, OUTPUT);
      DIO_voidSetPinValue(PORT_A, PIN0, HIGH);
    while (1) 
    {
    }
}

