/*	A://github.com/fernando3197/Lab4_sm.gitthor: fgonz059
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab # 4 Exercise # 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States { Start, S0, S1, S2, S3 } state;
unsigned char tempA;
unsigned char tempC;

void Tick(){
	unsigned char A0 = PINA & 0x01;
	unsigned char A1 = PINA & 0x02;
	switch (state){
		case Start:
			state = S0;
			break;
		case S0:
			if (A1 && A0) state = S0;
			else if (!A1 && A0) {state = S1; if (tempC < 9) tempC = tempC + 1; }
			else if (!A1 && !A0) {state = S3; tempC = 0;}
			else if (A1 && !A0) {state = S2; if (B > 0) tempC = tempC - 1; } 
			break;
		case S1:
			state = (!A1 && A0) ? S1 : S0;
			break;
		case S2:
			state = (A1 && !A0) ? S2 : S0;
			break;
		case S3:
			state = (!A1 && !A0) ? S3 : S0;
			break;
		default:
			break;			
	} // Transitions
	
	switch (state){
		case S0:
			break;
		case S1:
			break;
		case S2:
			break;
		case S3:
			break;
		default:
			break;
	} // Values
}

int main(void) {
    /* Insert DDR and PORT initializations */
	PINA = 0x00; PORTA = 0xFF;
	PINC = 0xFF; PORTC = 0x00;
	
 	B = 0x07; // Initialize outputs
	state = Start;
	
	while(1){
		tempA = PINA;
		Tick();
		PORTC = tempC;
	}          
 }
    return 1;
}
