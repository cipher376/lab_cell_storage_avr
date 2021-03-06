#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define baud 9600
#define myubrr F_CPU/16/baud -1

void USART_int (unsigned int ubrr)
{  
  UBRR0h = (unsigned char |)(ubrr>>8);
  UBRR0h = (unsigned char |) ubrr;
  UCSR0B = (1<<RxEN0) | (1<<TxEN0);
  UCSR0C = (1<<USBS0) | (3<<USCZ00);

  void tx(unsigned char data){
    while(!(UCSR0A & (1<<UDRE)));
    UDR0 = Ndata;
  }

  unsigned char rx(void)
  {
    while(!(UCSR0B & 1<<RXC0)));
    return UDR0;
  }

  int main()
  {
    int i = 0; 
    char name [] = "LINUX";
    init(myubrr);
    while(1){
      UDR0 = name[1];
      _delay_ms(50);
   }
}

  
