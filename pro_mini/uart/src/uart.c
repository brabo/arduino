#include "uart.h"

void uart_init(){
	cli();
	// Set baud rate
	UBRR0L = BAUD_PRESCALE;// Load lower 8-bits into the low byte of the UBRR register
	UBRR0H = (BAUD_PRESCALE >> 8); 
	/* Load upper 8-bits into the high byte of the UBRR register
	Default frame format is 8 data bits, no parity, 1 stop bit
	to change use UCSRC, see AVR datasheet*/ 

	// Enable receiver and transmitter and receive complete interrupt 
	UCSR0B = ((1<<TXEN0)|(1<<RXEN0) | (1<<RXCIE0));
	//sei();
}

void uart_sendbyte(uint8_t byte){

	// Wait until last byte has been transmitted
	while((UCSR0A &(1<<UDRE0)) == 0);

	// Transmit data
	UDR0 = byte;
}

// not being used but here for completeness
// Wait until a byte has been received and return received data 
uint8_t uart_getbyte(void){
	while((UCSR0A &(1<<RXC0)) == 0);
	return UDR0;
}

int uart_send(uint8_t *string) {
    while( *string != '\0' ) {
    	uart_sendbyte(*string++);
    }
    uart_sendbyte('\0');
    return 0;
}