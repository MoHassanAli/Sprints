/* Auther 		: 	Mohamed Hassan   */
/* Date		 	: 	7/7/2021         */
/* Version 		: 	V1               */

#ifndef LIBERARY_AVR32_REG_H_
#define LIBERARY_AVR32_REG_H_

#define NULL  '\0'

#define HIGH	1
#define LOW		0

#define OUTPUT	1
#define INPUT	0

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7


/************************************************************/

#define SREG 		*((volatile u8*) 0x5F)

#define SPH 		*((volatile u8*) 0x5E)
#define SPL 		*((volatile u8*) 0x5D)

#define OCR0		*((volatile u8*) 0x5C)

#define GICR 		*((volatile u8*) 0x5B)
#define GIFR 		*((volatile u8*) 0x5A)

#define TIMSK 		*((volatile u8*) 0x59)
#define TIFR 		*((volatile u8*) 0x58)

#define SPMCR 		*((volatile u8*) 0x57)
#define TWCR 		*((volatile u8*) 0x56)

#define MCUCR  		*((volatile u8*) 0x55)
#define MCUCSR 		*((volatile u8*) 0x54)

#define TCCR0 		*((volatile u8*) 0x53)
#define TCNT0 		*((volatile u8*) 0x52)

#define OSCCAL	 	*((volatile u8*) 0x51) /* Oscillator Calibration Register */
#define OCDR 		*((volatile u8*) 0x51)	/* On-Chip Debug Register */

#define SFIOR 		*((volatile u8*) 0x50)

#define TCCR1A 		*((volatile u8*) 0x4F)
#define TCCR1B 		*((volatile u8*) 0x4E)

#define TCNT1H 		*((volatile u8*) 0x4D)
#define TCNT1L 		*((volatile u8*) 0x4C)
#define TCNT1 		*((volatile u16*) 0x4C)  /* For 2 bytes */

#define OCR1AH 		*((volatile u8*) 0x4B)
#define OCR1AL 		*((volatile u8*) 0x4A)
#define OCR1A 		*((volatile u16*) 0x4A)  /* For 2 bytes */

#define OCR1BH 		*((volatile u8*) 0x49)
#define OCR1BL 		*((volatile u8*) 0x48)
#define OCR1B 		*((volatile u16*) 0x48)  /* For 2 bytes */

#define ICR1H 		*((volatile u8*) 0x47)
#define ICR1L	 	*((volatile u8*) 0x46)
#define ICR1	 	*((volatile u16*) 0x46)  /* For 2 bytes */

#define TCCR2 		*((volatile u8*) 0x45)
#define TCNT2 		*((volatile u8*) 0x44)

#define OCR2 		*((volatile u8*) 0x43)

#define ASSR 		*((volatile u8*) 0x42)
#define WDTCR 		*((volatile u8*) 0x41)

#define UBRRH 		*((volatile u8*) 0x40)  // UART
#define UCSRC 		*((volatile u8*) 0x40)  // UART

#define EEARH	 	*((volatile u8*) 0x3F)
#define EEARL 		*((volatile u8*) 0x3E)
#define EEDR 		*((volatile u8*) 0x3D)
#define EECR 		*((volatile u8*) 0x3C)

#define PORTA 		*((u8 *) 0x3B)
#define DDRA  		*((u8 *) 0x3A)
#define PINA  		*((volatile u8*) 0x39)
#define PORTB 		*((u8 *) 0x38)
#define DDRB  		*((u8 *) 0x37)
#define PINB  		*((volatile u8*) 0x36)
#define PORTC 		*((u8 *) 0x35)
#define DDRC  		*((u8 *) 0x34)
#define PINC  		*((volatile u8*) 0x33)
#define PORTD 		*((u8 *) 0x32)
#define DDRD  		*((u8 *) 0x31)
#define PIND  		*((volatile u8*) 0x30)

#define SPDR 		*((volatile u8*) 0x2F)
#define SPSR	 	*((volatile u8*) 0x2E)
#define SPCR	 	*((volatile u8*) 0x2D)

#define UDR 		*((volatile u8*) 0x2C)  // UART

#define UCSRA	 	*((volatile u8*) 0x2B)  // UART
#define UCSRB 		*((volatile u8*) 0x2A)  // UART
#define UBRRL 		*((volatile u8*) 0x29)  // UART

#define ACSR 		*((volatile u8*) 0x28)
#define ADMUX		*((volatile u8*) 0x27)
#define ADCSRA		*((volatile u8*) 0x26)

#define ADCH		*((volatile u8*) 0x25)
#define ADCL		*((volatile u8*) 0x24)
#define ADC			*((volatile u16*) 0x24)  /* For 2 bytes */

#define TWDR 		*((volatile u8*) 0x23)
#define TWAR 		*((volatile u8*) 0x22)
#define TWSR 		*((volatile u8*) 0x21)
#define TWBR 		*((volatile u8*) 0x20)



#endif /* LIBERARY_AVR32_REG_H_ */
