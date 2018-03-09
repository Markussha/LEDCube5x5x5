/*
 * snake2.c
 *
 * Created: 08.03.2018 13:01:00
 *  Author: uidn5332
 */ 
#include "../relLED.h"
#include "../ledout.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

unsigned char slower_snake2 = 0, restart_snake2 = 1, currentled_snake2 = 0, newled_snake2 = 0, slowdown_snake2 = 15;


void snake2() {
	if(slower_snake2 == 15) {
		slower_snake2 = 0;
		
		if(restart_snake2) {
			restart_snake2 = 0;
			currentled_snake2 = rand()%125;
			led[currentled_snake2] = 1;
		}
		
		while(1) {
			unsigned char random_snakedir = rand()%6;
			switch(random_snakedir) {
				case 0: newled_snake2 = ledback(currentled_snake2); break;
				case 1: newled_snake2 = ledbottom(currentled_snake2); break;
				case 2: newled_snake2 = ledfront(currentled_snake2); break;
				case 3: newled_snake2 = ledleft(currentled_snake2); break;
				case 4: newled_snake2 = ledright(currentled_snake2); break;
				case 5: newled_snake2 = ledtop(currentled_snake2); break;
			}
			if(newled_snake2 != 126 && led[newled_snake2] != 1) {
				currentled_snake2 = newled_snake2;
				led[currentled_snake2] = 1;
				break;
			}
			if((ledback(currentled_snake2) == 126 || led[ledback(currentled_snake2)] == 1) && (ledfront(currentled_snake2) == 126 || led[ledfront(currentled_snake2)] == 1) && (ledright(currentled_snake2) == 126 || led[ledright(currentled_snake2)] == 1) && (ledbottom(currentled_snake2) == 126 || led[ledbottom(currentled_snake2)] == 1) && (ledleft(currentled_snake2) == 126 || led[ledleft(currentled_snake2)] == 1) && (ledtop(currentled_snake2) == 126 || led[ledtop(currentled_snake2)] == 1)) {
				clearLED();
				led[currentled_snake2] = 1;
				break;
			}
		}
	}
	slower_snake2++;
	
}

void snake2_mode() {
	slowdown_snake2 += 15;
	if(slowdown_snake2 >= 100) slowdown_snake2 = 10;
}