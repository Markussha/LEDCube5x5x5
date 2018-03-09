/*
 * relLED.c
 *
 * Created: 26.09.2017 10:51:50
 *  Author: uidn5332
 */ 


//gibt die LED links von led zurück
unsigned char ledleft(unsigned char led) {
	
	if(led%5 != 0) {
		return (led-1);
	}else return 126;
	
}

//gibt die LED rechts von led zurück
unsigned char ledright(unsigned char led) {
	
	if((led+1)%5 != 0) {
		return (led+1);
	}else return 126;
	
}

//gibt die LED vor led zurück
unsigned char ledfront(unsigned char led) {
	
	if(led < 5) {return 126;}
	if(led > 24 && (led - 25) < 5) {return 126;}
	if(led > 49 && (led - 50) < 5) {return 126;}
	if(led > 74 && (led - 75) < 5) {return 126;}
	if(led > 99 && (led - 100) < 5) {return 126;}
		
	return (led - 5);
	
}

//gibt die LED hinter led zurück
unsigned char ledback(unsigned char led) {
	
	if(led < 25 && led > 19) {return 126;}
	if(led < 50 && led > 44) {return 126;}
	if(led < 75 && led > 69) {return 126;}
	if(led < 100 && led > 94) {return 126;}
	if(led < 125 && led > 119) {return 126;}
	
	return (led + 5);
	
}

//gibt die LED über led zurück
unsigned char ledtop(unsigned char led) {
	if(led > 99) {return 126;}
	
	return (led + 25);
}

//gibt die LED unter led zurück
unsigned char ledbottom(unsigned char led) {
	if(led < 25) {return 126;}
	
	return (led - 25);
}


unsigned char rot90(unsigned char led) {
	//rotiert die LED um 90 Grad um die Hochachse des LED-Würfels
	unsigned char layerbuffer = led - led%25;
	unsigned char ledpicture  = led%25;
	unsigned char out = 0;
	switch(ledpicture) {
		case 0: out = 4; break;
		case 1: out = 9; break;
		case 2: out = 14; break;
		case 3: out = 19; break;
		case 4: out = 24; break;
		case 5: out = 3; break;
		case 6: out = 8; break;
		case 7: out = 13; break;
		case 8: out = 18; break;
		case 9: out = 23; break;
		case 10: out = 2; break;
		case 11: out = 7; break;
		case 12: out = 12; break;
		case 13: out = 17; break;
		case 14: out = 22; break;
		case 15: out = 1; break;
		case 16: out = 6; break;
		case 17: out = 11; break;
		case 18: out = 16; break;
		case 19: out = 21; break;
		case 20: out = 0; break;
		case 21: out = 5; break;
		case 22: out = 10; break;
		case 23: out = 15; break;
		case 24: out = 20; break;
		default: out = 126;
	}
	return out + layerbuffer;
}