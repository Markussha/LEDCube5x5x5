/*
 * ledout.c
 *
 * Created: 04.09.2017 08:41:23
 *  Author: uidn5332
 */ 

//definiere die Prozessorgeschwindigkeit für einige Module
#define  F_CPU 16000000UL

//Einbinden der nötigen Bibliotheken
#include <avr/io.h>
#include <avr/interrupt.h>
#include "ledout.h"
#include <avr/interrupt.h>
#include "spi.h"
#include <util/delay.h>

//definiere Variablen für aktuelle Schicht, LED-Ausgabe und Helligkeit
unsigned char currl = 0, offset = 0, ledare = 0;

//definiere Bytes für die LED-Treiber
//Chip1, Pins 15-8
int8_t MAXData11;
//Chip1, Pins 7-0
int8_t MAXData12;
//Chip2, Pins 15-8
int8_t MAXData21;
//Chip2, Pins 7-0
int8_t MAXData22;
//TimeFlag
unsigned char t10msflag = 0, t10msbflag = 0;
unsigned char t10ms = 0, t10msb = 2;

//----------------------------------------------------------------------------------------------
//Funktion: initLEDtier
//Initialisiert Timer0 als Timer für die LED-Ausgabe und zeitspezifische Flags
//Aufgerufene Funktionen: keine
//Zurückgegebene Werte	: keine
//----------------------------------------------------------------------------------------------
void initLEDtimer(void) {
	//CTC Modus Timer O C1
	TCCR0A |= (1<<WGM01);
	//Vorteiler auf 64
	TCCR0B |= (1<<CS01)|(1<<CS00);
	// Aktiviere OCIEA
	TIMSK0 |= (1<<OCIE0A);
	//etwa alle 10ms
	OCR0A = 180;
}

//----------------------------------------------------------------------------------------------
//Funktion: get10msflag
//Gibt die timing-flag für die Animationen zurück
//Aufgerufene Funktionen: keine
//Zurückgegebene Werte	: 1 oder 0, je nachdem ob 10ms vergangen sind
//----------------------------------------------------------------------------------------------
unsigned char get10msflag() {
	if(t10msflag == 1) {
		t10msflag = 0;
		return 1;
		}else { return 0;}
 	}
	 
//----------------------------------------------------------------------------------------------
//Funktion: get100msbflag
//Gibt die timing-flag für die Knopfabfrage zurück
//Aufgerufene Funktionen: keine
//Zurückgegebene Werte	: 1 oder 0, je nachdem ob halbwegs 100ms vergangen sind
//----------------------------------------------------------------------------------------------
unsigned char get100msbflag() {
	if(t10msbflag == 1) {
		t10msbflag = 0;
		return 1;
		}else { return 0;}
	}

