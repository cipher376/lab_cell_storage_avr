#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define OUTPUT PD7
#define UP PD6
#define DOWN PD5

#define input(pin) if(!(PIND&(1<<pin))==0)

void setup(){
DDRD |=(1<<OUTPUT);
PORTD |=(1<<OUTPUT);
PIND |=(1<<UP)|(1<<DOWN);

TCCR0A|=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00);//COMPARE OUTPUT MOD, WAVE GENERATION MOD = FAST PWM
TCCR0B |=(CS00);//NO PRESCALING

}

ISR(TIMER0_COMPA_vect){
  PORTD|=(1<<OUTPUT);
}


int main(){
  setup();
  int i=0;
  int dir=0;
  OCROA = 128;

  while(1){
    input(UP){
      i++;
    }else
    input(DOWN){
       i--;
    }
    OCROA=i;
   }
}
