//Einbinden aller benötigten Bibliotheken
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include "../ledout.h"
#include <avr/interrupt.h>








// uint8_t LED: LED, deren Zustand sich ändern soll (Wert zwischen 0 und 124)
// uint8_t onoff: soll die LED ein- oder ausgeschaltet werden?

void change(unsigned char LED, unsigned char onoff){

	led[LED] = onoff;

}