//----------------------------------------------------------------------------------------------
//Funktion: convertArrayToBitmask
//Konvertiert die Werte aus dem LED-Array in Bitmasken für die LED-Treiber
//Aufgerufene Funktionen: keine
//Zurückgegebene Werte	: keine
//----------------------------------------------------------------------------------------------
void convertArrayToBitmask(unsigned char l) {
	
	MAXData11 = 0x00;
	MAXData12 = 0x00;
	MAXData21 = 0x00;
	MAXData22 = 0x00;
	switch(l) {
		
		case 0: offset = 0;	
			break;
		
		case 1: offset = 25;
			break;
			
		case 2: offset = 50;
			break;
			
		case 3: offset = 75;
			break;
			
		case 4: offset = 100;
			break;
		
	}
	if(led[0 + offset] == 1) {MAXData21 |= 1<<0;}
	if(led[1 + offset] == 1) {MAXData22 |= 1<<7;}
	if(led[2 + offset] == 1) {MAXData22 |= 1<<6;}
	if(led[3 + offset] == 1) {MAXData22 |= 1<<5;}
	if(led[4 + offset] == 1) {MAXData22 |= 1<<4;}
	if(led[5 + offset] == 1) {MAXData22 |= 1<<3;}
	if(led[6 + offset] == 1) {MAXData22 |= 1<<2;}
	if(led[7 + offset] == 1) {MAXData22 |= 1<<1;}
	if(led[8 + offset] == 1) {MAXData22 |= 1<<0;}
	if(led[9 + offset] == 1) {MAXData11 |= 1<<7;}
	if(led[10 + offset] == 1) {MAXData11 |= 1<<6;}
	if(led[11 + offset] == 1) {MAXData11 |= 1<<5;}
	if(led[12 + offset] == 1) {MAXData11 |= 1<<4;}
	if(led[13 + offset] == 1) {MAXData11 |= 1<<3;}
	if(led[14 + offset] == 1) {MAXData11 |= 1<<2;}
	if(led[15 + offset] == 1) {MAXData11 |= 1<<1;}
	if(led[16 + offset] == 1) {MAXData11 |= 1<<0;}
	if(led[17 + offset] == 1) {MAXData12 |= 1<<7;}
	if(led[18 + offset] == 1) {MAXData12 |= 1<<6;}
	if(led[19 + offset] == 1) {MAXData12 |= 1<<5;}
	if(led[20 + offset] == 1) {MAXData12 |= 1<<4;}
	if(led[21 + offset] == 1) {MAXData12 |= 1<<3;}
	if(led[22 + offset] == 1) {MAXData12 |= 1<<2;}
	if(led[23 + offset] == 1) {MAXData12 |= 1<<1;}
	if(led[24 + offset] == 1) {MAXData12 |= 1<<0;}
		
	//halbe Helligkeit
	if(ledare == 1) {
			if(led[0 + offset] == 2) {MAXData21 |= 1<<0;}
			if(led[1 + offset] == 2) {MAXData22 |= 1<<7;}
			if(led[2 + offset] == 2) {MAXData22 |= 1<<6;}
			if(led[3 + offset] == 2) {MAXData22 |= 1<<5;}
			if(led[4 + offset] == 2) {MAXData22 |= 1<<4;}
			if(led[5 + offset] == 2) {MAXData22 |= 1<<3;}
			if(led[6 + offset] == 2) {MAXData22 |= 1<<2;}
			if(led[7 + offset] == 2) {MAXData22 |= 1<<1;}
			if(led[8 + offset] == 2) {MAXData22 |= 1<<0;}
			if(led[9 + offset] == 2) {MAXData11 |= 1<<7;}
			if(led[10 + offset] == 2) {MAXData11 |= 1<<6;}
			if(led[11 + offset] == 2) {MAXData11 |= 1<<5;}
			if(led[12 + offset] == 2) {MAXData11 |= 1<<4;}
			if(led[13 + offset] == 2) {MAXData11 |= 1<<3;}
			if(led[14 + offset] == 2) {MAXData11 |= 1<<2;}
			if(led[15 + offset] == 2) {MAXData11 |= 1<<1;}
			if(led[16 + offset] == 2) {MAXData11 |= 1<<0;}
			if(led[17 + offset] == 2) {MAXData12 |= 1<<7;}
			if(led[18 + offset] == 2) {MAXData12 |= 1<<6;}
			if(led[19 + offset] == 2) {MAXData12 |= 1<<5;}
			if(led[20 + offset] == 2) {MAXData12 |= 1<<4;}
			if(led[21 + offset] == 2) {MAXData12 |= 1<<3;}
			if(led[22 + offset] == 2) {MAXData12 |= 1<<2;}
			if(led[23 + offset] == 2) {MAXData12 |= 1<<1;}
			if(led[24 + offset] == 2) {MAXData12 |= 1<<0;}
	}
	
	ledare++;
	if(ledare == 2) ledare = 0;
	
}

//----------------------------------------------------------------------------------------------
//Funktion: ISR
//Läuft in hoher zeitlicher Frequenz (Interrupt), setzt die RunFlags die oben zurückgegeben werden, schickt Daten an Chips und aktiviert die korrekte Schicht
//Aufgerufene Funktionen: convertArrayToBitmask (ledout.c), SPI_Send (spi.c)
//Zurückgegebene Werte	: keine
//----------------------------------------------------------------------------------------------
ISR(TIMER0_COMPA_vect) {
	//set 10ms runflag
	if(t10ms == 3) {
		t10ms = 0;
		t10msflag = 1;
	}else{t10ms++;}
		
	//set button runflag
	if(t10msb == 150) {
		t10msb = 0;
		t10msbflag = 1;
		}else{t10msb++;}
	
	//t10msflag = 1;
	//Turn off all LayerFETs
	PORTC = 0x00;
	//get SPI data from LED Array
	convertArrayToBitmask(currl);
	
	//Send Data to lower Chip
	SPI_Send(MAXData21);
	SPI_Send(MAXData22);
	//Send Data to upper Chip
	SPI_Send(MAXData11);
	SPI_Send(MAXData12);
	//Latch upper Chip
	PORTD |= (1<<PD7);
	PORTD &= ~(1<<PD7);
	
	//turn on appropriate FET
	switch(currl) {
		case 4: PORTC |= (1<<4); break;
		case 3: PORTC |= (1<<3); break;
		case 2: PORTC |= (1<<2); break;
		case 1: PORTC |= (1<<1); break;
		case 0: PORTC |= (1<<0); break;
		default:break;
	}
	
	currl++;
	if (currl == 5) {currl = 0;}
}

//----------------------------------------------------------------------------------------------
//Funktion: clearLED
//Schaltet den gesamten Würfel aus
//Aufgerufene Funktionen: keine
//Zurückgegebene Werte	: keine
//----------------------------------------------------------------------------------------------
void clearLED() {
	for(unsigned char i = 0; i < 125; i++) {
		led[i] = 0;
	}
}