#include <stdio.h>
#include "arrayCompare.c"
#include "bufferSignature.c"

int main(){
	short freq[] = {3, 2, 2};
	short freqSize = 3;
	short state[] = {1, 0, 0, 1, 0, 2, 2};
	short stateSize = 7;
	short result[stateSize];
	int target[] = {0, 5, 8, 11, 14, 16, 16};
	
	bufferSignature(freq, freqSize, state, stateSize, result);
	
	if(!intArrayCompare(result, target, stateSize))
		puts("bufferSignature(freq: {3, 2, 2}, freqSize: 3, state: {1, 0, 0, 1, 0, 2, 2}, stateSize: 7, result) == {0, 5, 8, 11, 14, 16, 16} : Passed");
	else
		puts("bufferSignature(freq: {3, 2, 2}, freqSize: 3, state: {1, 0, 0, 1, 0, 2, 2}, stateSize: 7, result) == {0, 5, 8, 11, 14, 16, 16} : Failed");
	return 0;
}
