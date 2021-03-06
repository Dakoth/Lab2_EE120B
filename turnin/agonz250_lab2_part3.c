/*	Author: agonz250
 *  Partner(s) Name: 
 *	Lab Section: 028 
 *	Assignment: Lab #2  Exercise # 3
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
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s

	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A 
	unsigned char cntAvail;	//Count of number of FREE spaces in binary 	

	while(1) {
		//read input
		tmpA = PINA;

		tmpA = ~tmpA; 	//invert the bits to show the correct values when added 	

		//counts number of free spaces in A 
		cntAvail = ((tmpA & 0x08) >> 3) + ((tmpA & 0x04) >> 2) + ((tmpA & 0x02) >> 1) +	((tmpA & 0x01)); //3, 2, 1, 0	
		PORTC = cntAvail;		
		
		//If the lot is full, then set C7 = 1
		if (cntAvail == 0x00) {
			PORTC = cntAvail | 0x80;
		}
	}	
	return 0;
}
