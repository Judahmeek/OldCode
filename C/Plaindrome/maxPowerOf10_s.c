#ifndef MAXPOWEROF10_S
#define MAXPOWEROF10_S

unsigned short maxPowerOf10_s(unsigned short num) {
	if(num){
		unsigned short rval = 1;
	    while(num / rval)
	        rval *= 10;
	    return rval/10;
	}
	return 1;
}

#endif //MAXPOWEROF10_S
