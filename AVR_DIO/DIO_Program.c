/* Auther 		: 	Mohamed Hassan   */
/* Date		 	: 	7/7/2021         */
/* Version 		: 	V1               */




#include "AVR32_REG.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"
#include "STD_Types.h"

/********************************************************************************/
void DIO_VidSetPortDirection(u8 Copy_U8Port , u8 Copy_U8PortDirection_0xFF)
{
	switch (Copy_U8Port)
	{
		case PORT_A : DDRA = Copy_U8PortDirection_0xFF ; break ;
		case PORT_B : DDRB = Copy_U8PortDirection_0xFF ; break ;
		case PORT_C : DDRC = Copy_U8PortDirection_0xFF ; break ;
		case PORT_D : DDRD = Copy_U8PortDirection_0xFF ; break ;
		default		:									 break ;
	}
}



/********************************************************************************/
void DIO_VidSetPinDirection(u8 Copy_U8Port , u8 Copy_U8Pin , u8 Copy_U8PinDirection)
{
	/* Check if Direction is output */
	if ( OUTPUT == Copy_U8PinDirection)
	{
		switch (Copy_U8Port)
		{
			case PORT_A : SET_BIT( DDRA , Copy_U8Pin ) ; break ;
			case PORT_B : SET_BIT( DDRB , Copy_U8Pin ) ; break ;
			case PORT_C : SET_BIT( DDRC , Copy_U8Pin ) ; break ;
			case PORT_D : SET_BIT( DDRD , Copy_U8Pin ) ; break ;
			default		: 							   	 break ;
		}
	}
	/* Check if Direction is input */
	else if ( INPUT == Copy_U8PinDirection)
	{
		switch (Copy_U8Port)
		{
			case PORT_A : CLR_BIT( DDRA , Copy_U8Pin ) ; break ;
			case PORT_B : CLR_BIT( DDRB , Copy_U8Pin ) ; break ;
			case PORT_C : CLR_BIT( DDRC , Copy_U8Pin ) ; break ;
			case PORT_D : CLR_BIT( DDRD , Copy_U8Pin ) ; break ;
			default		: 							   	 break ;
		}
	}
}

/***********************************************************************/
void DIO_VidSetPortValue(u8 Copy_U8Port , u8 Copy_U8PortValue_0xFF)
{
	switch(Copy_U8Port)
	{
		case PORT_A : PORTA = Copy_U8PortValue_0xFF ; break ;
		case PORT_B : PORTB = Copy_U8PortValue_0xFF ; break ;
		case PORT_C : PORTC = Copy_U8PortValue_0xFF ; break ;
		case PORT_D : PORTD = Copy_U8PortValue_0xFF ; break ;
		default		: 					 		  	  break ;
	}
}




/********************************************************************************/
void DIO_VidSetPinValue(u8 Copy_U8Port , u8 Copy_U8Pin , u8 Copy_U8PinValue)
{
	if (HIGH == Copy_U8PinValue)
	{
		switch (Copy_U8Port)
		{
			case PORT_A : SET_BIT( PORTA , Copy_U8Pin ) ; break ;
			case PORT_B : SET_BIT( PORTB , Copy_U8Pin ) ; break ;
			case PORT_C : SET_BIT( PORTC , Copy_U8Pin ) ; break ;
			case PORT_D : SET_BIT( PORTD , Copy_U8Pin ) ; break ;
			default		: 						  	   	  break ;
		}
	}


	else if (LOW == Copy_U8PinValue)
	{
		switch (Copy_U8Port)
		{
			case PORT_A : CLR_BIT( PORTA , Copy_U8Pin ) ; break ;
			case PORT_B : CLR_BIT( PORTB , Copy_U8Pin ) ; break ;
			case PORT_C : CLR_BIT( PORTC , Copy_U8Pin ) ; break ;
			case PORT_D : CLR_BIT( PORTD , Copy_U8Pin ) ; break ;
			default		: 						   	  	  break ;
		}
	}
}

/***********************************************************************/
void DIO_VidGetPortValue(u8 Copy_U8Port, u8 * Copy_PU8PortValue)
{
	switch (Copy_U8Port)
	{
		case PORT_A : *Copy_PU8PortValue = PINA ; break ;
		case PORT_B : *Copy_PU8PortValue = PINB ; break ;
		case PORT_C : *Copy_PU8PortValue = PINC ; break ;
		case PORT_D : *Copy_PU8PortValue = PIND ; break ;
		default		: 							  break ;
	}
}



/***********************************************************************/
void DIO_VidGetPinValue(u8 Copy_U8Port , u8 Copy_U8Pin , u8 * Copy_PU8PinValue)
{
	switch (Copy_U8Port)
	{
		case PORT_A : *Copy_PU8PinValue = GET_BIT( PINA , Copy_U8Pin ) ; break ;
		case PORT_B : *Copy_PU8PinValue = GET_BIT( PINB , Copy_U8Pin ) ; break ;
		case PORT_C : *Copy_PU8PinValue = GET_BIT( PINC , Copy_U8Pin ) ; break ;
		case PORT_D : *Copy_PU8PinValue = GET_BIT( PIND , Copy_U8Pin ) ; break ;
		default		: 											  		 break ;
	}
}




/***********************************************************************/
void DIO_VidTogglePort(u8 Copy_U8Port)
{


	switch (Copy_U8Port)
	{
		case PORT_A : TGL_PORT( PORTA ) ; break;
		case PORT_B : TGL_PORT( PORTB ) ; break;
		case PORT_C : TGL_PORT( PORTC ) ; break;
		case PORT_D : TGL_PORT( PORTD ) ; break;
		default		:					  break;
	}
}




/***********************************************************************/
void DIO_VidTogglePin(u8 Copy_U8Port , u8 Copy_U8Pin)
{

	switch (Copy_U8Port)
	{
		case PORT_A : TGL_BIT( PORTA , Copy_U8Pin ) ; break;
		case PORT_B : TGL_BIT( PORTB , Copy_U8Pin ) ; break;
		case PORT_C : TGL_BIT( PORTC , Copy_U8Pin ) ; break;
		case PORT_D : TGL_BIT( PORTD , Copy_U8Pin ) ; break;
		default		: 								  break;
	}
}
