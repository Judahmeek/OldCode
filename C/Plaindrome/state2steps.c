#ifndef STATE2STEPS
#define STATE2STEPS

#ifdef DEBUGSTATE2STEPS
#include "./IO/printShortArray.c"
#include "./IO/printIntArray.c"
//#include "./IO/systemPause.c"
#endif

#include "steps2state.c"

/*determines the number of steps a given state[] is away from the "minimal state" based on the given freq[].
The "minimal state" is the state created by step 0. Example: Freq[2,2,2,1] => Result[a,a,b,b,c,c,d].
*/
int state2steps(const short freq[], short freqSize, short state[], short stateSize){
	
	#ifdef DEBUGSTATE2STEPS
	fputs("state2steps(freq: ", stdout);
	printShortArray(freq, freqSize);
	printf(",freqSize: %d, state: ", freqSize);
	printShortArray(state, stateSize);
	printf(", stateSize: %d)\n", stateSize);
	//systemPause();
	#endif
	
	short copy[freqSize];
	short i = 0;
	for(i = 0; i < freqSize; ++i){
		copy[i] = freq[i];
	}
	--copy[0];
	
	short zeroState[stateSize];
	steps2state(freq, freqSize, zeroState, stateSize, 0);
	
	#ifdef DEBUGSTATE2STEPS
	fputs("steps2state(copy: ", stdout);
	printShortArray(copy, freqSize);
	printf(",freqSize: %d, zeroState: ", freqSize);
	printShortArray(zeroState, stateSize);
	printf(", stateSize: %d)\n", stateSize);
	//systemPause();
	#endif
	
	int steps = 0;
	short sigSize = stateSize - 1;
	int sig[sigSize];
	promotionSignature(copy, freqSize, sig, sigSize, 0);
	
	#ifdef DEBUGSTATE2STEPS
	fputs("After initial pSig: ", stdout);
	fputs("state2steps(copy: ", stdout);
	printShortArray(copy, freqSize);
	printf(",freqSize: %d, sig: ", freqSize);
	printIntArray(sig, sigSize);
	printf(", sigSize: %d)\n", sigSize);
	//systemPause();
	#endif
	
	for(i = 0; i < sigSize;){
		if(state[i] == zeroState[i]){
			--copy[zeroState[++i]];
		} else {
			steps += sig[i];
			++copy[zeroState[i]];
    		++zeroState[i];
			while(copy[zeroState[i]] == 0){
				++zeroState[i];
			}
    		--copy[zeroState[i]];
			promotionSignature(copy, freqSize, sig, sigSize, i);
			
			#ifdef DEBUGSTATE2STEPS
			fputs("After following pSig: ", stdout);
			fputs("promotionSignature(copy: ", stdout);
			printShortArray(copy, freqSize);
			printf(",freqSize: %d, pSig: ", freqSize);
			printIntArray(sig, sigSize);
			printf(", sigSize: %d, i: %d)\n", sigSize, i);
			//systemPause();
			#endif
			
			short k = i, l, m;
			for(l = 0; l < freqSize; ++l){
				for(m = 0; m < copy[l]; ++m){
					zeroState[++k] = l;
				}
			}
		}
	}
	
	return steps;
};

#endif //STATE2STEPS
