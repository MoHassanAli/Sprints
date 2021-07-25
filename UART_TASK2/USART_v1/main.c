/*
 * USART_v1.c
 *
 * Created: 7/13/2021 10:39:13 PM
 * Author : Mohamed
 */ 


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO_Interface.h"
#include "MCAL/UART.h"


void Traffic_Lights(uint8_t*str);


int main(void)
{
	uint8_t LOC_u8str[30]={};
	
	
	DIO_VidSetPinDirection(PortA,PIN0,OUTPUT);
	DIO_VidSetPinDirection(PortA,PIN1,OUTPUT);
	DIO_VidSetPinDirection(PortA,PIN2,OUTPUT);
	
	
	UART_init();
	while(1)
	{
		
		UART_receiveString(LOC_u8str);
		Traffic_Lights(LOC_u8str);
	}
}


void Traffic_Lights(uint8_t*str){
	
	uint8_t index=-1;
	uint8_t row,col;
	uint8_t strDataBase[4][10]={"start","wait","stop","at"};
	uint8_t WrongData[20]="wrong data\r";	
	uint8_t LOC_u8start[30]="Green LED ON\r";
	uint8_t LOC_u8wait[30]="Yellow LED ON\r";
	uint8_t LOC_u8stop[30]="Red LED ON\r";
	uint8_t LOC_u8AT[10]="OK\r";
	
		for(row=0;row<4;row++){
			for(col=0;col<10;col++){
				if(str[col]!=strDataBase[row][col]){
					break;
				}
				if(str[col]=='\0'){
					index=row;
				}
			}
		}
		if(index==-1){
			UART_sendString(WrongData);
		}else if(index==0){
			
			DIO_VidSetPinValue(PortA,PIN2,HIGH);
			DIO_VidSetPinValue(PortA,PIN1,LOW);
			DIO_VidSetPinValue(PortA,PIN0,LOW);
			UART_sendString(LOC_u8start);
			
		}else if(index==1){
			DIO_VidSetPinValue(PortA,PIN2,LOW);
			DIO_VidSetPinValue(PortA,PIN1,HIGH);
			DIO_VidSetPinValue(PortA,PIN0,LOW);
			UART_sendString(LOC_u8wait);
			
		}else if(index==2){
			DIO_VidSetPinValue(PortA,PIN2,LOW);
			DIO_VidSetPinValue(PortA,PIN1,LOW);
			DIO_VidSetPinValue(PortA,PIN0,HIGH);
			UART_sendString(LOC_u8stop);
		
		}else if(index==3){
			UART_sendString(LOC_u8AT);
		}
	
	}
	

