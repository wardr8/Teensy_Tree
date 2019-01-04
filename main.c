/*
Multiplexing code used to light up Teensy_Tree

Robert Ward 12/21/2018
*/

//HIGH: F0, F1, F4, F5, F6, F7, B6
//LOW:  B0, B1, B2, B3, B7, D0, D1

#include "teensy_general.h" 
#include "t_usb.h"

#define spiral_wait 40 //in ms
#define ring_wait 100
int i;

void rings_blink(void){
	//top LED
	PORTF = 0b00100000; PORTB = 0b10000111; PORTD = 0b00000011;
	teensy_wait(ring_wait);
	
	//1st ring
	int i;
	for (i=0; i<=(ring_wait/3); i++){
		PORTF = 0b01010000; PORTB = 0b10000111;	PORTD = 0b00000011;
		teensy_wait(1);
		PORTF = 0b00110000; PORTB = 0b10001011; PORTD = 0b00000011;
		teensy_wait(1);
		PORTF = 0b01100000; PORTB = 0b00001111; PORTD = 0b00000011;
		teensy_wait(1);
	}
	
	//2nd ring
	for (i=0; i<=(ring_wait/5); i++){
		PORTF = 0b00110010; PORTB = 0b10001101; PORTD = 0b00000011;
		teensy_wait(1);
		PORTF = 0b11100000; PORTB = 0b10001111; PORTD = 0b00000010;
		teensy_wait(1);
		PORTF = 0b01000010; PORTB = 0b10001011; PORTD = 0b00000011;
		teensy_wait(1);
		PORTF = 0b10000010; PORTB = 0b10000111; PORTD = 0b00000011;
		teensy_wait(1);
		PORTF = 0b10010000; PORTB = 0b00001111; PORTD = 0b00000011;
		teensy_wait(1);
	}
	
	//outer ring
	for (i=0; i<=(ring_wait/7); i++){
		PORTF = 0b00110011; PORTB = 0b10001110; PORTD = 0b00000011;
		teensy_wait(1);
		PORTF = 0b11100000; PORTB = 0b11001111; PORTD = 0b00000001;
		teensy_wait(1);
		PORTF = 0b01000001; PORTB = 0b10001101; PORTD = 0b00000011;
		teensy_wait(1);
		PORTF = 0b10000001; PORTB = 0b10001011; PORTD = 0b00000011;
		teensy_wait(1);
		PORTF = 0b00000001; PORTB = 0b11000111; PORTD = 0b00000011;
		teensy_wait(1);
		PORTF = 0b00000010; PORTB = 0b01001111; PORTD = 0b00000011;
		teensy_wait(1);
		PORTF = 0b00010000; PORTB = 0b11001111; PORTD = 0b00000010;
		teensy_wait(1);
	}
}


void spiral_blink(void){
	
	//outer ring																			//HIGH, LOW
	PORTF = 0b00100000; PORTB = 0b10001110; PORTD = 0b00000011; teensy_wait(spiral_wait);	//F5, B0
	PORTF = 0b00010000; teensy_wait(spiral_wait);											//F4, B0
	PORTF = 0b00000010; teensy_wait(spiral_wait);											//F1, B0
	PORTF = 0b00000001; teensy_wait(spiral_wait);											//F0, B0
	PORTF = 0b00000001; PORTB = 0b10001101; teensy_wait(spiral_wait);						//F0, B1
	PORTB = 0b10001011; teensy_wait(spiral_wait);											//F0, B2
	PORTB = 0b10000111; teensy_wait(spiral_wait);											//F0, B3
	PORTF = 0b00000010; PORTB = 0b00001111; teensy_wait(spiral_wait);						//F1, B7
	PORTF = 0b00010000; PORTB = 0b10001111; PORTD = 0b00000010; teensy_wait(spiral_wait);	//F4, D0
	PORTF = 0b00100000; PORTD = 0b00000001; teensy_wait(spiral_wait);						//F5, D1
	PORTF = 0b01000000; teensy_wait(spiral_wait);											//F1, D1
	PORTF = 0b10000000; teensy_wait(spiral_wait);											//F7, D1
	PORTF = 0b00000000; PORTB = 0b11001111; teensy_wait(spiral_wait);						//B6, D1
	PORTD = 0b00000010; teensy_wait(spiral_wait);											//B6, D0
	PORTB = 0b01001111; PORTD = 0b00000011; teensy_wait(spiral_wait);						//B6, B7
	PORTB = 0b11000111; teensy_wait(spiral_wait);											//B6, B3
	PORTF = 0b10000000; PORTB = 0b10001011; teensy_wait(spiral_wait);						//F7, B2
	PORTF = 0b01000000; PORTB = 0b10001101; teensy_wait(spiral_wait);						//F6, B1
	
	//2nd ring
	PORTF = 0b00100000; PORTB = 0b10001101; PORTD = 0b00000011; teensy_wait(spiral_wait);	//F5, B1
	PORTF = 0b00010000; teensy_wait(spiral_wait);											//F4, B1
	PORTF = 0b00000010; teensy_wait(spiral_wait);											//F1, B1
	PORTB = 0b10001011; teensy_wait(spiral_wait);											//F1, B2
	PORTB = 0b10000111; teensy_wait(spiral_wait);											//F1, B3
	PORTF = 0b00010000; PORTB = 0b00001111; teensy_wait(spiral_wait);						//F4, B7
	PORTF = 0b00100000; PORTB = 0b10001111; PORTD = 0b00000010; teensy_wait(spiral_wait);	//F5, D0
	PORTF = 0b01000000; teensy_wait(spiral_wait);											//F6, D0
	PORTF = 0b10000000; teensy_wait(spiral_wait);											//F7, D0
	PORTB = 0b00001111; PORTD = 0b00000011; teensy_wait(spiral_wait);						//F7, B7
	PORTB = 0b00000111; teensy_wait(spiral_wait);											//F7, B3
	PORTF = 0b01000000; PORTB = 0b10001011; teensy_wait(spiral_wait);						//F6, B2
	
	//1st ring
	PORTF = 0b00100000; PORTB = 0b10001011; PORTD = 0b00000011; teensy_wait(spiral_wait);	//F5, B2
	PORTF = 0b00010000; teensy_wait(spiral_wait);											//F4, B2
	PORTB = 0b10000111; teensy_wait(spiral_wait);											//F4, B3
	PORTF = 0b01000000; PORTB = 0b00001111; teensy_wait(spiral_wait);						//F5, B7
	PORTF = 0b01000000; teensy_wait(spiral_wait);											//F6, B7
	PORTB = 0b10000111; teensy_wait(spiral_wait);											//F6, B3
	
	//top LED
	PORTF = 0b00100000; PORTB = 0b10000111; PORTD = 0b00000011; teensy_wait(spiral_wait);	//F5, B3
	int i;
	for (i=1; i<=4; i++){
		teensy_wait(200); PORTB = 0b10001111;
		teensy_wait(200); PORTB = 0b10000111;
	}
}


int main(void)
{
	teensy_clockdivide(0); //set the clock speed
	teensy_led(ON); // turn on the on board LED

	//set outputs
	DDRF = 0b11110011;
	DDRB = 0b11001111;
	DDRD = 0b00000011;

	//start as off
	PORTF = 0x00;
	PORTB = 0x00;
	PORTD = 0x00;

	while(1){
		
		for(i=1; i<=5; i++){
			rings_blink();
		}
		for(i=1; i<=2; i++){
			spiral_blink();
		}
	}
	return 0; /* never reached */
}



