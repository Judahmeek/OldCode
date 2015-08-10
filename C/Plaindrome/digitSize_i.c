short digitSize_i(int num) {
    short count = 0;
    unsigned int rval = 1;
    while(num / rval){
        rval *= 10;
        ++count;
	}
    return count;
}
