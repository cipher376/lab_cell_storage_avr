#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR F_CPU/16/baud-1

#include <avr/io.h>
#include <util/delay.h>


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

 int main(){

	int i=0;
	char name[]="LINUX"	
	usart_init(myubrr);
while(1){

for(;i<5;i++){
tx(name[i]);
delay_ms(200);
}
}
	




}
