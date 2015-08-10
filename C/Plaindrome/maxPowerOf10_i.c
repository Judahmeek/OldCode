unsigned int maxPowerOf10_i(unsigned int num) {
	if(num){
		unsigned int rval = 1;
	    while(num / rval)
	        rval *= 10;
	    return rval/10;
	}
	return 1;
}
