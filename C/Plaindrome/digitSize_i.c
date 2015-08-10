#ifndef DIGITSIZE_I
#define DIGITSIZE_I

short digitSize_i(int num) {
    short count = 0;
    unsigned int rval = 1;
    while(num / rval){
        rval *= 10;
        ++count;
	}
    return count;
}

#endif //DIGITSIZE_I
