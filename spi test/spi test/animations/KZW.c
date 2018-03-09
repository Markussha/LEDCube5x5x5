/*
 * KZW.c
 *
 * Created: 27.09.2017 10:31:24
 *  Author: uidn5332
 */ 

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include "../ledout.h"
#include <avr/interrupt.h>
#include "isabel.h"



uint8_t Millis100;
uint8_t seconds;
uint8_t overflowcounter;


void blink(){
	uint8_t previous = seconds;
	
	if(seconds - previous >= 1){
		previous = seconds;
		
		if(previous % 2 == 0){ // LEDs in "geraden Sekunden" einschalten
			for (uint8_t i = 0; i < 125; i++){
				change(i, 1);
			}
		}
		else{ //ansonsten aus
			for (uint8_t i = 0; i < 125; i++){
				change(i, 0);
			}
		}
		
	}
}


ISR(TIMER2_OVF_vect){
	overflowcounter += 1; // 1 overflow alle 16,382 Millisekunden
	
	if (overflowcounter == 6){
		Millis100 += 1;
	}
	if (Millis100 == 10){
		seconds += 1;
	}
}


uint8_t nodoubles[125];
void ndr(){
	
	uint8_t randomarray[150];
	for (uint8_t i = 0; i < 150; ++i) //erzeuge 150 Zufallszahlen von 0-124
	{randomarray[i]=rand()%125;
	}
	
	//lösche doppelte Zahlen aus dem Array
	//setze zunächst doppelte Zahlen auf -1
	for (uint8_t i = 0; i < 150; ++i){
		uint8_t current = randomarray[i];
		if (current==-1){
			break;
		}
		for (uint8_t j = i + 1; j < 150; ++j){
			if (current==randomarray[j]){
				randomarray[j]=-1;
				
				break;
			}
			
		}
	}
	
	//übernehme nur nicht-markierte Zahlen ins Array (wir brauchen nur 125)
	uint8_t count=0;
	for(uint8_t i = 0; i < 125; ++i){
		if(randomarray[i] != -1){
			nodoubles[count]=randomarray[i];
			count+=1;
		}
	}
}


// configure Timer2

void settimer(){
	ndr();
	TCCR2B |= (1 <<  CS20) | (1 << CS21) | (1 << CS22); // Prescaler 1024

	// Overflow interrupt
	TIMSK2 |= (1 << 0);

	// activate timer
	PRR |= (1 << PRTIM2);
}

uint8_t elapsedtime = 0;
uint8_t LEDcounter = 0;
uint8_t previous = 0;

void eggtimer(){
	previous = seconds;
	ndr();
	
	
	// schalte alle LEDs an
	for (uint8_t i = 0; i < 125; ++i){
		change(i, 1);
	}
	
	while (elapsedtime <= 60){ // solange eine Minute noch nicht rum ist
		if (seconds - previous >= 1){ //wenn eine Sekunde um ist
			
			previous = seconds;
			
			if (LEDcounter < 15){ // am Anfang werden jeweils 3 LEDs ausgeschaltet
				change(LEDcounter, 0);
				change(LEDcounter + 1, 0);
				change(LEDcounter + 2, 0);
				
				LEDcounter += 2;
			}
			else{ // später nur noch 2
				change(LEDcounter, 0);
				change(LEDcounter + 1, 0);
				
			}
			elapsedtime += 1;
		}
		
		
		if (elapsedtime == 60){
			blink();
		}
}
}

