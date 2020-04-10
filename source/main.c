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

	unsigned char largerVal, smallerVal; //Used for the step when subtracting A and C

	unsigned short sumWeight; //Used to get the sum of a b and c  

	//unsigned char cntAvail;	//Count of number of FREE spaces in binary 	

	while(1) {
		tmpA = PINA;
		tmpB = PINB;
		tmpC = PINC;

		sumWeight = tmpA + tmpB + tmpC; 

		//printf("%d \n", sumABC); //test print
		//If the cart's total weight exceeds 140 kg, PD0 = 1;
		if ( sumWeight > 140) {
			tmpD = tmpD | 0x01;	
		}
		else { 
			tmpD = tmpD & 0xFE;
		}

		
		//Determines if a or C is larger than the other. Avoids negative values. 
		if (tmpA > tmpC) {	//A > C
			largerVal = tmpA;
			smallerVal = tmpC;
		}
		else {		// C > A 
			largerVal = tmpC;	
			smallerVal = tmpA;
		}
		
		//if a - c  > 80, set pd1 to 1	
		if ( (largerVal - smallerVal) > 80 ) {
			tmpD = tmpD | 0x02;
		} 
		else {
			tmpD = tmpD & 0xFD; //1111 1101 	
		}
		
		
		tmpD = 		 ((
		
		//put tmp into D 
		PORTD = tmpD;
	}	
	return 0;
}
