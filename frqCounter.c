#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define OUTPUT  PD6;
#define OUTPUT1  PD4;
#define UP  PD7;
#define DOWN  PD5;

#define input(pin)if(!(PIND &(1<<pin))==0)

void setup(){
   //Setting port D pin6 and pin4 as outputs
  DDRD = (1<<OUTPUT)|(1<<OUTPUT1);
  PORTD = (1<<OUTPUT)|(1<<OUTPUT1);
  
  //Seting port D pin7 and pin 5 as inputs
  PIND = (1<<UP)|(1<<DOWN);

  //Initializing the timer registers
  TCCR0A = (1<<COM0A1);
  TCCR0A = (1<<WGM01)|(1<<WGM00); //Fast PMW mode set
  TCCR0B = (1<<CS00); //internal clock source
  TIMSK0 = (1<<OCIE0A); //Enabling interrupt

  }

//Interrupt handler
ISR_TIMER0_COMPA(){
  PORTD |=(1<<OUTPUT);  
}   

int main(){
  setup();
  int i=0;
  int dir=0;
  OCR0A = 128;

  while(1){
    input(UP){
      i++;
    }else
    input(DOWN){
      i--;        
    }

   OCR0A =i;
  }
}

