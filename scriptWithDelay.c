#include <util/delay.h>
#include <avr/io.h>

int main(void){
  void delay_ms(int d)
  {
    _delay_ms(d);
  }
  DDRB = 0xFF;
  while(1){
    delay_ms(10);
    PORTB = 0X55;
    delay_ms(10);
  }
} 
