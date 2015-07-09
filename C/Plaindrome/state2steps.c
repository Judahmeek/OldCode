/*determines the number of steps a given state[] is away from the "minimal state" based on the given freq[].
The "minimal state" is the state created by step 0. Example: Freq[2,2,2,1] => Result[a,a,b,b,c,c,d].
*/
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
