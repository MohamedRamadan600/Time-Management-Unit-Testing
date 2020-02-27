/*
 * registers.h
 *
 *  Created on: Oct 21, 2019
 *      Author: M_Ramadan
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "std_types.h"

/*
 * General Registers
 */
#define MCUCR			*((volatile unsigned char*)(0x55))
#define MCUCSR			*((volatile unsigned char*)(0x54))
#define GICR			*((volatile unsigned char*)(0x5B))
#define GIFR			*((volatile unsigned char*)(0x5A))

/*
 * PORTx registers
 */

#define PORTA_DATA		*((volatile unsigned char*)(0x3B))          
#define PORTA_DIR  		*((volatile unsigned char*)(0x3A))
#define PORTA_PIN		*((volatile unsigned char*)(0x39))

#define PORTB_DATA 		*((volatile unsigned char*)(0x38))
#define PORTB_DIR  		*((volatile unsigned char*)(0x37))
#define PORTB_PIN		*((volatile unsigned char*)(0x36))

#define PORTC_DATA 		*((volatile unsigned char*)(0x35))
#define PORTC_DIR  		*((volatile unsigned char*)(0x34))
#define PORTC_PIN		*((volatile unsigned char*)(0x33))


#define PORTD_DATA 		*((volatile unsigned char*)(0x32))
#define PORTD_DIR  		*((volatile unsigned char*)(0x31))
#define PORTD_PIN		*((volatile unsigned char*)(0x30))


/*
 * General Timer registers
 */
#define TIMSK			*((volatile unsigned char*)(0x59))
#define TIFR			*((volatile unsigned char*)(0x58))

/*
 * Status registers
 */

#define SREG			*((volatile unsigned char*)(0x5F))

/*
 * Timer 0 Registers
 */

#define TCCR0			*((volatile unsigned char*)(0x53))
#define TCNT0			*((volatile unsigned char*)(0x52))
#define OCR0			*((volatile unsigned char*)(0x5C))


/*
 * Timer 1 Registers
 */

#define TCCR1A			*((volatile unsigned char*)(0x4F))
#define TCCR1B			*((volatile unsigned char*)(0x4E))
#define TCCR1			*((volatile unsigned short*)(0x4E))
#define TCNT1H			*((volatile unsigned char*)(0x4D))
#define TCNT1L			*((volatile unsigned char*)(0x4C))
#define TCNT1			*((volatile unsigned short*)(0x4C))
#define OCR1AH			*((volatile unsigned char*)(0x4B))
#define OCR1AL			*((volatile unsigned char*)(0x4A))
#define OCR1A			*((volatile unsigned short*)(0x4A))
#define OCR1BH			*((volatile unsigned char*)(0x49))
#define OCR1BL			*((volatile unsigned char*)(0x48))
#define OCR1B			*((volatile unsigned short*)(0x48))
#define ICR1H			*((volatile unsigned char*)(0x47))
#define ICR1L			*((volatile unsigned char*)(0x46))
#define ICR1			*((volatile unsigned short*)(0x46))


/*
 * Timer 2 Registers
 */
#define TCCR2		*((volatile unsigned char*)(0x45))
#define TCNT2		*((volatile unsigned char*)(0x44))
#define OCR2		*((volatile unsigned char*)(0x43))
#define ASSR		*((volatile unsigned char*)(0x42))








#endif /* REGISTERS_H_ */
