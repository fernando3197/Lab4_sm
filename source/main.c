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
	
	unsigned char A0 = PINA & 0x01;
	switch(state){
		case Start:
			state = S0;
			break;
		case S0:
			state = A0 ? S1 : S0;
			break;
		case S1:
			state = !A0 ? S2 : S1;
			break;
		case S2:
			state = A0 ? S3 : S2;
			break;
		case S3:
			state = !A0 ? S0 : S3;
			break;
		default:
			break;			
		}			
	} // Transitions
	
	switch(state){
		case S0:
			break;
		case S1:
			tempB = 0x02;
			break;
		case S2:
			break;
		case S3:
			B = 0x01;
			break;
		default:
			break;
		
	} // State actions
}

int main(void) {
    /* Insert DDR and PORT initializations */
	PINA = 0x00; PORTA = 0xFF;
	PINB = 0xFF; PORTB = 0x00;
	
 	B = 0x01; // Initialize outputs
	state = Start;
	
	while(1){
		tempA = PORTA;
		Tick();
	}       
    }
    return 1;
}
