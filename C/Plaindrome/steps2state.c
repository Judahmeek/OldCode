#ifndef STEPS2STATE
#define STEPS2STATE

#ifdef DEBUGSTEPS2STATE
	#include "./IO/printTitledShortArray.c"
	#include "./IO/printIntArray.c"
	#include "./IO/systemPause.c"
#endif

#include "promotionSignature.c"

/*converts result[] into an anagram of the palindrome based on the given freq[] and steps.
The purpose of this function is to convert a state that is referenced by the number of steps between it and the "minimal state" back into a string.
The "minimal state" is the state created by step 0. Example: Freq[2,2,2,1] => Result[a,a,b,b,c,c,d].
*/
void steps2state(const short freq[], short freqSize, short result[], short stateSize, int steps){
	short sigSize = stateSize - 1;
	int sig[sigSize];
	short i = 0, j = 0, target = 0;
	
	short copy[freqSize];
	for(i = 0; i < freqSize; ++i){
		copy[i] = freq[i];
	}
	
	--copy[0];
	promotionSignature(copy, freqSize, sig, sigSize, 0);
	
	#ifdef DEBUGSTEPS2STATE
		fputs("After initial pSig: ", stdout);
		fputs("state2steps(copy: ", stdout);
		printShortArray(copy, freqSize);
		printf(",freqSize: %d, sig: ", freqSize);
		printIntArray(sig, sigSize);
		printf(", sigSize: %d)\n", sigSize);
	#endif
	
    for(i = 0; i < sigSize; ++i){
    	while( steps >= sig[i]){
    		#ifdef DEBUGSTEPS2STATE
				printf("Steps: %d >= sig[%d]: %d\n", steps, i, sig[i]);
			#endif
    		steps -= sig[i];
    		#ifdef DEBUGSTEPS2STATE
				printf("Steps - sig[i] = %d\nTarget: %d, ", steps, target);
				printTitledShortArray("Copy[] before: ", copy, freqSize, 1);
			#endif
    		++copy[target];
    		++target;
			if(target == freqSize)
				target = 0;
			while(copy[target] == 0){
				++target;
				if(target == freqSize)
					target = 0;
			}
    		--copy[target];
    		
    		#ifdef DEBUGSTEPS2STATE
				printf("Target: %d, ", target);
				printTitledShortArray("Copy[] after: ", copy, freqSize, 1);
			#endif
			
			promotionSignature(copy, freqSize, sig, sigSize, i);
			
			#ifdef DEBUGSTEPS2STATE
				fputs("After following pSig: ", stdout);
				fputs("promotionSignature(copy: ", stdout);
				printShortArray(copy, freqSize);
				printf(",freqSize: %d, pSig: ", freqSize);
				printIntArray(sig, sigSize);
				printf(", sigSize: %d, i: %d)\n", sigSize, i);
				#ifdef ENABLEPAUSE
					systemPause();
				#endif
			#endif
		}
		j = 0;
		while(copy[j] == 0){
			++j;
		}
		result[i] = target;
		target = j;
		--copy[j];
		
		#ifdef DEBUGSTEPS2STATE
			printTitledShortArray("Developing step2state: ", result, stateSize, 1);
		#endif
	}
	result[sigSize] = target;
};

#endif //STEPS2STATE
