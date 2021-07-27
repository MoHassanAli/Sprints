


#define	F_CPU	1000000UL                                // F_CPU 8000000UL






#include "../LIB/STD_Types.h"
#include "../LIB/BIT_MATH.h"
#include "LM35_Interface.h"
#include "../MCAL/DIO_Interface.h"


void LM35_Init(void)
{
	DIO_VidSetPinDirection(PortA,PIN0,INPUT);
	ADC_VidInit();

}


void LM35_VidRead(u16 * Copy_U16Read_LM35)
{
	ADC_VidSelectChannel(0);
	u16 Temp;

	ADC_VidRead(&Temp);
	Temp = Temp*0.25;
	*Copy_U16Read_LM35 = Temp;

}
