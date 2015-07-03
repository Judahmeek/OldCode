//Complexity calculation note: freqSize is upperbounded at 26. max(freq) is upperbounded at stateSize.

int fact(short x){ //O(N)
	int y = 1;
	while(x > 1){
		y *= x;
		--x;
	}
	return y;
};

int arrayFact (const short x[], short size, short startingIndex, short minus){ //~7/1-17:00 returns sum of each element's factorial O(N)
	short i = startingIndex;
	int total = fact(x[i++] - minus);
	while(i < size){
		total *= fact(x[i++]);
	}
	return total;
};

short arraySum (const short x[], short size){ //O(N)
	int total = 0;
	short i;
	for(i = 0; i < size; ++i){
		total += x[i];
	}
	return total;
};

/*creates an array that shows the number of steps required to promote a letter in the same digit.
Example: [a, a, b] has the signature of [2, 1] because promoting a[0] requires going through both combinations of a[1] and a[2] while promoting a[1] merely requires switching a[1] and a[2].*/
void promotionSignature (const short freq[], short freqSize, int result[], short resultSize, short startingIndex){ //~7/1-17:00 O(N^2)
	short i, j = 0, k = 0;
	while(freq[j] == 0){
			++j;
	}
	
	short remainingDigits = resultSize - startingIndex;
	
	for(i = 0; i < startingIndex; ++i){ //O(N)
		result[i] = -1;
	}
	for(; i < resultSize; ++i){ //O(N * N) = O(N^2)
		result[i] = fact(remainingDigits) / arrayFact(freq, freqSize, j, k); //O(N) + O(N) = O(N)
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

/*converts result[] into an anagram of the palindrome based on the given freq[] and steps.
The purpose of this function is to convert a state that is referenced by the number of steps between it and the "minimal state" back into a string.
The "minimal state" is the state created by step 0. Example: Freq[2,2,2,1] => Result[a,a,b,b,c,c,d].
*/
void steps2state(const short freq[], short freqSize, short result[], short resultSize, short steps){ //~7/1-17:00
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

/*determines the number of steps a given state[] is away from the "minimal state" based on the given freq[].
The "minimal state" is the state created by step 0. Example: Freq[2,2,2,1] => Result[a,a,b,b,c,c,d].
*/
short state2steps(const short freq[], short freqSize, short state[], short stateSize){ //~7/1-17:00
	
	short copy[freqSize];
	short i = 0;
	for(i = 0; i < freqSize; ++i){
		copy[i] = freq[i];
	}
	--copy[0];
	
	short zeroState[stateSize];
	steps2state(freq, freqSize, zeroState, stateSize, 0); //Create zero state
	
	short steps = 0;
	short sigSize = stateSize - 1;
	int sig[sigSize];
	promotionSignature(copy, freqSize, sig, sigSize, 0); //Create zero state signature
	
	for(i = 0; i < sigSize;){
		if(state[i] == zeroState[i]){
			--copy[zeroState[i + 1]];
			++i;
		} else {
			steps += sig[i];
			++copy[zeroState[i]];
    		++zeroState[i];
			while(copy[zeroState[i]] == 0){
				++zeroState[i];
			}
    		--copy[zeroState[i]];
			promotionSignature(copy, freqSize, sig, sigSize, i);
			short k = i, l, m;
			for(l = 0; l < freqSize; ++l){
				for(m = 0; m < copy[l]; ++m){
					zeroState[++k] = l;
				}
			}
		}
	}
	
	return steps;
}
