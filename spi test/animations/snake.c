/*
 * snake.c
 *
 * Created: 27.09.2017 10:08:02
 *  Author: uidn5332
 */ 


//Einbinden aller nötigen Bibliotheken
#include "isabel.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include "../ledout.h"
#include <avr/interrupt.h>

uint8_t snake[5]; //Schlange startet bei LED 0
void snakerun(){
		
	//bestimme LEDs um "Kopf" der Schlange "drumherum"
	uint8_t around_array[26];
	
	around_array[0] = snake[0] - 1 % 125;
	around_array[1] = snake[0] + 1 % 125;
	around_array[2] = snake[0] + 4 % 125;
	around_array[3] = snake[0] + 5 % 125;
	around_array[4] = snake[0] + 6 % 125;
	around_array[5] = snake[0] - 6 % 125;
	around_array[6] = snake[0] - 5 % 125;
	around_array[7] = snake[0] - 4 % 125;

	around_array[8] = snake[0] - 25 % 125;
	around_array[9] = snake[0] - 26 % 125;
	around_array[10] = snake[0] - 24 % 125;
	around_array[11] = snake[0] - 21 % 125;
	around_array[12] = snake[0] - 20 % 125;
	around_array[13] = snake[0] - 19 % 125;
	around_array[14] = snake[0] - 31 % 125;
	around_array[15] = snake[0] - 30 % 125;
	around_array[16] = snake[0] - 29 % 125;
	around_array[17] = snake[0] + 25 % 125;
	around_array[18] = snake[0] + 26 % 125;
	around_array[19] = snake[0] + 24 % 125;
	around_array[20] = snake[0] + 29 % 125;
	around_array[21] = snake[0] + 30 % 125;
	around_array[22] = snake[0] + 31 % 125;
	around_array[23] = snake[0] + 19 % 125;
	around_array[24] = snake[0] + 20 % 125;
	around_array[25] = snake[0] + 21 % 125;

	// bestimme anhand des around_arrays zufällig, die Richtung, in die sich die Schlange als nächstes bewegtifif
	
	uint8_t nextLED = around_array[rand()%26];
	if(nextLED == snake[1]){   // Schlange kann sich nicht um 360° drehen
		nextLED = around_array[(nextLED + 1) % 26];
	}
	
	// Update für die Schlange
	
	change(snake[4],0);
	for (uint8_t i = 4; i > 0; --i){
		snake[i] = snake[i-1];
	}
	snake[0] = nextLED;
	
	for (uint8_t i = 0; i < 5; ++i){
		change(snake[i],1);
	}
	

	
	

/*	for (uint8_t i = 0; i < 26; ++i){
		change(around_array[i],1);
	}	
 */


}








