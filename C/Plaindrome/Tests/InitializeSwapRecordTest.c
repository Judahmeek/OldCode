//#define DEBUG
#include "../digitSize_i.c"
#include "../InitializeSwapRecord.c"
#ifndef DEBUG
#include "../IO/printTitledShortArray.c"
#include "../IO/printIntArray.c"
#endif

int main(){
	short freq[] = {2, 2, 1};
	short freqSize = 3, stateSize = 5;
	int i = 0;
	
	int tscs = 0; //tscs stands for total state changing ints
	for(i = 0; i < freqSize; ++i){
		tscs += freq[i] * (stateSize - freq[i]);
	}
	tscs /= 2;
		
	int totalStates = factorial(stateSize)/arrayFactorial(freq, freqSize, 0, 0);
	short width = digitSize_i(totalStates);
	short result[stateSize];
	
	short** states = (short **)malloc(sizeof(short *) * totalStates);
    states[0] = (short *)malloc(sizeof(short) * totalStates * stateSize);
    for(i = 0; i < totalStates; ++i)
        states[i] = (*states + stateSize * i);
	
	short** bufferSig = (short **)malloc(sizeof(short *) * totalStates);
    bufferSig[0] = (short *)malloc(sizeof(short) * totalStates * stateSize);
    for(i = 0; i < totalStates; ++i)
        bufferSig[i] = (*bufferSig + stateSize * i);
    
	int** swapRecord = InitializeSwapRecord(freq, freqSize, bufferSig, states, stateSize, totalStates, tscs);
	
	for(i = 0; i < totalStates; ++i){
        printf("Steps: %*d -> ", width, i);
		steps2state(freq, freqSize, result, stateSize, i);
		printTitledShortArray("Result: ", result, stateSize, 0);
		putchar('\t');
		printf("swapRecord[%d]: ", i);
		printIntArray(swapRecord[i], tscs);
		putchar('\n');
	}
	return 0;
}
