
/*  Auther       :  Mohamed Hassan     */
/*  Date          :  19/10/2020             */
/*  Version      :  v1                          */
/*  Description :  DIO_DRIVER           */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "DIO_Private.h"



void DIO_VidSetPinDirection(uint8_t copy_U8Port , uint8_t copy_U8Pin ,uint8_t copy_U8Direction)
{
	/* check if die is output\*/
	if(OUTPUT == copy_U8Direction)
	{
		switch (copy_U8Port)
		{
			case PortA : SET_BIT(DDRA,copy_U8Pin); break;
			case PortB : SET_BIT(DDRB,copy_U8Pin); break;
			case PortC : SET_BIT(DDRC,copy_U8Pin); break;
			case PortD : SET_BIT(DDRD,copy_U8Pin); break;
			default:                                           break;
		}
	}
	else if (INPUT == copy_U8Direction) /* check if dire is input */
	{
		switch (copy_U8Port)
		{
			case PortA : CLR_BIT(DDRA,copy_U8Pin); break;
			case PortB : CLR_BIT(DDRB,copy_U8Pin); break;
			case PortC : CLR_BIT(DDRC,copy_U8Pin); break;
			case PortD : CLR_BIT(DDRD,copy_U8Pin); break;
			default:                                           break;
		}
	}
}


void DIO_VidSetPinValue(uint8_t copy_U8Port , uint8_t copy_U8Pin ,uint8_t copy_U8Value)
{

	if(OUTPUT == copy_U8Value)
	{
		switch (copy_U8Port)
		{
			case PortA : SET_BIT(PORTA,copy_U8Pin); break;
			case PortB : SET_BIT(PORTB,copy_U8Pin); break;
			case PortC : SET_BIT(PORTC,copy_U8Pin); break;
			case PortD : SET_BIT(PORTD,copy_U8Pin); break;
			default:                                           break;
		}
	}
	else if (INPUT == copy_U8Value)
	{
		switch (copy_U8Port)
		{
			case PortA : CLR_BIT(PORTA,copy_U8Pin); break;
			case PortB : CLR_BIT(PORTB,copy_U8Pin); break;
			case PortC : CLR_BIT(PORTC,copy_U8Pin); break;
			case PortD : CLR_BIT(PORTD,copy_U8Pin); break;
			default:                                           break;
		}
	}
}

void DIO_VidSetPortDirection(uint8_t copy_U8Port ,uint8_t copy_U8Direction)
{
	switch(copy_U8Port)
	{
		case PortA :DDRA = copy_U8Direction; break;
		case PortB :DDRB = copy_U8Direction; break;
		case PortC :DDRC = copy_U8Direction; break;
		case PortD :DDRD = copy_U8Direction; break;
		default:   break;

	}

}

void DIO_VidSetPortValue(uint8_t copy_U8Port ,uint8_t copy_U8Value)
{
	switch(copy_U8Port)
	{
		case PortA :PORTA = copy_U8Value; break;
		case PortB :PORTB = copy_U8Value; break;
		case PortC :PORTC = copy_U8Value; break;
		case PortD :PORTD = copy_U8Value; break;
		default:   break;
	}

}

void DIO_VidTogglePin(uint8_t copy_U8Port ,uint8_t copy_U8Pin)
{
	switch (copy_U8Port)
		{
			case PortA : TOG_BIT(PORTA,copy_U8Pin); break;
			case PortB : TOG_BIT(PORTB,copy_U8Pin); break;
			case PortC : TOG_BIT(PORTC,copy_U8Pin); break;
			case PortD : TOG_BIT(PORTD,copy_U8Pin); break;
			default:                                           break;
		}
}

uint8_t DIO_U8GetPinValue(uint8_t copy_U8Port ,uint8_t copy_U8Pin)
{
	uint8_t LOC_var;
	switch (copy_U8Port)
		{
			case PortA : LOC_var = GET_BIT(PINA,copy_U8Pin);
				return LOC_var;
				break;
			case PortB : LOC_var = GET_BIT(PINB,copy_U8Pin);
			return LOC_var;
				break;
			case PortC : LOC_var = GET_BIT(PINC,copy_U8Pin);
				return LOC_var;
				break;
			case PortD : LOC_var = GET_BIT(PIND,copy_U8Pin);
				return LOC_var;
				break;
			default:
				return 20;
				break;
		}
}
