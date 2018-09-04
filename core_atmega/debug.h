/*
 * debug.h
 *
 * Created: 2018-09-04 10:58:40
 *  Author: arek
 */ 


#ifndef DEBUG_H_
#define DEBUG_H_

// Debug pins

// DEBUG PIN 0
#define DEBUG0_PIN_CONFIG	DDRB |=  (1 << PB1)
#define DEBUG0_PIN_SET		PORTB |= (1 << PB1)
#define DEBUG0_PIN_RESET	PORTB &= ~(1 << PB1)
/*
// DEBUG PIN 1
#define DEBUG1_PIN_CONFIG	DDRD |=  (1 << PD1)
#define DEBUG1_PIN_SET		PORTD |= (1 << PD1)
#define DEBUG1_PIN_RESET	PORTD &= ~(1 << PD1)

// DEBUG PIN 2
#define DEBUG2_PIN_CONFIG	DDRD |=  (1 << PD2)
#define DEBUG2_PIN_SET		PORTD |= (1 << PD2)
#define DEBUG2_PIN_RESET	PORTD &= ~(1 << PD2)
*/




#endif /* DEBUG_H_ */