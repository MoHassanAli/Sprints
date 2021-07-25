


#include "../LIB/STD_Types.h"
#include "../LIB/BIT_MATH.h"
#include "DIO_interface.h"



#include "ADC_Private.h"
#include "ADC_Config.h"

void ADC_VidSelectChannel(uint8_t Copy_U8Channel)
{

	ADMUX &= 0XE0;

	if ( Copy_U8Channel >= 0    &&    Copy_U8Channel <= 31 )
	{
		ADMUX|= Copy_U8Channel ;
	}
	else
	{
	}
}



/**********************************************************************/
void ADC_VidInit(void)
{


#if ADC_VREF == INTERNAL_AVCC
	SET_BIT( ADMUX , 6 ) ; // REFS0
	SET_BIT( ADMUX , 7 ) ; // REFS1
#endif


#if ADC_ADJ	== RIGHT_ADJ
	CLR_BIT( ADMUX , 5 ) ; // ADLAR

#elif ADC_ADJ == LEFT_ADJ
	SET_BIT( ADMUX , 5 ) ;

#endif



/**********************************************************************/
#if ADC_PRESCALER == PRESCALER_TWO
	CLR_BIT( ADCSRA , 0 ) ;
	SET_BIT( ADCSRA , 1 ) ;
	SET_BIT( ADCSRA , 2 ) ;

#elif ADC_PRESCALER == PRESCALER_EIGHT

#endif


	SET_BIT( ADCSRA , 7 ) ; // Enable ADC


}


void ADC_VidRead(u16 * Copy_ReadValue)
{
	u16 Read_Value;

	SET_BIT( ADCSRA , 6 ) ; // ( ADSC ) Start Converting

	while (!GET_BIT(ADCSRA,4));
		SET_BIT(ADCSRA,4);




	*Copy_ReadValue = ADC ;

}



/*

void ADC_EnuTriggingMode(u8 Copy_U8Mode)   // msh fahmha
{
	switch (Copy_U8Mode)
	{
		case 0 :
			CLR_BIT( ADCSRA , 5 ) ;
			break ;
		case 1 :
			SET_BIT( ADCSRA , 5 ) ;
			break ;
	}
}



void ADC_VidInterruptEnable(void)
{
	SET_BIT( ADCSRA , 3 ) ;
}



void ADC_VidInterruptDisable(void)
{
	CLR_BIT( ADCSRA , 3 ) ;
}

*/
