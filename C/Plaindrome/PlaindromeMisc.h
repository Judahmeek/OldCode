int fact(short x){
	int y = 1;
	while(x > 1){
		y *= x;
		--x;
	}
	return y;
};

int arrayFact (const short x[], short size, short start){ //returns sum of each element's factorial
	int total = 1;
	short i;
	for(i = start; i < size; ++i){
		total *= fact(x[i]);
	}
	return total;
};

short arraySum (const short x[], short size){
	int total = 0;
	short i;
	for(i = 0; i < size; ++i){
		total += x[i];
	}
	return total;
};

/*creates an array that shows the number of steps required to promote a letter in the same digit.
Example: [a, a, b] has the signature of [2, 1] because promoting a[0] requires going through both combinations of a[1] and a[2] while promoting a[1] merely requires switching a[1] and a[2].
If start != 0, then freq[] must be modified accordingly.*/
void signature (const short freq[], short freqSize, int result[], short resultSize, short start){ //~6/22-00:37
	short i, j = 0;
	short remainingDigits = resultSize - start;
	short copy[freqSize];
	for(i = 0; i < freqSize; ++i){
		copy[i] = freq[i];
	}
	
	for(i = 0; i < start; ++i){
		result[i] = -1;
	}
	
	for(i = start; i < resultSize; ++i){
		result[i] = fact(remainingDigits) / arrayFact(copy, freqSize, j);
		while(copy[j] == 0)
			++j;
		--copy[j];
		--remainingDigits;
	}
};

/*converts result[] into an anagram of the palindrome based on the given freq[] and steps.
The purpose of this function is to convert a state that is referenced by the number of steps between it and the "minimal state" back into a string.
The "minimal state" is the state created by step 0. Example: Freq[2,2,2,1] => Result[a,a,b,b,c,c,d].
*/
void steps2state(const short freq[], short freqSize, short result[], short resultSize, short steps){ //~6/22-00:37
	short sigSize = resultSize - 1;
	int sig[sigSize];
	short i = 0, j = 0, target = 0;
	
	short copy[freqSize];
	for(i = 0; i < freqSize; ++i){
		copy[i] = freq[i];
	}
	
	--copy[0];
	signature(copy, freqSize, sig, sigSize, 0);
    for(i = 0; i < sigSize; ++i){
    	while( steps >= sig[i]){
    		steps -= sig[i];
    		++copy[target];
    		++target;
			while(copy[target] == 0){
				++target;
			}
    		--copy[target];
			signature(copy, freqSize, sig, sigSize, i);
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
int state2steps(const short freq[], short freqSize, short state[], short stateSize){ //~6/22-00:37
	
	short copy[freqSize];
	short i = 0;
	for(i = 0; i < freqSize; ++i){
		copy[i] = freq[i];
	}
	--copy[0];
	
	short minState[stateSize];
	steps2state(freq, freqSize, minState, stateSize, 0); //Create min state
	
	int steps = 0;
	short sigSize = stateSize - 1;
	int sig[sigSize];
	signature(copy, freqSize, sig, sigSize, 0); //Create min state signature
	
	for(i = 0; i < sigSize;){
		if(state[i] == minState[i]){
			--copy[minState[i + 1]];
			++i;
		} else {
			steps += sig[i];
			++copy[minState[i]];
    		++minState[i];
			while(copy[minState[i]] == 0){
				++minState[i];
			}
    		--copy[minState[i]];
			signature(copy, freqSize, sig, sigSize, i);
			short k = i, l, m;
			for(l = 0; l < freqSize; ++l){
				for(m = 0; m < copy[l]; ++m){
					minState[++k] = l;
				}
			}
		}
	}
	
	return steps;
};
