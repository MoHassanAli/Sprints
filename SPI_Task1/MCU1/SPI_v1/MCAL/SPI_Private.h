/*
 * SPI_Private.h
 *
 * Created: 7/14/2021 9:19:05 PM
 *  Author: Mohamed
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPDR	*((volatile uint8_t*) 0x2F)
#define SPSR	*((volatile uint8_t*) 0x2E)
#define SPCR	*((volatile uint8_t*) 0x2D)
#define PB4    4
#define PB5    5
#define PB6    6
#define PB7    7

/*************************************/
#define MSTR	4
#define SPE		6
#define SPIF	7




#endif /* SPI_PRIVATE_H_ */