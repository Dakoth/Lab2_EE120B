/*	Author: agonz250
 *  Partner(s) Name: 
 *	Lab Section: 028 
 *	Assignment: Lab #2  Exercise # 4
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
	DDRB = 0x00; PORTB = 0XFF; //Sets port B to input 
	DDRC = 0x00; PORTC = 0xFF; //Set's Port C t0 input 

	DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs, initialize to 0s

	unsigned char tmpA = 0; // Temporary variable to hold the value of A
	unsigned char tmpB = 0;
	unsigned char tmpC = 0;
	unsigned char tmpD = 0x00;

	unsigned short sumABC = 0; //Used to get the sum of a b and c  

	//unsigned char cntAvail;	//Count of number of FREE spaces in binary 	

	while(1) {
		tmpA = PINA;
		tmpB = PINB;
		tmpC = PINC;

		sumABC = tmpA + tmpB + tmpC; 

		//If the cart's total weight exceeds 140 kg, PD0 = 1;
		if (sumABC > 140) {
			tmpD = tmpD | 0x01;	
		}

		PORTD = tmpD;
	}	
	return 0;
}
