/*
 * explosion.c
 *
 * Created: 26.09.2017 11:17:09
 *  Author: uidn5332
 */ 

//Einbinden aller benötigten Bibliotheken
#include "../ledout.h"
#include <avr/interrupt.h>
#include "../relLED.h"


//WaveArrays
unsigned char wave0, wave1[6], wave2[30], wave3[6*4*4]; 

//berechne umliegende LEDs
void calcwaves(unsigned char ledi) {
	
	wave1[0] = ledtop(ledi);
	wave1[1] = ledbottom(ledi);
	wave1[2] = ledleft(ledi);
	wave1[3] = ledright(ledi);
	wave1[4] = ledfront(ledi);
	wave1[5] = ledback(ledi);
	
	//top1 relatives
	wave2[0] = ledtop(wave1[0]);
	wave2[1] = ledleft(wave1[0]);
	wave2[2] = ledright(wave1[0]);
	wave2[3] = ledfront(wave1[0]);
	wave2[4] = ledback(wave1[0]);
	
	//bottom1 relatives
	wave2[15] = ledtop(wave1[0]);
	wave2[16] = ledleft(wave1[0]);
	wave2[17] = ledright(wave1[0]);
	wave2[18] = ledfront(wave1[0]);
	wave2[19] = ledback(wave1[0]);
	
	//left1 relatives
	wave2[5] = ledtop(wave1[2]);
	wave2[6] = ledleft(wave1[2]);
	wave2[7] = ledbottom(wave1[2]);
	wave2[8] = ledfront(wave1[2]);
	wave2[9] = ledback(wave1[2]);
	
	//right1 relatives
	wave2[10] = ledtop(wave1[3]);
	wave2[11] = ledright(wave1[3]);
	wave2[12] = ledbottom(wave1[3]);
	wave2[13] = ledfront(wave1[3]);
	wave2[14] = ledback(wave1[3]);
	
	//front1 relatives
	wave2[20] = ledtop(wave1[4]);
	wave2[21] = ledright(wave1[4]);
	wave2[22] = ledbottom(wave1[4]);
	wave2[23] = ledfront(wave1[4]);
	wave2[24] = ledleft(wave1[4]);
	
	//back1 relatives
	wave2[25] = ledtop(wave1[4]);
	wave2[26] = ledright(wave1[4]);
	wave2[27] = ledbottom(wave1[4]);
	wave2[28] = ledback(wave1[4]);
	wave2[29] = ledleft(wave1[4]);
	
}

//bearbeitet die LED-Arrays
void explosion() {
	
	calcwaves(63);
	
	for(uint8_t i = 0; i < 30; i++) {
		led[wave2[i]] = 1;
	}
	
}


