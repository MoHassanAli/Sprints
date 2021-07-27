

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO_Interface.h"
#include "LCD_Private.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "util/delay.h"


void LCD_VidInit() {
	#if (LCD_MODE==Eight_BIT)
	{
		DIO_VidSetPortDirection(PortC, 255);
		DIO_VidSetPortDirection(PortD, 255);
		_delay_ms(50);
		LCD_VidSendCommand(0b00111000);
		_delay_ms(1);
		LCD_VidSendCommand(0b00001100);
		_delay_ms(1);
		LCD_VidSendCommand(1);
		_delay_ms(2);
	}
	#elif (LCD_MODE == Four_BIT)
	{
		DIO_VidSetPortDirection(PortC,255);
		DIO_VidSetPortDirection(PortD,255);
		_delay_ms(50);

	}
	#else
	{
		#error "Incorrect mode";
	}
	#endif

	

}

void LCD_VidSendData(uint8_t copy_U8Data) {
	DIO_VidSetPinValue(PortD, PIN2, HIGH);
	
	DIO_VidSetPinValue(PortD, PIN1, LOW);
	DIO_VidSetPortValue(PortC, copy_U8Data);
	DIO_VidSetPinValue(PortD, PIN0, HIGH);
	_delay_ms(1); //delay enable pin
	DIO_VidSetPinValue(PortD, PIN0, LOW);
	_delay_ms(1);

}

void LCD_VidSendCommand(uint8_t copy_U8Command) {
	DIO_VidSetPinValue(PortD, PIN2, LOW);
	//void LCD_VidLatch(u8 copy_U8Command);
	DIO_VidSetPinValue(PortD, PIN1, LOW);
	DIO_VidSetPortValue(PortC, copy_U8Command);
	DIO_VidSetPinValue(PortD, PIN0, 1);
	_delay_ms(1); //delay enable pin
	DIO_VidSetPinValue(PortD, PIN0, LOW);
	_delay_ms(1);
}


void LCD_VidSendString(uint8_t *copy_U8String) {
	while (*copy_U8String != 0) {
		LCD_VidSendData(*copy_U8String);
		copy_U8String++;
	}
}

void LCD_GoToXY(uint8_t copy_U8X, uint8_t copy_U8Y) {
	if (0 == copy_U8X) {
		LCD_VidSendCommand(128 + copy_U8Y);
	} else if (1 == copy_U8X) {
		LCD_VidSendCommand(128 + 64 + copy_U8Y);
	}
}

void LCD_VidDraw(uint8_t copy_U8Pattern[], uint8_t copy_U8Size) //bthays
{
	LCD_VidSendCommand(0x40);
	uint8_t LOC_U8Iter = 0;
	for (LOC_U8Iter = 0; LOC_U8Iter < copy_U8Size; LOC_U8Iter++) {
		LCD_VidSendData(copy_U8Pattern[LOC_U8Iter]);
	}
	LCD_GoToXY(0, 0);
	LCD_VidSendCommand(0x04);
	//LCD_VidSendCommand(DECREMENT_CURSOR_TO_LEFT);
	for (LOC_U8Iter = 0; LOC_U8Iter <= 7; LOC_U8Iter++) {
		LCD_VidSendData(LOC_U8Iter);
	}

}

void LCD_VidSendNum (uint32_t Copy_U32Num)
{
	uint8_t rem=0,arr[10]={0},counter=0, Get_Ascii = 0,j ;

	if ((Copy_U32Num>=0) && (Copy_U32Num<10))
	{
		Get_Ascii = 0;
		Get_Ascii=Copy_U32Num+48;
		LCD_VidSendData(Get_Ascii);
	}
	else
	{
		Get_Ascii = 0;
		for(uint8_t i=0;i<10;i++)
		{
			if (Copy_U32Num!=0)
			{
				rem=Copy_U32Num%10;
				Copy_U32Num=Copy_U32Num/10;
				arr[i]=rem;
				counter++;
			}
			else
			{
				break;
			}

		}
		for (j=(counter-1) ;j>=0 ;j--)
		{

			Get_Ascii=arr[j]+48 ;
			LCD_VidSendData(Get_Ascii);
			if (j==0) break ;
		}
	}
}

void LCD_WriteNumber(sint16_t num){
	u16 n=1;
	if (num==0)
	{
		LCD_VidSendData(  (   (num/n)%10) +48);

	}else{
		if(GET_BIT(num,15)==0x01){
			num=num*-1;
			LCD_VidSendData('-');
		}
		for(n=10000;n>=1;n/=10){
			if(num>=n){
				LCD_VidSendData(((num/n)%10)+48);
			}
		}
	}

}
