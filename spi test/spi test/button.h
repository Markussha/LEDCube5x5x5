/*
 * button.h
 *
 * Created: 04.09.2017 11:22:15
 *  Author: uidn5332
 */
 
 //gibt den aktuellen Modus zurück
 unsigned char getMode(void);
 
//Knöpfe einlesen und Modus anpassen
 void getBtn();

 //initialisiere die Pins mit den Buttons
void initbtn(void);