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
#include "HAL/KPD_Interface.h"
#include "MCAL/DIO_Interface.h"

uint8_t String_u8Numb(uint8_t *Str);
int main(void)
{
	uint32_t temp=0;
	uint32_t oldtemp=0;
	uint8_t keyValue;
	uint8_t key_read[10];
	uint8_t i=0;
	uint8_t key;

	LM35_Init();
	LCD_VidInit();
	Key_VidInit();

	LCD_VidSendString("Set Temp:");
	LCD_GoToXY(1,0);
	LCD_VidSendString("Press =");

	DIO_VidSetPinDirection(PortA,PIN2,OUTPUT);


	while(1){
		keyValue = Key_U8GetKey();
		if(keyValue != NOT_PRESSED){
			key_read[i]=keyValue;
			LCD_GoToXY(0,9+i);
			LCD_VidSendData(keyValue);
			i++;
		}
		if(keyValue == '=')
		{
			break;
		}

	}

	while(1){
		key = String_u8Numb(key_read);
		LM35_VidRead(&temp);
		LCD_GoToXY(0,0);

		if (temp != oldtemp) {
			LCD_VidSendCommand(CLR_LCD);
			LCD_WriteNumber(temp);
			oldtemp = temp;
			if(temp> key){
				DIO_VidSetPinValue(PortA,PIN2,LOW);
			}else{

				DIO_VidSetPinValue(PortA,PIN2,HIGH);
			}

		}

	}
}

uint8_t String_u8Numb(uint8_t *Str)
{
	uint8_t Numb = 0;
	Numb = (Str[0] - '0') * 10 + (Str[1] - '0');

	return Numb;
}
