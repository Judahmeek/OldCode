#ifndef MAXPOWEROF10_I
#define MAXPOWEROF10_I

unsigned int maxPowerOf10_i(unsigned int num) {
	if(num){
		unsigned int rval = 1;
	    while(num / rval)
	        rval *= 10;
	    return rval/10;
	}
	return 1;
}

#endif //MAXPOWEROF10_I