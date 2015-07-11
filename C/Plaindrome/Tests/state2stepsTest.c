#include <stdio.h>
#include "arraySum.c"
#include "printArray.h"
#include "steps2state.c"
#include "state2steps.c"

int main() {
	const short freq[] = {2, 2, 2, 1};
	short freqSize = 4;
	short stateSize = arraySum(freq, freqSize);
	short uBound = factorial(stateSize)/arrayFactorial(freq, freqSize, 0, 0);
	short result[stateSize];
	short steps, steps2, input;
	for(steps = 0;steps < uBound; ++steps){
		steps2state(freq, freqSize, result, stateSize, steps);
		printShortArray("Result: ", result, stateSize);
		steps2 = state2steps(freq, freqSize, result, stateSize);
		printf("Steps: %d\n", steps2);
		if(steps % 10 == 0){
			printf("Press enter to continue...");
			while(input != '\n')
    			input = getchar();
    		input = 'x';
		}
	}
	return 0;
}
