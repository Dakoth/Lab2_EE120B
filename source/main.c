/*	Author: agonz250
 *  Partner(s) Name: 
 *	Lab Section: 028 
 *	Assignment: Lab #2  Exercise # 2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif	

//Used to get value at specified bit value 
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
	unsigned char tmpC = 0x00; // Temporary variable to hold the value of C
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A

	unsigned char cntavail = 0;	//Count of number of spaces in binary 
	//tmpA = PINA & 0x0F;

	while(1) {
		// 1) Read input
		//tmpA = PINA & 0x0F; 	//Selects PA3 - PA0
		for (int i = 0; i < 4; i++) { //if 1, increase count, does it 4 times
			if(GetBit(A, i)) {
				cntavail++;	
			}
		}
		// 2) Perform computation 

		//tmpA = (tmpA & 0xF0); //clears 
		
		// 3 write output
		PORTC = cntavail;
	}
	return 0;
}
