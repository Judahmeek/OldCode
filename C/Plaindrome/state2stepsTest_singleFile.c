//Single source file for online compiling
//Successfully compiled at http://www.codechef.com/ide (gcc-4.9.2)
#include <stdio.h>

short arraySum (const short x[], short size){
	int total = 0;
	short i;
	for(i = 0; i < size; ++i){
		total += x[i];
	}
	return total;
};

void printShortArray (const char* x, const short y[], short size){
	fputs(x, stdout);
	short i;
	for(i = 0; i < size; ++i)
        printf("%d ", y[i]);
    puts("");
};

int factorial(short x){
	int y = 1;
	while(x > 1){
		y *= x;
		--x;
	}
	return y;
};

int arrayFactorial(const short x[], short size, short startingIndex, short minus){ //~7/1-17:00 returns sum of each element's factorial O(N)
	short i = startingIndex;
	int total = factorial(x[i++] - minus);
	while(i < size){
		total *= factorial(x[i++]);
	}
	return total;
};

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

short state2steps(const short freq[], short freqSize, short state[], short stateSize){
	
	short copy[freqSize];
	short i = 0;
	for(i = 0; i < freqSize; ++i){
		copy[i] = freq[i];
	}
	--copy[0];
	
	short zeroState[stateSize];
	steps2state(freq, freqSize, zeroState, stateSize, 0);
	
	short steps = 0;
	short sigSize = stateSize - 1;
	int sig[sigSize];
	promotionSignature(copy, freqSize, sig, sigSize, 0);
	
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

int main() {
	const short freq[] = {2, 2, 2, 1};
	short freqSize = 4;
	short stateSize = arraySum(freq, freqSize);
	short uBound = factorial(stateSize)/arrayFactorial(freq, freqSize, 0, 0);
	short result[stateSize];
	short steps, steps2, input;
	for(steps = 0;steps < uBound; ++steps){
		steps2state(freq, freqSize, result, stateSize, steps);
		printShortArray("State: ", result, stateSize);
		steps2 = state2steps(freq, freqSize, result, stateSize);
		printf("Steps: %d\n", steps2);
	}
	return 0;
}
