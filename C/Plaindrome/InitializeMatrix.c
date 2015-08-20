#include "swap.c"
#include "InitializeSwapRecord.c"

InitializeMatrix(const short freq, short freqSize[], short stateSize, double** MarkovMatrix, int totalStates, int tscs){
	
	swap** swapRecord = InitializeSwapRecord(freq, freqSize, stateSize, totalStates, tscs); //pull both scanRecord and bufferRecord out?
	
	for(i = 0; i < totalStates; ++i){
        swapR[i] = (*swapR + tscs * i * sizeof(int));
        ...
    }
}
