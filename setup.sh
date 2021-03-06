#!/bin/bash


#Remove previously compiled files
rm *.elf*.hex*.o
#compile the program

avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o $1.o $1.c
#read

#create the elf file
avr-gcc -mmcu=atmega328p $1.o -o $1.elf
#read
#create the hex file from the elf
avr-objcopy -O ihex -R .eeprom $1.elf $1.hex
#Burn to rom
avrdude -v -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:$1.hex
