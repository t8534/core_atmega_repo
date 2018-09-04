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


#define USART_BAUDRATE 9600
#define UBRR_VALUE (((F_CPU/(USART_BAUDRATE*16UL)))-1)


void serial_init() {
	
	//power_usart0_enable();
	
	/*
	// initialize USART (must call this before using it)
	//UBRR0=UBRR_VALUE; // set baud rate
	UBRR0=51;
	UCSR0A=0x00;
	UCSR0B|=(1<<TXEN0); //enable transmission only
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00); // no parity, 1 stop bit, 8-bit data
	*/
	
	
	
	// configure ports double mode
	//UCSR0A = _BV(U2X0);
	UCSR0A=0x00;

	// configure the ports speed 9600
	UBRR0H = 0x00;
	UBRR0L = 51;

	// asynchronous, 8N1 mode
	UCSR0C |= 0x06;
	
	// rx/tx enable
	//UCSR0B |= _BV(RXEN0);
	UCSR0B |= _BV(TXEN0);
	
	
}

void serial_send(unsigned char data){
	// send a single character via USART
	while(!(UCSR0A&(1<<UDRE0))){}; //wait while previous byte is completed
	UDR0 = data; // Transmit data
}

void serial_break(){
	serial_send(10); // new line
	serial_send(13); // carriage return
}
void serial_comma(){
	serial_send(','); // comma
	serial_send(' '); // space
}

void serial_number(long val){
	// send a number as ASCII text
	char preVal=' ';
	long divby=100000000; // change by dataType
	while (divby>=1){
		serial_send('0'+val/divby);
		val-=(val/divby)*divby;
		divby/=10;
	}
}



int main(void)
{
	
	// Debug pin init
	//DEBUG0_PIN_CONFIG;
	//DEBUG1_PIN_CONFIG;
	//DEBUG2_PIN_CONFIG;

	/*
    while (1) 
    {
		DEBUG0_PIN_SET;
		_delay_ms(100);
		DEBUG0_PIN_RESET;
		_delay_ms(100);
    }
	*/
	
	serial_init();
	int i;
	for(;;) {

		//for(i='A';i<='Z';i++){serial_send(i);} // send the alphabet
		//serial_break();
		//
		//serial_number(10140000+123); // send a big number
		//serial_break();
			
		serial_send(0x62);  //B 0x42
			
		_delay_ms(1000); // wait a while
	}

	
}

