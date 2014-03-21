#include <avr/io.h>
#include <avr/interrupt.h>

// initialize timer, interrupt and variable
void timer1_init()
{
    // set up timer with prescaler = 64 and CTC mode
   	TCCR1B |= (1 << WGM12)|(1 << CS11)|(1 << CS10);
 
    // initialize counter
    TCNT1 = 0;

 
    // initialize compare value
    OCR1A = 2500; // 1 ms = 16.000Hz / 64 = 250 cycles
 
    // enable compare interrupt
    TIMSK |= (1 << OCIE1A);
 
    // enable global interrupts
    sei();
}
 
// this ISR is fired whenever a match occurs
ISR (TIMER1_COMPA_vect)
{
    // add action here
	DDRA= (1 << PA1);
	PORTA = (1 << PA1);
	
}
 
int main(void)
{
    // initialize timer
    timer1_init();
 
    // loop forever
    while(1)
    {
	
    }
}
