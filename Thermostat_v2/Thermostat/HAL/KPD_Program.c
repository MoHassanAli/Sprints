/*
 * key_prog.c
 *
 *  Created on: Oct 22, 2020
 *      Author: Mohamed
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO_Interface.h"
#include "KPD_Private.h"
#include "KPD_Config.h"
#include "util/delay.h"

uint8_t Rowarr[]={R1,R2,R3,R4};
uint8_t Colarr[]={C1,C2,C3,C4};
uint8_t key_u8Vals[4][4]=KEY_VALS;

void Key_VidInit(void)
{
	DIO_VidSetPortDirection(KEY_PORT,0x0f);
	DIO_VidSetPortValue(KEY_PORT,0xff);

}

uint8_t Key_U8GetKey(void)
{

	for (uint8_t ColIter =0; ColIter <=3 ; ColIter ++)
	{
		DIO_VidSetPinValue(KEY_PORT,Colarr[ColIter],LOW);
		for(uint8_t RowIter=0; RowIter <=3 ; RowIter++)
		{
			if(! DIO_U8GetPinValue(KEY_PORT ,Rowarr[RowIter]))
			{

				while(! DIO_U8GetPinValue(KEY_PORT ,Rowarr[RowIter]));
				_delay_ms(10);
				return key_u8Vals[RowIter][ColIter];
			}
		}
		DIO_VidSetPinValue(KEY_PORT,Colarr[ColIter],HIGH);
	}
	return NOT_PRESSED;
}
