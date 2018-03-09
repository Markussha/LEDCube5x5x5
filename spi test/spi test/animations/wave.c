/*
 * waves.c
 *
 * Created: 08.03.2018 07:30:43
 *  Author: uidn5332
 */ 

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../ledout.h"
#include "../relLED.h"

unsigned char wave1_1 = 0;
unsigned char wave1_2[3] = {1,5,25};
unsigned char wave1_3[6] = {2, 6, 10, 26, 30, 50};
unsigned char wave1_4[10] = {3, 7, 11, 15, 27, 31, 35, 51, 55, 75};
unsigned char wave1_5[15] = {4, 8, 12, 16, 20, 28, 32, 36, 40, 52, 56, 60, 100, 76, 80};
unsigned char wave1_6[18] = {9, 13, 17, 21, 29, 33, 37, 41, 45, 53, 57, 61, 65, 77, 81, 85, 101, 105};
unsigned char wave1_7[19] = {14, 18, 22, 34, 38, 42, 46, 54, 58, 62, 66, 70, 78, 82, 86, 90, 102, 106, 110};
unsigned char wave1_8[18] = {19, 23, 39, 43, 47, 59, 63, 67, 71, 79, 83, 87, 91, 95, 103, 107, 111, 115};
unsigned char wave1_9[15] = {24, 44, 48, 64, 68, 72, 84, 88, 92, 96, 104, 108, 112, 116, 120};
unsigned char wave1_10[10] = {49, 69, 73, 89, 93, 97, 109, 113, 117, 121};
unsigned char wave1_11[6] = {74, 94, 98, 114, 118, 122};
unsigned char wave1_12[3] = {99, 123, 119};
unsigned char wave1_13 = 124;

unsigned char slowdown = 0, rotate = 0, wavedir = 0, slower = 15;
int currwave = 0;

unsigned char letrotate(unsigned char led) {
	for(int i = 0; i<rotate; i++) led = rot90(led);
	return led;
}

void wave() {
	
	if(slowdown == slower) {
		slowdown = 0;
		
		clearLED();
		
		switch(currwave) {
			case 0: led[letrotate(wave1_1)] = 1; break;
			case 1: for(unsigned char i = 0; i<3; i++) led[letrotate(wave1_2[i])] = 1; break;
			case 2: for(unsigned char i = 0; i<6; i++) led[letrotate(wave1_3[i])] = 1; break;
			case 3: for(unsigned char i = 0; i<10; i++) led[letrotate(wave1_4[i])] = 1; break;
			case 4: for(unsigned char i = 0; i<15; i++) led[letrotate(wave1_5[i])] = 1; break;
			case 5: for(unsigned char i = 0; i<18; i++) led[letrotate(wave1_6[i])] = 1; break;
			case 6: for(unsigned char i = 0; i<19; i++) led[letrotate(wave1_7[i])] = 1; break;
			case 7: for(unsigned char i = 0; i<18; i++) led[letrotate(wave1_8[i])] = 1; break;
			case 8: for(unsigned char i = 0; i<15; i++) led[letrotate(wave1_9[i])] = 1; break;
			case 9: for(unsigned char i = 0; i<10; i++) led[letrotate(wave1_10[i])] = 1; break;
			case 10: for(unsigned char i = 0; i<6; i++) led[letrotate(wave1_11[i])] = 1; break;
			case 11: for(unsigned char i = 0; i<3; i++) led[letrotate(wave1_12[i])] = 1; break;
			case 12: led[letrotate(wave1_13)] = 1; break;
			case -1: led[letrotate(wave1_1)] = 1; break;
		}
		
		if(wavedir == 0) {
			currwave++;
			if(currwave == 13) {
				wavedir = rand()%2;
				rotate = rand()%4;
				if(wavedir) currwave = 12;
				else currwave = 0;
			}
		}else{
			currwave--;
			if(currwave == (-1)) {
				wavedir = rand()%2;
				rotate = rand()%4;
				if(wavedir) currwave = 12;
				else currwave = 0;
			}
		}
	}
	
	
	slowdown++;
} 

void wave_mode() {
	slower += 10;
	if(slower > 120) slower = 25;
}