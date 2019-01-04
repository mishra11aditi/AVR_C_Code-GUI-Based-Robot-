/*uart.h
*******************************************************************************************
Description:

	This header file enables uart communication feature between two devices.
	Include this header file in your C code. 
	Call the uart_init() function before calling any other functions to initialize the uart.
	
Functions:

	uart_init();	Call this function before calling any other functions to initialize 
					the uart communication.
	uart_char();  	This function will transmit a single character on the UART.
					For e.g. uart_char(0x61); will display A. 
					Again uart_char('b'); will display b.
	uart_string();	This function will display a string. 
					An e.g. of this would be like uart_string("This is AVR");
	uart_num();		This will show a 3-digit decimal value on the display
					For e.g. uart_num(35); will displkay 035
	uart_read();	This will show a 3-digit decimal value on the Display. 
					For e.g. if we give uart_read(x); then x value will be displayed.

*******************************************************************************************/
#include<util/delay.h>
#ifndef _UART_H_
#define _UART_H_

void uart_init()
{
	UCSR0A = 0x00;
	UCSR0B = 0x18;
	UCSR0C = 0x86;
	UBRR0H = 0x00;
	UBRR0L = 0x67;
	_delay_ms(1);
}

void uart_char(unsigned char uchar)
{
	UDR0=uchar;
	while( (UCSR0A&0x40)==0);
	_delay_ms(1);
}
 
void uart_string(const unsigned char *ustring)
{
	while ( *ustring )
	{
		UDR0=*ustring++;
		while( (UCSR0A&0x40)==0);
		_delay_ms(1);
	}
}

void uart_num(unsigned char num)
{
    unsigned char H=0,T=0,O=0;
	H=num/100;
	T=(num - (H*100))/10;
	O=(num - (H*100) - (T*10));
	
	uart_char(H+48);
	uart_char(T+48);
	uart_char(O+48);	
}
 
unsigned char uart_read()
{
	while( (UCSR0A&0x80)==0);
	return UDR0;
}



#endif 
