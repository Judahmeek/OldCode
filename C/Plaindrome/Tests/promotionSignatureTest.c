#include <stdio.h>
#include "arraySum.c"
#include "arrayCompare.c"
#include "promotionSignature.c"

int main() {
	short freq[] = {3, 2, 2};
	short freqSize = 3;
	short startingIndex = 0;
	short resultSize = arraySum(freq, 3) - 1;
	int result[resultSize];
	int target[] = {90, 30, 6, 3, 1, 1};
	--freq[0];
	
	promotionSignature(freq, freqSize, result, resultSize, startingIndex);
	
	if(!intArrayCompare(result, target, resultSize))
		puts("promotionSignature(freq: {2, 2, 2}, freqSize: 3, result[], resultSize: 3, startingIndex: 0) == {90, 30, 6, 3, 1, 1} : Passed");
	else
		puts("promotionSignature(freq: {2, 2, 2}, freqSize: 3, result[], resultSize: 3, startingIndex: 0) == {90, 30, 6, 3, 1, 1} : Failed");
		
	return 0;
}
