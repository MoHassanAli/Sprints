/*
 * UART_test.c
 *
 * Created: 7/24/2021 11:45:03 PM
 *  Author: Mohamed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "assert.h"
#include "stdio.h"

#define	RXC			7		//USART Receive Complete
#define	TXC			6		//USART Transmit Complete
#define	UDRE		5		//USART Data Register Empty
#define	FE			4		//Frame Error
#define	DOR			3		//Data OverRun
#define	PE			2		//Parity Error
#define	U2X			1		// Double the USART Transmission Speed
#define	MPCM		0		// Multi-processor Communication Mode


/* UCSRB REGISTER*/
#define	RXCIE			7			//RX Complete Interrupt Enable
#define	TXCIE			6			//TX Complete Interrupt Enable
#define	UDRIE			5			// Data Register Empty Interrupt Enable
#define	RXEN			4			// Receiver Enable
#define	TXEN			3			// Transmitter Enable
#define	UCSZ2			2			// Character Size
#define	RXB8			1			// Receive Data Bit 8
#define	TXB8			0			//  Transmit Data Bit 8


#define	URSEL			7			//Register Select
/*
This bit selects between accessing the UCSRC or the UBRRH Register.
 It is read as one when reading UCSRC.
 The URSEL must be one when writing the UCSRC
*/
#define	UMSEL			6			//USART Mode Select

//  Parity Mode Select
#define	UPM1			5
#define	UPM0			4

#define	USBS			3			// Stop Bit Select
#define	UCSZ1			2			// Character Size
#define	UCSZ0			1
#define	UCPOL			0			//  Clock Polarity

uint8_t UDR;
uint8_t UCSRA;
uint8_t UCSRB;
uint8_t UBRRL;
uint8_t UBRRH;
uint8_t UCSRC;

#define NO_E   1
#define F_CPU 1000000UL //1MHz Clock frequency
/* UART Driver Baud Rate */
#define USART_BAUDRATE 9600

#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 8UL))) - 1)



/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void UART_init(void)
{

	UCSRA = (1<<U2X);


	UCSRB = (1 << RXEN) | (1 << TXEN);

	UCSRC = ((1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1));

	UBRRH = BAUD_PRESCALE>>8;
	UBRRL = BAUD_PRESCALE;
}

uint8_t UART_sendByte(const uint8_t data)
{


	UDR = data;
	return NO_E;


}

uint8_t UART_recieveByte(void)
{
	uint8_t data;
	data=UDR;
	return data;

}

void UART_sendString(const uint8_t *Str)
{
	uint8_t i = 0;
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}
}

void UART_receiveString(uint8_t *Str)
{
	uint8_t i = 0;
	Str[i] = UART_recieveByte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_recieveByte();
	}
	Str[i] = '\0';
}


void UART_SendByteTest (void)
{
	assert(UART_sendByte('a')== NO_E);

}

void UART_ReceiveTest(void)
{
	assert(UART_recieveByte()=='a');

}

void main()
{

	UART_init();
	UART_SendByteTest();
	UART_ReceiveTest();
	printf("No Error");
}


