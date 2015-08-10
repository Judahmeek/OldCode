#ifndef ARRAYSUM
#define ARRAYSUM

short arraySum (const short x[], short size){
	int total = 0;
	short i;
	for(i = 0; i < size; ++i){
		total += x[i];
	}
	return total;
};

#endif //ARRAYSUM
