/* Auther 		: 	Mohamed Hassan   */
/* Date		 	: 	7/7/2021         */
/* Version 		: 	V1               */



#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_


void DIO_VidSetPortDirection(u8 Copy_U8Port, u8 Copy_U8PortDirection_0xFF);
void DIO_VidSetPinDirection(u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Direction);


void DIO_VidSetPortValue(u8 Copy_U8Port, u8 Copy_U8PortValue_0xFF);
void DIO_VidSetPinValue(u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Value);


void DIO_VidGetPortValue(u8 Copy_U8Port, u8 * Copy_PU8Value);
void DIO_VidGetPinValue(u8 Copy_U8Port, u8 Copy_U8Pin, u8 * Copy_PU8Value);


void DIO_VidTogglePort(u8 Copy_U8Port);
void DIO_VidTogglePin(u8 Copy_U8Port , u8 Copy_U8Pin);


#endif
