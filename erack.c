#ifndef F_CPU
#define F_CPU 16000000UL // 
#endif
 
#include <avr/io.h>
#include <util/delay.h> 
             

#define DECK1OPEN (PORTD|=(1<<2)) //PD2 for deck1
#define DECK2OPEN (PORTD|=(1<<3)) //PD3 for deck2

#define DECK1CLOSE (PORTD&=~(1<<2)) //PD2 for deck1
#define DECK2CLOSE (PORTD&=~(1<<3)) //PD3 for deck2

//Led configurations
#define POWERONLED (PORTD|=(1<<4)) //Power on led;
#define RXTXLED    (PORTD|=(1<<5)) //Transmiting receiveing led.



//Array of ports in deck
/*
  deck1[0]
y
  ****
  ****
  ****
       x
*/

unsigned char deck1Ports[12];
unsigned char deck2Ports[12];
unsigned char cmd[2][30];

unsigned char i,j;

void setup(){
  //Using port D as the output
  DDRD = 0xff;
}

void USART_init(unsigned int ubrr){
  UBRR 0H =(unsigned char)(ubrr>>8);
  UBRR 0L =(unsigned char) ubrr>
  UCSR 0B =(1<<RXEN0)|(1<<TXEN0); 
  UCSR 0C = (1<<USBS0)|(3<<UCSZ00);
}


void USART_tx(unsigned char data){
  while(!(UCSR0A&(1<<UDRE)));
    UDR0=data;
}

unsigned char USART_rx(void){
  while(!(UCSR0B&(1<<RXC0)));
  return UDR0;
}

void execute(unsigned int cmd){
   
}
int main(void)
{
    PORTD = 0x00;

    while(1)
    {
       DECK1CLOSE;
        _delay_ms(500);
       DECK1OPEN;
        _delay_ms(500);
    }
}


