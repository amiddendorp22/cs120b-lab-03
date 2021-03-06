/*	Author: amidd001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    unsigned char tmpA;
    unsigned char tmpC;
    while (1) {
	tmpA = PINA & 0x0F; //grabs the last 4 pins of PINA
	
	if(tmpA <= 0x04)
	{
		tmpC = 0x40;
		if(tmpA == 0x00)
		{
			tmpC = 0x40;//just the 0x40
		}
		else if(tmpA == 0x01 || tmpA == 0x02)
		{
			tmpC = 0x60;  
		}
		else if(tmpA == 0x03 || tmpA == 0x04)
		{
			tmpC = 0x70;
		}
	}
	if(tmpA == 0x05 || tmpA == 0x06)
	{
		tmpC = 0x38;
	}
	if(tmpA == 0x07 || tmpA == 0x08 || tmpA == 0x09)
	{
		tmpC = 0x3C;
	}
	if(tmpA == 0x0A || tmpA == 0x0B || tmpA == 0x0C)
	{
		tmpC = 0x3E;
	}
	if(tmpA == 0x0D || tmpA == 0x0E || tmpA == 0x0F)
	{
		tmpC = 0x1F;
	}
	PORTC = tmpC;
    }
    return 1;
}
