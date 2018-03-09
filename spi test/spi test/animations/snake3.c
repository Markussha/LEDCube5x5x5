/*
 * snake3.c
 *
 * Created: 08.03.2018 13:43:24
 *  Author: uidn5332
 */ 

#include "../relLED.h"
#include "../ledout.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

unsigned char slower_snake3 = 0, restart_snake3 = 1, currentled_snake3 = 0, newled_snake3 = 0, slowdown_snake3 = 10;
unsigned char led_snake3[6] = {0,0,0,0,0,0};

void snake3() {
	if(slower_snake3 == slowdown_snake3) {
		slower_snake3 = 0;
		
		if(restart_snake3) {
			restart_snake3 = 0;
			currentled_snake3 = rand()%125;
			for(unsigned char i = 0; i<6; i++) {
				led_snake3[i] = currentled_snake3;
			}
		}
		
		while(1) {
			unsigned char random_snakedir = rand()%6;
			switch(random_snakedir) {
				case 0: newled_snake3 = ledback(currentled_snake3); break;
				case 1: newled_snake3 = ledbottom(currentled_snake3); break;
				case 2: newled_snake3 = ledfront(currentled_snake3); break;
				case 3: newled_snake3 = ledleft(currentled_snake3); break;
				case 4: newled_snake3 = ledright(currentled_snake3); break;
				case 5: newled_snake3 = ledtop(currentled_snake3); break;
			}
			if(newled_snake3 != 126 && led[newled_snake3] != 1) {
				currentled_snake3 = newled_snake3;
				for(unsigned char i = 5; i>0; i--) {
					led_snake3[i] = led_snake3[i-1];
				}
				led_snake3[0] = currentled_snake3;
				break;
			}
			if((ledback(currentled_snake3) == 126 || led[ledback(currentled_snake3)] == 1) && (ledfront(currentled_snake3) == 126 || led[ledfront(currentled_snake3)] == 1) && (ledright(currentled_snake3) == 126 || led[ledright(currentled_snake3)] == 1) && (ledbottom(currentled_snake3) == 126 || led[ledbottom(currentled_snake3)] == 1) && (ledleft(currentled_snake3) == 126 || led[ledleft(currentled_snake3)] == 1) && (ledtop(currentled_snake3) == 126 || led[ledtop(currentled_snake3)] == 1)) {
				clearLED();
				for(unsigned char i = 0; i<6; i++) {
					led_snake3[i] = currentled_snake3;
				}
				break;
			}
		}
		clearLED();
		for(unsigned char i = 0; i<6; i++) {
			led[led_snake3[i]] = 1;
		}
	}
	slower_snake3++;
	
}

void snake3_mode() {
	slowdown_snake3 += 15;
	if(slowdown_snake3 >= 100) slowdown_snake3 = 10;
}