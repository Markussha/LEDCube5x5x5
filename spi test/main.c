 /*
 * spi test.c
 *
 * Created: 12.09.2017 08:53:19
 * Author : uidn5332
 */ 

//Definieren der Prozessorfrequenz f�r einige Module
#define F_CPU 16000000UL

//Einbinden aller n�tigen Bibliotheken
#include <avr/io.h>
#include "spi.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include "ledout.h"
#include "button.h"
#include "animate.h"

//----------------------------------------------------------------------------------------------
//Funktion: ioinit
//Initialisiert die Ein- und Ausg�nge f�r die LED-Matrix
//Aufgerufene Funktionen: keine
//Zur�ckgegebene Werte	: keine
//----------------------------------------------------------------------------------------------
void ioinit(void) {
	//LE Pins als Output deklarieren
	DDRB |= (1<<PB2)|(1<<PB1);
	DDRD |= (1<<PD7)|(1<<PD6);
	//OE Pins als Output deklarieren
	DDRB |= (1<<PB0);
	//Layer auf Output setzen
	DDRC = 0xff;
}

//----------------------------------------------------------------------------------------------
//Funktion: main
//Startfunktion, hier startet der Code
//Aufgerufene Funktionen: ioinit (main.c), initLEDtimer (ledout.c), initbtn (button.c), getBtn (button.c), animate (animate.c), getMode (button.c)
//Zur�ckgegebene Werte	: keine
//----------------------------------------------------------------------------------------------
int main(void)
{
	
	//initialisiere alles
	ioinit();
	initLEDtimer();
	SPI_MasterInit();
	initbtn();
	settimer();
	
	//aktiviere Interrupts
	sei();

    while (1) 
    {
		
		//lese alle Kn�pfe ein, setze Modus passend (siehe button.c)
		if(get100msbflag()) {
			getBtn();
		}
		
		//animationsfunktionen aufrufen
		if(get10msflag()) {
			animate(getMode());
		}

    }
	
	
}
