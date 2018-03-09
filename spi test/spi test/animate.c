/*
 * animate.c
 *
 * Created: 15.09.2017 11:35:41
 *  Author: uidn5332
 */ 

//unsigned char ruediger;

//nötige Bibliotheken einbinden
#include "ledout.h"
#include <avr/interrupt.h>

#include "animations/strandtest.h"
#include "animations/topbottom.h"
#include "animations/explosion.h"
#include "animations/random.h"
#include "animations/isabel.h"
#include "animations/snake.h"
#include "animations/KZW.h"
#include "animations/next.h"
#include "animations/wave.h"
#include "animations/rain.h"
#include "animations/snake.h"
#include "animations/snake2.h"
#include "animations/snake3.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>

//Variablen für Modi und Zeitverzögerung
unsigned char prevmode = 0, savemode = 0, isabeltime = 0;


//----------------------------------------------------------------------------------------------
//Funktion: animate
//Wählt die passende Animation und ruft diese im richtigen Zeittakt auf
//Aufgerufene Funktionen: siehe animations/*
//Zurückgegebene Werte	: keine
//----------------------------------------------------------------------------------------------
void animate(unsigned char mode) {
	
	//letzten Modus schreiben
	savemode = mode;
	
	//vergleiche Modus mit letztem Modus
	if(prevmode != mode) {
		//cleare das gesamte LED-Array
		for(unsigned char i = 0; i < 125; i++) {
			led[i] = 0;
		}
		prevmode = mode;
	}
	
	//je mach Modus die richtige Animation ausführen
	switch(mode) {
		case 1:		strandtest(); break;
		case 2:		topbottom(); break;
		case 3:		wave(); break;
		case 4:		for(unsigned char i = 0; i < 125; i++) {
					led[i] = 1;
					}break;
		case 5:		ranranrandom(); break;
		case 6:		rain(); break;
		case 7:		snakerun(); break;
		case 8:		snake2(); break;
		case 9:		snake3(); break;
		default: break;
	}
	

}

//----------------------------------------------------------------------------------------------
//Funktion: modeswitch
//bei Drücken des mittleren Knopfes (Button2) Aktion ausführen
//Aufgerufene Funktionen: siehe animations/*
//Zurückgegebene Werte	: keine
//----------------------------------------------------------------------------------------------
void modeswitch() {
	switch(savemode) {
		case 1: strandtest_mode(); break;
		case 2: topbottom_mode(); break;
		case 3: wave_mode(); break;
		case 6: rain_mode(); break;
		case 8: snake2_mode(); break;
		case 9: snake3_mode(); break;
	}
}