#include <avr/io.h>

int main(void){

  unsigned char myList[] = "0123456789";
  unsigned char z;
  DDRB = 0xFF;
  for(z=0;z<10;z++)
    PORTB = myList[z];
  while(1);
  return 0;
}
