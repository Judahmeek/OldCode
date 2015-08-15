#include "../digitSize_i.c"
#include "../swapRecord.c"

int main(){
	short freq[] = {2, 2, 1};
	short freqSize = 3, stateSize = 5;
	int i = 0;
	
	short tscs = 0; //tscs stands for total state changing swaps
	for(i = 0; i < freqSize; ++i){
		tscs += freq[i] * (stateSize - freq[i]);
	}
	tscs /= 2;
		
	int totalStates = factorial(stateSize)/arrayFactorial(freq, freqSize, 0, 0);
	short width = digitSize_i(totalStates);
	short result[stateSize];
	
	swap** swapR = swapRecord(freq, freqSize, stateSize, totalStates, tscs);
	for(i = 0; i < totalStates; ++i){
        swapR[i] = (*swapR + tscs * i * sizeof(int));
        printf("Steps: %*d -> ", width, i);
		steps2state(freq, freqSize, result, stateSize, i);
		printTitledShortArray("Result: ", result, stateSize, 0);
		putchar('\t');
		printf("swapRecord[%d]: ", i);
		printSwapArray(swapR[i], tscs);
		putchar('\n');
	}
	return 0;
}
