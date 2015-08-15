#include "../IO/printTitledShortArray.c"
#include "../digitSize_i.c"
#include "../arraySum.c"
#include "../steps2state.c"

int main() {
	const short freq[] = {2, 2, 1};
	short freqSize = 3;
	short stateSize = arraySum(freq, freqSize);
	int uBound = factorial(stateSize)/arrayFactorial(freq, freqSize, 0, 0);
	short result[stateSize];
	short input = 0, width = digitSize_i(uBound);
	int steps;
	for(steps = 0;steps < uBound; ++steps){
		printf("Steps: %*d -> ", width, steps);
		steps2state(freq, freqSize, result, stateSize, steps);
		printTitledShortArray("Result: ", result, stateSize, 1);
		if(steps % 10 == 0){
			printf("Press enter to continue...");
			while(input != '\n')
    			input = getchar();
    		input = 0;
    	}
	}
	return 0;
}
