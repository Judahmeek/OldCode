#include "../IO/printTitledShortArray.c"
#include "../shortArrayCompare.c"
#include "../bufferSignature.c"

int main(){
	short freq[] = {2, 2, 1};
	short freqSize = 3;
	short state[] = { 0, 1, 1, 2, 0 };
	short stateSize = 5, sigSize = stateSize - 1;
	short result[sigSize];
	short target[] = {3, 5, 7, 8};
	
	bufferSignature(freq, freqSize, state, sigSize, result);
	
	printTitledShortArray("bufferSignature(freq: ", freq, freqSize, 0);
	printf(", freqSize: %d, state: ", freqSize);
	printShortArray(state, stateSize);
	printf(", sigSize: %d, result) == ", sigSize);
	printShortArray(target, sigSize);
	
	if(!shortArrayCompare(result, target, sigSize))
		puts(" : Passed");
	else
		puts(" : Failed");
		
	return 0;
}
