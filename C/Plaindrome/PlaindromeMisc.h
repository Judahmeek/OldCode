//Complexity calculation note: freqSize is upperbounded at 26. max(freq) is upperbounded at stateSize.

int fact(short x){ //O(N)
	int y = 1;
	while(x > 1){
		y *= x;
		--x;
	}
	return y;
};

int arrayFact (const short x[], short size, short start){ //returns sum of each element's factorial O(N)
	int total = 1;
	short i;
	for(i = start; i < size; ++i){
		total *= fact(x[i]);
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
Example: [a, a, b] has the signature of [2, 1] because promoting a[0] requires going through both combinations of a[1] and a[2] while promoting a[1] merely requires switching a[1] and a[2].
If start != 0, then freq[] must be modified accordingly.*/
void promotionSignature (const short freq[], short freqSize, int result[], short resultSize, short start){ //~6/22-00:37 O(N^2)
	short i, j = 0;
	short remainingDigits = resultSize - start;
	short copy[freqSize];
	for(i = 0; i < freqSize; ++i){ //O(C)
		copy[i] = freq[i];
	}
	
	for(i = 0; i < start; ++i){ //O(N)
		result[i] = -1;
	}
	
	for(i = start; i < resultSize; ++i){ //O(N * N) = O(N^2)
		result[i] = fact(remainingDigits) / arrayFact(copy, freqSize, j); //O(N) + O(N) = O(N)
		if(!result[i])
			++result[i];
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
void steps2state(const short freq[], short freqSize, short result[], short resultSize, short steps){ //~6/22-00:37 O(N^3)
	short sigSize = resultSize - 1;
	int sig[sigSize];
	short i = 0, j = 0, target = 0;
	
	short copy[freqSize];
	for(i = 0; i < freqSize; ++i){
		copy[i] = freq[i];
	}
	
	--copy[0];
	signature(copy, freqSize, sig, sigSize, 0); //O(N^2)
    for(i = 0; i < sigSize; ++i){ //O(N^3)
    	while( steps >= sig[i]){
    		steps -= sig[i];
    		++copy[target];
    		++target;
			while(copy[target] == 0){
				++target;
			}
    		--copy[target];
			signature(copy, freqSize, sig, sigSize, i); //O(N^2)
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
int state2steps(const short freq[], short freqSize, short state[], short stateSize){ //~6/22-00:37 O(N^3)
	
	short copy[freqSize];
	short i = 0;
	for(i = 0; i < freqSize; ++i){
		copy[i] = freq[i];
	}
	--copy[0];
	
	short minState[stateSize];
	steps2state(freq, freqSize, minState, stateSize, 0); //Create min state //O(N^3)
	
	int steps = 0;
	short sigSize = stateSize - 1;
	int sig[sigSize];
	signature(copy, freqSize, sig, sigSize, 0); //Create min state signature O(N^2)
	
	for(i = 0; i < sigSize;){ //O(N^3)
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
			signature(copy, freqSize, sig, sigSize, i); //O(N^2)
			short k = i, l, m;
			for(l = 0; l < freqSize; ++l){ //O(N)
				for(m = 0; m < copy[l]; ++m){
					minState[++k] = l;
				}
			}
		}
	}
	
	return steps;
};

struct link
{
   int  stateID;
   int  index;
}; 

void CreateMarkovMatrix(const short freq, short freqSize[],short stateSize,double** MarkovMatrix,int totalStates,int index,int tscs) //~6/30-11:40
{
	int o, i;
	link stateSwaps[totalStates][tscs];
	
	for(o = 0; o < totalStates; o++){
		for(i = 0; i < tscs; i++){
			stateSwaps[o][i].stateID = -1;
			stateSwaps[o][i].index = -1;
		}
	}
	
	int targetDigit, c, t;
	short baseState[stateSize];
	short swapState[stateSize];
	for(o = 0; o < totalStates; o++){ //O(tS * (S^3 + tscs * (S + S^3))) = O(S^S)
    	steps2state(freq, freqSize, baseState, stateSize, o); //O(S^3) ~Doing this for every state is unnecessary if I utilize swapState data from previous baseStates
    	i = 1, targetDigit = 0, c = 0;
    	while(c < tscs){ //O(tscs * S)
    		if(baseState[targetDigit] == baseState[i])
    			++i;
    		else{
    			for(t = 0; t < stateSize; t++) //initialize copy O(S)
    				swapState[t] = baseStatw[t];
    			
    			swapState[targetDigit] = baseState[i]; //perform swap
    			swapState[i] = baseState[targetDigit]; //Should these swapStates be saved? Use memory to reduce processing time?
    			
    			stateSwaps[o][c].stateID = state2steps(freq, freqSize, swapState, stateSize); //ID state O(S^3)
    			stateSwaps[o][c].index = i;
    			
    			++c, ++i;
			}
			
			if(i = stateSize){
				++targetDigit;
				i = targetDigit + 1;
			}
		}
	}
	
	
	
	/*for(i = 0; i < totalStates; i++){
			MarkovMatrix[i] = (*MarkovMatrix + totalStates * i);
			MarkovMatrix[i][0] = (posSwaps - tscs) / posSwaps;
    }
	
	To-Do List: Needs to update swapstate's partner swap record and scan for already detected swaps to minimize use of st2stps*/
}
