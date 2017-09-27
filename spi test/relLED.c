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