/*
 * button.c
 *
 * Created: 04.09.2017 11:21:52
 *  Author: uidn5332
 */ 

//CPU-Frequenz definieren
#define F_CPU 16000000UL

//Einbinden der nötigen Bibliotheken
#include <avr/io.h>
#include <avr/interrupt.h>
#include "button.h"
#include "ledout.h"
#include "animate.h"
#include "spi.h"
#include <util/delay.h>
#include <avr/sleep.h>

//definiere den maximalen Modus
#define maxmode 9

//Setze Werte für das debouncen der Knöpfe (Aktionen nur einmalig ausführen) und die ISR für Zeitspezifisches 

//debounce flags
unsigned char deb1=0,deb2=0,deb3=0,deb4=0,deb5=0;
//buttonRun flags
unsigned char run1=0,run2=0,run3=0,run4=0,run5=0;
//wasActive flags
unsigned char last1=0,last2=0,last3=0,last4=0,last5=0;
//timeFlag
unsigned char t100msflag=0;
//ModeFlag
unsigned char MODE = 1;
//stateFlags
unsigned char specialState = 0;
//2s sleepmode
unsigned char sleepTime = 0;


//----------------------------------------------------------------------------------------------
//Funktion: getMode
//gibt den aktuellen Modus zurück
//Aufgerufene Funktionen: keine
//Zurückgegebene Werte	: MODE
//----------------------------------------------------------------------------------------------
unsigned char getMode() {
	return MODE;
}

//----------------------------------------------------------------------------------------------
//Funktion: initbtn
//initialisiert die Pins auf welchen die Knöpfe liegen
//Aufgerufene Funktionen: keine
//Zurückgegebene Werte	: keine
//----------------------------------------------------------------------------------------------
void initbtn() {
	//Pullup auf Buttons aktivieren
	PORTD = 0xff;	
	

}

//----------------------------------------------------------------------------------------------
//Funktion: getModeChange
//Wertet Knopfdrücke aus und ändert die Modusvariable
//Aufgerufene Funktionen: modeswitch (animate)
//Zurückgegebene Werte	: keine
//----------------------------------------------------------------------------------------------
void getModeChange() {
	if(specialState == 1) {
		specialState = 0;
		cli();
		MODE = maxmode + 5;
	}
	if(run2 == 1) {
		modeswitch();
		run2 = 0;
	} 
	if(run1 == 1) {
		MODE++;
		if(MODE > maxmode) {
			MODE = 1;
		}
		run1 = 0;
	}
	if(run3 == 1) {
		MODE--;	
		if(MODE < 1) {
			MODE = maxmode;
		}
		run3 = 0;
	}
}

//----------------------------------------------------------------------------------------------
//Funktion: getRunFlags
//liest die Knöpfe ein, setzt Ausführungsflags
//Aufgerufene Funktionen: keine
//Zurückgegebene Werte	: keine
//----------------------------------------------------------------------------------------------
void getRunFlags() {
		//check button 3
		if (!(PIND & (1<<PD2))) {
			if(last3 == 0) {
				run3 = 1;
				last3 = 1;
				//check for combination
				if (!(PIND & (1<<PD5))) {
					specialState = 1;
				}
			}
			}else if(last3 == 1) {
			last3 = 0;
		}
		//check button 1
		if (!(PIND & (1<<PD5))) {
			if(last1 == 0) {
				run1 = 1;
				last1 = 1;
				//check for combination
				if (!(PIND & (1<<PD2))) {
					specialState = 1;
				}
			}
			}else if(last1 == 1) {
			last1 = 0;
		}
		//check button 2
		if (!(PIND & (1<<PD3))) {
			if(last2 == 0) {
				run2 = 1;
				last2 = 1;
			}
			sleepTime++;
			
			if(sleepTime == 15) {
				EIMSK |= (1<<INT1);
				EICRA |= (1<<ISC11);
				TIMSK0 &= ~(1<<OCIE0A);
				
				//clear LEDs
				SPI_Send(0x00);
				SPI_Send(0x00);
				SPI_Send(0x00);
				SPI_Send(0x00);
				//Latch upper Chip
				PORTD |= (1<<PD7);
				PORTD &= ~(1<<PD7);
				
				//schalte Layer aus
				PORTC = 0x00;
				
				//schlafmodus aktivieren
				set_sleep_mode(SLEEP_MODE_PWR_DOWN);
				sleep_mode();
				
			}
			
			}else if(last2 == 1) {
			last2 = 0;
			sleepTime = 0;
		}
}

//----------------------------------------------------------------------------------------------
//Funktion: getBtn
//Knöpfe einlesen + modi ändern 
//Aufgerufene Funktionen: keine
//Zurückgegebene Werte	: keine
//----------------------------------------------------------------------------------------------
void getBtn() {
	getRunFlags();
	getModeChange();
}

//----------------------------------------------------------------------------------------------
//Funktion: ISR
//Aufwecken aus dem Schlafmodus
//Aufgerufene Funktionen: keine
//Zurückgegebene Werte	: keine
//----------------------------------------------------------------------------------------------
ISR(INT1_vect) {
	_delay_ms(1);
	if (!(PIND & (1<<PD3))) {
		TIMSK0 |= (1<<OCIE0A);
	}
}

//----------------------------------------------------------------------------------------------
//Funktion: RS232State
//Betreiben der Verbindung zu einem Hostcomputer
//Aufgerufene Funktionen: keine
//Zurückgegebene Werte	: keine
//----------------------------------------------------------------------------------------------
void RS232State() {
	if(MODE == maxmode + 5) {
		
	}
}
