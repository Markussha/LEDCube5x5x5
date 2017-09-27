/*/*
 * ledout.h
 *
 * Created: 04.09.2017 08:41:36
 *  Author: uidn5332
 */ 

//Array mit 125 Elementen f�r die LEDs, 1 = an 2 = halbe Helligkeit 0 = aus
unsigned char led[125];

//10ms flag f�r Animation
unsigned char get10msflag();
//100ms flag f�r Knopfabfrage
unsigned char get100msbflag();
//initialisiert den Timer0
void initLEDtimer(void);
//schaltet den gesamten W�rfel aus
void clearLED();