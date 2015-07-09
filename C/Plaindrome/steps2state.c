#include "promotionSignature.c"

/*converts result[] into an anagram of the palindrome based on the given freq[] and steps.
The purpose of this function is to convert a state that is referenced by the number of steps between it and the "minimal state" back into a string.
The "minimal state" is the state created by step 0. Example: Freq[2,2,2,1] => Result[a,a,b,b,c,c,d].
*/
void steps2state(const short freq[], short freqSize, short result[], short resultSize, short steps){
	short sigSize = resultSize - 1;
	int sig[sigSize];
	short i = 0, j = 0, target = 0;
	
	short copy[freqSize];
	for(i = 0; i < freqSize; ++i){
		copy[i] = freq[i];
	}
	
	--copy[0];
	promotionSignature(copy, freqSize, sig, sigSize, 0);
    for(i = 0; i < sigSize; ++i){
    	while( steps >= sig[i]){
    		steps -= sig[i];
    		++copy[target];
    		++target;
			while(copy[target] == 0){
				++target;
			}
    		--copy[target];
			promotionSignature(copy, freqSize, sig, sigSize, i);
		}
		j = 0;
		while(copy[j] == 0){
			++j;
		}
		result[i] = target;
		target = j;
		--copy[j];
	}
	result[sigSize] = target;
};
