/*
 * strandtest.c
 *
 * Created: 26.09.2017 08:15:47
 *  Author: uidn5332
 */ 

//Einbinden aller benötigten Bibliotheken
#include "../ledout.h"
#include <avr/interrupt.h>

//deklaration der Variablen für die aktuelle LED, vergangene Zeit und Geschwindigkeit
unsigned char ledi = 0, stime = 0, speedmulti = 10;

//Drücken der Modustaste
void strandtest_mode() {
	speedmulti += 15;
}

//Ausgabe der Daten ins LED-Array
void strandtest() {
	if(stime > speedmulti) {
		led[ledi - 1] = 0;
		led[ledi] = 1;
		stime = 0;
		ledi++;
		if(ledi == 126) {ledi = 0;}
		}else{stime++;}
}

