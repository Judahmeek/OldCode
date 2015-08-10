#ifndef INTARRAYCOMPARE
#define INTARRAYCOMPARE

short intArrayCompare (const int x[], const int y[], short size){
	short i;
	for(i = 0; i < size; ++i){
		if(x[i] > y[i])
			return 1;
		if(x[i] < y[i])
			return -1;
	}
	return 0;
};

#endif //INTARRAYCOMPARE