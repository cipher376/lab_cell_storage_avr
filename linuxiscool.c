#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR ((F_CPU/16/BAUD)-1)


#include <avr/io.h>
#include <util/delay.h>



void setup(){
//pin 1,3 as input
DDRB=0x00;

// pin 2 as input
DDRC=0x00;

//clear port registers(reset)
PINB=0;
PINC=0;
}

void USART_init(unsigned int ubrr){

UBRR0H =(unsigned char)(ubrr>>8);//initialize upper half the baud rate register
UBRR0L =(unsigned char) ubrr;//initialize lower half the baud rate register
UCSR0B =(1<<TXEN0); //set transmitter
UCSR0C = (1<<USBS0)|(3<<UCSZ00); //num of stop bit 1, 8bit data frame

}

int i=0;
char msg[20];




void printmsg(unsigned char msg[],int msglen){
i=0;
while(i<=msglen){
   //UDR0 = msg[i]; //send data
   while(!(UCSR0A&(1<<UDRE0)));
    UCSR0B &= ~(1<<TXC0);
   if(msg[i] & 0x0100)
    UCSR0B |=(1<<TXC0);

    UDR0 = msg[i]; //send data
      i++;
  }
}


int main(){

setup();
USART_init(MYUBRR);

while(1){

//printmsg("wait..\n",6);

//_delay_ms(2000);
if(!(PINB&(1<<PINB1))==0){
printmsg("LINUX ",6);
 
}
if(!(PINB&(1<<PINB2))==0){

printmsg(" cool ",6);
}
   
if(!(PINC&(1<<PINC3))==0){

printmsg(" is \n",4);
}

}

}


