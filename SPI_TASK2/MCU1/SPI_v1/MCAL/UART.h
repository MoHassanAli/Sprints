/*
 * UART.h
 *
 * Created: 7/13/2021 10:40:33 PM
 *  Author: Mohamed
 */ 


#ifndef UART_H_
#define UART_H_

#include "../LIB/STD_TYPES.h"
/*******************************************************************************
 *                      Rigesters                                  *
 *******************************************************************************/
#define UBRRL   (*(volatile uint8_t*)0x0029)

#define UCSRB   (*(volatile uint8_t*)0x002A)
#define TXB8    0
#define RXB8    1
#define UCSZ2   2
#define TXEN    3
#define RXEN    4
#define UDRIE   5
#define TXCIE   6
#define RXCIE   7

#define UCSRA   (*(volatile uint8_t*)0x002B)
#define MPCM    0
#define U2X     1
#define PE      2
#define DOR     3
#define FE      4
#define UDRE    5
#define TXC     6
#define RXC     7

#define UDR     (*(volatile uint8_t*)0x002C)


#define UCSRC   (*(volatile uint8_t*)0x0040)
#define UCPOL   0
#define UCSZ0   1
#define UCSZ1   2
#define USBS    3
#define UPM0    4
#define UPM1    5
#define UMSEL   6
#define URSEL   7

#define UBRRH   (*(volatile uint8_t*)0x0040)
#define URSEL   7
/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define F_CPU 1000000UL //1MHz Clock frequency
/* UART Driver Baud Rate */
#define USART_BAUDRATE 9600

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void UART_init(void);

void UART_sendByte(const uint8_t data);

uint8_t UART_recieveByte(void);

void UART_sendString(const uint8_t *Str);

void UART_receiveString(uint8_t *Str); // Receive until #




#endif /* UART_H_ */