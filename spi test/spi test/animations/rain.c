/*
 * rain.c
 *
 * Created: 08.03.2018 10:23:44
 *  Author: uidn5332
 */ 

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../ledout.h"

unsigned char raintime1 = 0, raintime2 = 15, raintime3 = 7, raintime4 = 40, raintime5 = 33, raintime6 = 9, raintime7 = 2, raintime8 = 11, speedbias = 50;
unsigned int raininess = 0;
unsigned char rainmeter = 0, mediumrain = 1, strongrain = 1, lightrain = 1;
unsigned char droplets[8] = { -1, -1, -1, -1, -1, -1, -1, -1};

void rain() {
	
	//droplet 1
	if(droplets[0] > 125) {
		droplets[0] = 75 + (rand()%50);
		raintime1 = speedbias+rand()%30;
	}
	raintime1--;
	
	unsigned char blinkabit1 = rand()%7;
	if(blinkabit1 < 3) led[droplets[0]] = 0;
	else led[droplets[0]] = 1;
	
	if(raintime1==0) {
		led[droplets[0]] = 0;
		droplets[0] -= 25;
		raintime1 = speedbias+rand()%30;
	}
	
	//droplet 2
	if(droplets[1] > 125) {
		droplets[1] = 75 + (rand()%50);
		raintime2 = speedbias+rand()%30;
	}
	raintime2--;
	
	unsigned char blinkabit2 = rand()%7;
	if(blinkabit2 < 3) led[droplets[1]] = 0;
	else led[droplets[1]] = 1;
	
	if(raintime2==0) {
		led[droplets[1]] = 0;
		droplets[1] -= 25;
		raintime2 = speedbias+rand()%30;
	}
	
	if(lightrain) {
		//droplet 3
		if(droplets[2] > 125) {
			droplets[2] = 75 + (rand()%50);
			raintime3 = speedbias+rand()%30;
		}
		raintime3--;
	
		unsigned char blinkabit3 = rand()%7;
		if(blinkabit3 < 3) led[droplets[2]] = 0;
		else led[droplets[2]] = 1;
	
		if(raintime3==0) {
			led[droplets[2]] = 0;
			droplets[2] -= 25;
			raintime3 = speedbias+rand()%30;
		}
	
		//droplet 4
		if(droplets[3] > 125) {
			droplets[3] = 75 + (rand()%50);
			raintime4 = speedbias+rand()%30;
		}
		raintime4--;
	
		unsigned char blinkabit4 = rand()%7;
		if(blinkabit4 < 3) led[droplets[3]] = 0;
		else led[droplets[3]] = 1;
	
		if(raintime4==0) {
			led[droplets[3]] = 0;
			droplets[3] -= 25;
			raintime4 = speedbias+rand()%30;
		}
	}else{
		led[droplets[2]] = 0;
		led[droplets[3]] = 0;
	}
	
	
	if(mediumrain) {
		//droplet 5
		if(droplets[4] > 125) {
			droplets[4] = 75 + (rand()%50);
			raintime5 = speedbias+rand()%30;
		}
		raintime5--;
		
		unsigned char blinkabit5 = rand()%7;
		if(blinkabit5 < 3) led[droplets[4]] = 0;
		else led[droplets[4]] = 1;
		
		if(raintime5==0) {
			led[droplets[4]] = 0;
			droplets[4] -= 25;
			raintime5 = speedbias+rand()%30;
		}
		
		//droplet 6
		if(droplets[5] > 125) {
			droplets[5] = 75 + (rand()%50);
			raintime6 = speedbias+rand()%30;
		}
		raintime6--;
		
		unsigned char blinkabit6 = rand()%7;
		if(blinkabit6 < 3) led[droplets[5]] = 0;
		else led[droplets[5]] = 1;
		
		if(raintime6==0) {
			led[droplets[5]] = 0;
			droplets[5] -= 25;
			raintime6 = speedbias+rand()%30;
		}
		}else{
		led[droplets[4]] = 0;
		led[droplets[5]] = 0;
	}
	
	
		if(strongrain) {
			//droplet 7
			if(droplets[6] > 125) {
				droplets[6] = 75 + (rand()%50);
				raintime7 = speedbias+rand()%30;
			}
			raintime7--;
			
			unsigned char blinkabit7 = rand()%7;
			if(blinkabit7 < 3) led[droplets[6]] = 0;
			else led[droplets[6]] = 1;
			
			if(raintime7==0) {
				led[droplets[6]] = 0;
				droplets[6] -= 25;
				raintime7 = speedbias+rand()%30;
			}
			
			//droplet 8
			if(droplets[7] > 125) {
				droplets[7] = 75 + (rand()%50);
				raintime8 = speedbias+rand()%30;
			}
			raintime8--;
			
			unsigned char blinkabit8 = rand()%7;
			if(blinkabit8 < 3) led[droplets[7]] = 0;
			else led[droplets[7]] = 1;
			
			if(raintime8==0) {
				led[droplets[7]] = 0;
				droplets[7] -= 25;
				raintime8 = speedbias+rand()%30;
			}
			}else{
			led[droplets[6]] = 0;
			led[droplets[7]] = 0;
		}
		
		//raininess einstellen
		if(raininess == 10000) {
			raininess = 0;
			unsigned char rainrand = rand()%11;
			if(rainrand < 3) {
				lightrain = 1;
				mediumrain = strongrain = 0;
			}else if(rainrand < 9) {
				lightrain = mediumrain = 1;
				strongrain = 0;
			}else lightrain = mediumrain = strongrain = 1;
		}else raininess++;
	
}

void rain_mode() {
	speedbias += 30;
}


