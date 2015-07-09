#include <stdio.h>
#include "arraySum.c"

int main() {
	short array[] = {2, 3, 2};
	short arraySize = 3;
	if(arraySum(array, arraySize) == 7)
		puts("arraySum(array: {2, 3, 2}, arraySize: 3) == 7 : Passed");
	else
		puts("arraySum(array: {2, 3, 2}, arraySize: 3) == 7 : Failed");
	return 0;
}
