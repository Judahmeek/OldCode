#include <stdio.h>
#include "arrayFactorial.c"

int main() {
	short array[] = {2, 3, 2};
	short arraySize = 3;
	short startingIndex = 0;
	short minus = 1;
	if(arrayFactorial(array, arraySize, startingIndex, minus) == 12)
		puts("arrayFactorial({2, 3, 2}, arraySize: 3, startingIndex: 0, minus: 1) == 12 : Passed");
	else
		puts("arrayFactorial({2, 3, 2}, arraySize: 3, startingIndex: 0, minus: 1) == 12 : Failed");
	return 0;
}
