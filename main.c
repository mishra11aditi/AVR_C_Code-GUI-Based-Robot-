//Program to control the robot according to the serial port data received (f, b, l, r, s)
/********************************************************************************
Microcontroller: ATmega-328p
clock: 16mhz
compiler WinAVR-20100110
********************************************************************************

Motors are connected at M0, M1, M2, M3

********************************************************************************/

#include<avr/io.h>
#include <util/delay.h> 
#include "uart.h"

int main(void)
{
	unsigned char data;
	DDRB=0x3c;					//Data direction for motor
	uart_init();				//Initialization of UART
	_delay_ms(100);
	
 while(1)
  {
	data=uart_read();			//read a character from UART
	
	uart_char(data);			//show the key pressed on hyper terminal
	uart_char('\n');			//new line
	uart_char(13);				//carriage return
	
	switch (data)
	 {
	  case 'f':					//if received f
	   PORTB=0x14;				//move forward
	   break; 
	  case 'b':					//if received b
	   PORTB=0x28;				//move backward
	   break; 
	  case 'l':					//if received l
	   PORTB=0x04;				//move towards left
	   break; 					
	  case 'r':					//if received r
	   PORTB=0x10;				//move towards right
	   break;  
	  case 's':					//if received s
	   PORTB=0x00;				//stop the robot
	   break;  
  	 }
	
  }
  
}