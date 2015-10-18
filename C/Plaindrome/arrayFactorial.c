#ifndef ARRAYFACTORIAL
#define ARRAYFACTORIAL

#include "Factorial.c"

int arrayFactorial(const short x[], short size, short startingIndex, short minus){
	short i = startingIndex;
	int total = factorial(x[i++] - minus);
	while(i < size){
		total *= factorial(x[i++]);
	}
	return total;
};

#endif //ARRAYFACTORIAL
