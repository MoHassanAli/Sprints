/*  Auther       :  Mohamed Hassan     */
/*  Date          :  19/10/2020             */
/*  Version      :  v1                          */
/*  Description :  Mohamed Hassan     */

#ifndef    _DIO_INTERFACE_H_
#define   _DIO_INTERFACE_H_

void DIO_VidSetPortDirection(uint8_t copy_U8Port, uint8_t copy_U8Direction);

void DIO_VidSetPinDirection(uint8_t copy_U8Port, uint8_t copy_U8Pin, uint8_t copy_U8Direction);

void DIO_VidSetPortValue(uint8_t copy_U8Port, uint8_t copy_U8Value);

void DIO_VidSetPinValue(uint8_t copy_U8Port, uint8_t copy_U8Pin, uint8_t copy_U8Value);

uint8_t DIO_U8GetPinValue(uint8_t copy_U8Port, uint8_t copy_U8Pin);

void DIO_VidTogglePin(uint8_t copy_U8Port, uint8_t copy_U8Pin);

#define PortA  0
#define PortB  1
#define PortC  2
#define PortD  3

#define OUTPUT   1
#define INPUT    0

#define HIGH        1
#define LOW    	    0

#define PIN0        0
#define PIN1        1
#define PIN2     	2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7

#endif
