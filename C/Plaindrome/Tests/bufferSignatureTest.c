#include "../IO/printTitledShortArray.c"
#include "../shortArrayCompare.c"
#include "../bufferSignature.c"

int main(){
	short freq[] = {3, 2, 2};
	short freqSize = 3;
	short state[] = {1, 0, 0, 1, 0, 2, 2};
	short stateSize = 7;
	short result[stateSize];
	short target[] = {0, 5, 8, 11, 14, 16, 16};
	
	bufferSignature(freq, freqSize, state, stateSize, result);
	
	printTitledShortArray("bufferSignature(freq: ", freq, freqSize, 0);
	printf(", freqSize: %d, state: ", freqSize);
	printShortArray(state, stateSize);
	printf(", stateSize: %d, result) == ", stateSize);
	printShortArray(target, stateSize);
	
	if(!shortArrayCompare(result, target, stateSize))
		puts(" : Passed");
	else
		puts(" : Failed");
		
	return 0;
}
