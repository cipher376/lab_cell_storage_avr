#ifndef F_CPU
#define F_CPU 16000000UL // or whatever may be your frequency
#endif
 
#include <avr/io.h>
#include <util/delay.h>                // for _delay_ms()
 
int main(void)
{
    DDRD = 0xff;                       // initialize port C
    while(1)
    {
        // LED on
        PORTD = 0xff;            // PC0 = High = Vcc
        _delay_ms(500);                // wait 500 milliseconds
 
        //LED off
        PORTD = 0x00;            // PC0 = Low = 0v
        _delay_ms(500);                // wait 500 milliseconds
    }
}
