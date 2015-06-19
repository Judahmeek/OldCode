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
NOTE TO SELF: We need to look into what signature should be provided should the input Anagrom of Palindrome be all the same values. Example: [a,a,a,a,a,a]*/
void signature (const short freq[], short freqSize, int result[], short resultSize, short start){
	short i, j = 0;
	short remainingDigits = resultSize - (start + 1);
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

/*converts result[] into an anagram of the palindrome based the given freq[] and steps.
The purpose of this function is to convert a state that is referenced by the number of steps between it and the "minimal state" back into a string.
The "minimal state" is the state created by step 0. Example: Freq[2,2,2,1] => Result[a,a,b,b,c,c,d].
This conversion is required in order to compare two states and calculate whether travel between the two states is possible with a single swap.
*/
void step(const short freq[], short freqSize, short result[], short resultSize, short steps){
	short sigSize = resultSize - 1;
	int sig[sigSize];
	short i = 0, j = 0, target = 0;
	
	short copy[freqSize];
	for(i = 0; i < freqSize; ++i){
		copy[i] = freq[i];
	}
	
	--copy[0];
	signature(copy, freqSize, sig, resultSize, 0);
    for(i = 0; i < sigSize; ++i){
    	while( steps >= sig[i]){
    		steps -= sig[i];
    		++copy[target];
    		++target;
			while(copy[target] == 0){
				++target;
			}
    		--copy[target];
			signature(copy, freqSize, sig, resultSize, i);
			j = 0;
			while(copy[j] == 0){
				++j;
			}
		}
		while(copy[j] == 0){
			++j;
		}
		result[i] = target + 'a';
		target = j;
		--copy[j];
	}
	result[sigSize] = target + 'a';
}
