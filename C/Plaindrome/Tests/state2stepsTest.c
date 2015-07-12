#include "../IO/printTitledShortArray.c"
#include "../findMaxPowOf10_i.c"
#include "../arraySum.c"
#include "../state2steps.c"

int main() {
	const short freq[] = {2, 2, 2, 1};
	short freqSize = 4;
	short stateSize = arraySum(freq, freqSize);
	short uBound = factorial(stateSize)/arrayFactorial(freq, freqSize, 0, 0);
	short result[stateSize];
	short input = 0, width = findMaxPowOf10_i(uBound);
	int steps, steps2;
	for(steps = 0;steps < uBound; ++steps){
		printf("Steps: %*d -> ", width, steps);
		steps2state(freq, freqSize, result, stateSize, steps);
		printTitledShortArray("Result: ", result, stateSize, 0);
		steps2 = state2steps(freq, freqSize, result, stateSize);
		printf(" -> Steps: %*d\n", width, steps2);
		if(steps % 10 == 0){
			printf("Press enter to continue...");
			while(input != '\n')
    			input = getchar();
    		input = 'x';
		}
	}
	return 0;
}
