#include "Factorial.c"

int arrayFactorial(const short x[], short size, short startingIndex, short minus){ //~7/1-17:00 returns sum of each element's factorial O(N)
	short i = startingIndex;
	int total = factorial(x[i++] - minus);
	while(i < size){
		total *= factorial(x[i++]);
	}
	return total;
};
