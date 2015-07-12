#include "../IO/printTitledIntArray.c"
#include "../arraySum.c"
#include "../intArrayCompare.c"
#include "../promotionSignature.c"

int main() {
	short freq[] = {3, 2, 2};
	short freqSize = 3;
	short startingIndex = 0;
	short resultSize = arraySum(freq, 3) - 1;
	int result[resultSize];
	int target[] = {90, 30, 6, 3, 1, 1};
	
	--freq[0];	
	promotionSignature(freq, freqSize, result, resultSize, startingIndex);
	
	printTitledIntArray("promotionSignature(freq: ", freq, freqSize, 0);
	printf(", freqSize: %d, result[], resultSize: %d, startingIndex: %d) == ", freqSize, resultSize, startingIndex);
	printIntArray(target, resultSize);
	
	if(!intArrayCompare(result, target, resultSize))
		puts(" : Passed");
	else
		puts(" : Failed");
		
	return 0;
}
