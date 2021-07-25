
#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define PRESCALER_TWO		0
#define PRESCALER_EIGHT		1

#define INTERNAL_AVCC		0
#define INTERNAL_256		1
#define EXTERNAL_AREF		2

#define	RIGHT_ADJ			0
#define	LEFT_ADJ			1



#define			ADMUX 			*((volatile uint8_t*)0x27)
#define 		ADCSRA 			*((volatile uint8_t*)0x26)
#define			ADC				*((volatile u16*)0x24)
#define 		SFIOR			*((volatile uint8_t*)0x50)
#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
