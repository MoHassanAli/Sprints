/*
 * Thermostat.c
 *
 * Created: 7/24/2021 6:29:00 PM
 * Author : Mohamed
 */ 

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "HAL/LM35_Interface.h"
#include "MCAL/UART.h"
#include "HAL/LCD_Interface.h"


int main(void)
{
	uint32_t temp=0;
	uint32_t oldtemp=0;
	LM35_Init();
	LCD_VidInit();
	
	while(1){
		LM35_VidRead(&temp);
		if (temp != oldtemp) {
			LCD_VidSendCommand(CLR_LCD);
			LCD_WriteNumber(temp);
			oldtemp = temp;
		}
		
	}
}

