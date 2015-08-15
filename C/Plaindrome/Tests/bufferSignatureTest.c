#include "../IO/printTitledShortArray.c"
#include "../shortArrayCompare.c"
#include "../bufferSignature.c"

int main(){
	short freq[] = {2, 2, 1};
	short freqSize = 3;
	short state[] = { 0, 1, 1, 2, 0 };
	short stateSize = 5;
	short result[stateSize];
	short target[] = {0, 3, 5, 7, 8};
	
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
