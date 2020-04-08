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
//unsigned char GetBit(unsigned char x, unsigned char k) {
//	return ((x & (0x01 << k)) != 0);
//}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
	//unsigned char tmpC = 0x00; // Temporary variable to hold the value of C
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A

	unsigned char cntAvail = 0x00;	//Count of number of FREE spaces in binary 
	
	while(1) {
		//read input
		tmpA = PINA;
		
		//counts number of free spaces in A 
		cntAvail = ((tmpA & 0x08) >> 3) + ((tmpA & 0x04) >> 2) + ((tmpA & 0x02) >> 1) +	((tmpA & 0x01)); //3, 2, 1, 0
		
		PORTC = cntAvail;		
	}
	//tmpA = PINA & 0x0F;
	/*
	while(1) {
		// 1) Read input
		//tmpA = PINA & 0x0F; 	//Selects PA3 - PA0
		for (i = 0; i < 8; i++) { //if 1, increase count, does it 4 times
			if( GetBit(tmpA, i) ) {
				cntavail++;	
			}
		}
		printf("%d\n", cntavail); 	//TEST
		// 2) Perform computation 

		//tmpA = (tmpA & 0xF0); //clears 
		
		// 3 write output
		//tmpC = cntavail; //added
		//PORTC = tmpC; //added 
		PORTC = cntavail;
	} */	
	return 0;
}
