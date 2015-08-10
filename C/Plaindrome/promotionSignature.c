#ifndef PROMOTIONSIGNATURE
#define PROMOTIONSIGNATURE

#include "arrayFactorial.c"

/*creates an array that shows the number of steps required to promote a letter in the same digit.
Example: [a, a, b] has the signature of [2, 1] because promoting a[0] requires going through both combinations of a[1] and a[2] while promoting a[1] merely requires switching a[1] and a[2].*/
void promotionSignature (const short freq[], short freqSize, int result[], short resultSize, short startingIndex){
	short i, j = 0, k = 0;
	while(freq[j] == 0){
			++j;
	}
	
	short remainingDigits = resultSize - startingIndex;
	
	for(i = 0; i < startingIndex; ++i){
		result[i] = -1;
	}
	for(; i < resultSize; ++i){
		result[i] = factorial(remainingDigits) / arrayFactorial(freq, freqSize, j, k);
		if(!result[i])
			++result[i];
		++k;
		if(k == freq[j]){
			++j;
			k = 0;
		}
		--remainingDigits;
	}
};
#endif //PROMOTIONSIGNATURE