#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define WAIT 100

int main(void){
	DDRB = 0xFF;
	PORTB = 0xF1;
    
    cli();//TIFR |= 0x01;       // clear interrupt flag
	
	
    OCR0A  = 0x70;      // number to count up to (0x70 = 112)
    TCCR0A = 0x02;      // Clear Timer on Compare Match (CTC) mode
    TIMSK = 0x01;       // TC0 compare match A interrupt enable
    TCCR0B = 0x05;      // clock source CLK/1024, start timer
    
    sei();              // global interrupt enable
    
	while(1){}

	return 0;
}

ISR(TIMER0_COMPA_vect)
{
    PORTB ^= 1<<0;
}
