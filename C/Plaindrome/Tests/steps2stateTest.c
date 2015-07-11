#include <stdio.h>
#include "arraySum.c"
#include "arrayOutput.h"
#include "steps2state.c"

int main() {
	const short freq[] = {2, 2, 2, 1};
	short freqSize = 4;
	short stateSize = arraySum(freq, freqSize);
	short uBound = factorial(stateSize)/arrayFactorial(freq, freqSize, 0, 0);
	short result[stateSize];
	short steps, input = 0;
	for(steps = 0;steps < uBound; ++steps){
		printf("Steps: %d -> ", steps);
		steps2state(freq, freqSize, result, stateSize, steps);
		printShortArray("Result: ", result, stateSize);
		if(steps % 10 == 0){
			printf("Press enter to continue...");
			while(input != '\n')
    			input = getchar();
    		input = 0;
    	}
	}
	return 0;
}
