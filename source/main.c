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
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    unsigned char tmpA;
    unsigned char tmpB;
    unsigned char i;
    unsigned char total1s = 0;
    unsigned char temp;
    while (1) {
	total1s = 0;
	tmpA = PINA;
	tmpB = PINB;
	
	//Counting 1's on A
	temp = tmpA;
	for(i = 0; i < 8; i++)
	{
		if((temp & 0x01) == 0x01)
		{
			total1s++;
		}
		temp = temp >> 1;
	}
	temp = tmpB;
	for(i = 0; i < 8; i++)
	{
		if((temp & 0x01) == 0x01)
		{
			total1s++;
		}
		temp = temp >> 1;
	}

	PORTC = total1s;

	
    }
    return 1;
}
