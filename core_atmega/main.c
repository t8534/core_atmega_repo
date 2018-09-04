/*
 * core_atmega.c
 *
 * Created: 2018-09-01 09:37:13
 * Author : arek
 */ 

#include <avr/io.h>
#include "debug.h"

//#define F_CPU 8000000UL  // set in the project properties
#include "util/delay.h"
#include "HD44780.h"


static uint8_t buff_txt[15] = {'a', 'r', 'e', 'k'};

int main(void)
{
	
	// Debug pin init
	DEBUG0_PIN_CONFIG;
	//DEBUG1_PIN_CONFIG;
	//DEBUG2_PIN_CONFIG;

	_delay_ms(100);		// Wait for stable power

	HD44780_init();
	HD44780_on();
	HD44780_clear();
	
    while (1) 
    {
		
		DEBUG0_PIN_SET;
		_delay_ms(100);
		DEBUG0_PIN_RESET;
		_delay_ms(100);
		
		HD44780_clear();
		HD44780_puts(buff_txt);
    }
}

