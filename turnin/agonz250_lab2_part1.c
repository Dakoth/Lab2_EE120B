/*	Author: agonz250
 *  Partner(s) Name: 
 *	Lab Section: 028 
 *	Assignment: Lab #2  Exercise #
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
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A

	while(1) {
		// 1) Read input
		tmpA = PINA & 0x03; 	//Selects PA1 and PA0				
		// 2) Perform computation 
		
		if (tmpA == 0x01) { //If PA1 = 0, and PA0 = 1, (ONLY CASE WHERE PB0 = 1)
			tmpB = (tmpB & 0xFE) | 0x01;	//sets tmp to bbbbbbb0
							//clears rightmost 1 bit, then set to 1
		} else {	
			//if (tmpA == 0x00) { 
			//// True if PA1 and PA0 are 0
			//iff PA1 = 1 and PA0 = 0
			//if PA1 = 1 and PA0 = 1 
			tmpB = (tmpB & 0xFE) | 0x00; // Sets tmpB to bbbbbbb0
						     // (clear rightmost bit, then set to 0)	
		}
		// 3 write output
		PORTB = tmpB;
	}
	return 0;
}		//test	
