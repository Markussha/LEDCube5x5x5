/*
 * random.c
 *
 * Created: 26.09.2017 14:51:23
 *  Author: uidn5332
 */ 

//Einbinden aller nötigen Bibliotheken
#include "isabel.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include "../ledout.h"
#include <avr/interrupt.h>

//deklaration aller nötigen Variablen
unsigned char zufall1[15];
unsigned char zufall2[15];
unsigned char slowr = 1;

//gibt Daten ins LED-Array aus
void ranranrandom(){
	
	if(slowr == 15) {
		slowr = 0;
	
	for(unsigned char i = 0; i < 15; i++){
		change(zufall1[i], 0);			//schalte vorherige LEDs aus
		
		zufall2[i] = rand() % 125;	// bestimme neue LEDs
	}
	
	for(unsigned char i=0; i< 15; ++i){
		change(zufall2[i], 1);					// schalte neue LEDs an
		zufall1[i] = zufall2[i];
	}

	}
	slowr++;
	
}