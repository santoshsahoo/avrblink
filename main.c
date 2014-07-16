#include <avr/io.h>
#include <util/delay.h>

#define MIN 10
#define MAX 500

int wait=30;
int diff=10;

int main(void){
    
	DDRB = 0xff;
	PORTB = 0;
	while(1){
	
    wait+=diff;
    
    if(wait>MAX)
      diff = -10;
    if(wait<MIN)
      diff=10;
	
		PORTB = 0b00000010;
		_delay_ms(wait);
		PORTB = 0b00000001;
		_delay_ms(wait);
	}
	return 0;
}