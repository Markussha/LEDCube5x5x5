/*
 * topbottom.c
 *
 * Created: 26.09.2017 08:32:05
 *  Author: uidn5332
 */ 

//Einbinden aller benötigten Bibliotheken
#include "../ledout.h"
#include <avr/interrupt.h>

//Variablen für aktuelle Schicht, Geschwindigkeit und Richtung
unsigned char curl = 0, slow = 0, slowcomp = 10;
char dir = 0;

//gibt Daten ins LED-Array aus
void topbottom() {
		
		slow++;
		
		if(slow == slowcomp) {
			
			for(unsigned char i = 0; i < 125; i++) {
				led[i] = 0;
			}
			
			//Bewegung nach oben
			if(dir == 0) {
				
				for(unsigned char i = 0; i < 25; i++) {
					led[i+ (curl*25)] = 1;
					
					if((curl+1) < 5) {
						led[i+ ((curl+1)*25)] = 2;
					}
					if((curl-1) >= 0) {
						led[i+ ((curl-1)*25)] = 2;
					}

				}
				
				curl++;
				
				if(curl == 5) {
					 dir = 1;
					 curl = 4;
				}
			}
			
			//Bewegung nach unten
			if(dir == 1) {
				
				for(unsigned char i = 0; i < 125; i++) {
					led[i] = 0;
				}
				
				for(unsigned char i = 0; i < 25; i++) {
					led[i+ (curl*25)] = 1;
					
					if((curl+1) < 5) {
						led[i+ ((curl+1)*25)] = 2;
					}
					if((curl-1) >= 0) {
						led[i+ ((curl-1)*25)] = 2;
					}
				}
				
				curl--;
				
				if(curl == 0) {
					dir = 0;
					curl = 0;
				}
			}
			
			slow = 0;
		}
		
}

//Drücken der Modustaste
void topbottom_mode() {
	slowcomp += 10;
}