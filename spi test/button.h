/*
 * button.h
 *
 * Created: 04.09.2017 11:22:15
 *  Author: uidn5332
 */

//gibt aus ob 100ms vergangen sind...
//oder etwas in der Art...
//eher Sch�tzwert
 unsigned char get100msflag(void);
 
 //gibt den aktuellen Modus zur�ck
 unsigned char getMode(void);
 
//Kn�pfe einlesen und Modus anpassen
 void getBtn();

 //initialisiere die Pins mit den Buttons
void initbtn(void);