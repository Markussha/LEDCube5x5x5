/*
 * animate.c
 *
 * Created: 15.09.2017 11:35:41
 *  Author: uidn5332
 */ 

unsigned char ruediger;

//n�tige Bibliotheken einbinden
#include "ledout.h"
#include <avr/interrupt.h>
#include "animations/strandtest.h"
#include "animations/topbottom.h"
#include "animations/explosion.h"
#include "animations/random.h"
#include "animations/isabel.h"
#include "animations/snake.h"
#include "animations/KZW.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>

//Variablen f�r Modi und Zeitverz�gerung
unsigned char prevmode = 0, savemode = 0, isabeltime = 0;


//----------------------------------------------------------------------------------------------
//Funktion: animate
//W�hlt die passende Animation und ruft diese im richtigen Zeittakt auf
//Aufgerufene Funktionen: siehe animations/*
//Zur�ckgegebene Werte	: keine
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
	
	//je mach Modus die richtige Animation ausf�hren
	switch(mode) {
		case 1:		strandtest(); break;
		case 2:		topbottom(); break;
		case 3:		explosion(); break;
		case 4:		for(unsigned char i = 0; i < 125; i++) {
					led[i] = 1;
					}break;
		case 5:		ranranrandom(); break;
		default: break;
	}
	

}

//----------------------------------------------------------------------------------------------
//Funktion: modeswitch
//bei Dr�cken des mittleren Knopfes (Button2) Aktion ausf�hren
//Aufgerufene Funktionen: siehe animations/*
//Zur�ckgegebene Werte	: keine
//----------------------------------------------------------------------------------------------
void modeswitch() {
	switch(savemode) {
		case 1: strandtest_mode(); break;
		case 2: topbottom_mode(); break;
	}
}