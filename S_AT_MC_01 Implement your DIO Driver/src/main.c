
#include "../include/DIO_Interface.h"

int main()
{
    DIO_voidSetPinDirection(PORT_A, PIN0, OUTPUT);
    DIO_voidSetPinValue(PORT_A, PIN0, HIGH);
    
    while (1)
    {

    }
    
}