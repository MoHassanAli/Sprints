#ifndef    _DIO_PRIVATE_H_
#define    _DIO_PRIVATE_H_

#define DDRA *((uint8_t*)0x3A)
#define DDRB *((uint8_t*)0x37)
#define DDRC *((uint8_t*)0x34)
#define DDRD *((uint8_t*)0x31)

#define PORTA *((uint8_t*)0x3B)
#define PORTB *((uint8_t*)0x38)
#define PORTC *((uint8_t*)0x35)
#define PORTD *((uint8_t*)0x32)

#define PINA *((volatile uint8_t*)0x39)
#define PINB *((volatile uint8_t*)0x36)
#define PINC *((volatile uint8_t*)0x33)
#define PIND *((volatile uint8_t*)0x30)


#define PortA  0
#define PortB  1
#define PortC  2
#define PortD  3

#define OUTPUT       1
#define INPUT        0

#define HIGH         1
#define LOW          0







#endif
