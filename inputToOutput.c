//take input from portB and send it to portC

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

void config(){


   //configuring ports
   DDRB|= 0xFF;//setting portB as output
   DDRC|= 0x00; //setting portC as input
   PINC |= 0X00; //Clear portC
  
}

int main(void){
  config();

  while(1){
     //take input from portC and send it to portB
     PORTB = PINC;
     }
}

