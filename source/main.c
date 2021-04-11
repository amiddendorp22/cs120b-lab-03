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
    DDRB = 0xFE; PORTB = 0xFE; //configures all but the last bit as output.
    DDRD = 0x00; PORTD = 0xFF;
    /* Insert your solution below */
    unsigned char tmpD;
    unsigned char tmpB;

    while (1) {
	tmpD = PIND;
	tmpB = PINB;
	
	if(tmpD >= 0x46)
	{
		tmpB = 0x02;
	}
	if(tmpD == 0x45)
	{
		if(tmpB == 0x01)
		{
			tmpB = 0x02;
		}
		else
		{
			tmpB = 0x04;
		}
	}
	else if(tmpD < 0x45)
	{
		if( (tmpD + tmpB) > 0x05)
		{
			tmpB = 0x04;
		}	
		else
		{
			tmpB = 0x00;
		}
	}	
	PORTB = tmpB;
    }
    return 1;
}
