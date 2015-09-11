#define DEBUGPROMOTIONSIGNATURE
#include "../IO/printTitledShortArray.c"
#include "../IO/printIntArray.c"
#include "../promotionSignature.c"

int main() {
	short freq[] = {1, 0, 2, 1};
	short freqSize = 4;
	short startingIndex = 2;
	short resultSize = 6;
	int result[resultSize];
		
	promotionSignature(freq, freqSize, result, resultSize, startingIndex);
	
	printTitledShortArray("promotionSignature(freq: ", freq, freqSize, 0);
	printf(", freqSize: %d, result[], resultSize: %d, startingIndex: %d) == ", freqSize, resultSize, startingIndex);
	printIntArray(result, resultSize);
		
	return 0;
}
