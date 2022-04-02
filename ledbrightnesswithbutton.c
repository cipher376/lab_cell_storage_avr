#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

void setup(){
    DDRD = 0;
    DDRB = 0xFF;
    //puls width modulation fastmode, clear on compare
    TCCR0 |=(1<<WGM00)|(1<<WGM01)|(1<<COM00)|(1<<COM01)|(1<<CS00);
    OCR0 = 0;


}


int main(void)
{
   setup();

    while(1)
    {
        if (!(PIND&(1<<PIND2)==0))
        {
            if (OCR0<255)
            {
                OCR0++;    
            }        
            _delay_ms(50);
            
        }
        if (!(PIND&(1<<PIND3)==0))
        {
            if (OCR0>0)
            {
                OCR0--;
            }        
            _delay_ms(50);
        }
    }
}


