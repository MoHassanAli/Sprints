/*
 * SPI_test.c
 *
 * Created: 7/25/2021 12:19:48 AM
 *  Author: Mohamed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "assert.h"
#include "stdio.h"


#define PB4    4
#define PB5    5
#define PB6    6
#define PB7    7

#define MSTR	4
#define SPE		6
#define SPIF	7

#define NO_E    1

uint8_t SPDR;
uint8_t SPSR;
uint8_t SPCR;
uint8_t DDRB;


uint8_t SPI_VidInitMaster(void)
{
	/******** Configure SPI Master Pins *********
	 * SS(PB4)   --> Output
	 * MOSI(PB5) --> Output
	 * MISO(PB6) --> Input
	 * SCK(PB7) --> Output
	 ********************************************/
	DDRB = DDRB | (1<<PB4);
	DDRB = DDRB | (1<<PB5);
	DDRB = DDRB & ~(1<<PB6);
	DDRB = DDRB | (1<<PB7);

	SPCR = (1<<SPE) | (1<<MSTR); // enable SPI + enable Master + choose SPI clock = Fosc/4

	return NO_E;
}

uint8_t SPI_VidInitSlave(void)
{
	/******** Configure SPI Slave Pins *********
	 * SS(PB4)   --> Input
	 * MOSI(PB5) --> Input
	 * MISO(PB6) --> Output
	 * SCK(PB7) --> Input
	 ********************************************/
	DDRB = DDRB & (~(1<<PB4));
	DDRB = DDRB & (~(1<<PB5));
	DDRB = DDRB | (1<<PB6);
	DDRB = DDRB & (~(1<<PB7));
	SPCR = (1<<SPE); // just enable SPI + choose SPI clock = Fosc/4
	return NO_E;
}

uint8_t SPI_VidSendByte(const uint8_t copy_U8Data)
{
	SPDR = copy_U8Data;
	return NO_E;
}

uint8_t SPI_U8RecieveByte(void)
{
	uint8_t data;
	data = SPDR;
	return data;
}

void SPI_VidSendString(const uint8_t *copy_str)
{
	uint8_t i = 0;
	while(copy_str[i] != '\0')
	{
		SPI_VidSendByte(copy_str[i]);
		i++;
	}
}

void SPI_VidRecieveString(uint8_t *copy_str)
{
	unsigned char i = 0;
	copy_str[i] = SPI_U8RecieveByte();
	while(copy_str[i] != '\r')
	{
		i++;
		copy_str[i] = SPI_U8RecieveByte();
	}
	copy_str[i] = '\0';
}

void SPI_VidInitSlaveTest(void)
{

    assert(SPI_VidInitSlave()== E_OK);
    assert(SPCR == 64);
}

void SPI_VidInitMasterTest(void)
{

    assert(SPI_VidInitMaster()== E_OK);
    assert(SPCR == 80);
}


void SPI_SendByteTest(void)
{
	assert(SPI_VidSendByte('a')== NO_E);

}

void SPI_RecieveByteTest (void)
{
	assert(SPI_U8RecieveByte()=='a');

}

void main ()
{
	SPI_VidInitSlaveTest();
	SPI_SendByteTest();
	SPI_RecieveByteTest();
	printf("No Error");
}
