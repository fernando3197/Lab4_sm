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
unsigned char tempB;

void Tick(){
		
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
