#include "InitializeSwapRecord.c"

InitializeMatrix(const short freq, short freqSize[], short stateSize, int totalStates, int tscs, int posSwaps){
	
	swapsThatMaintainState = (posSwaps - tscs);
	double stmsPercentageOfPosSwaps = swapsThatMaintainState/posSwaps;
	double singleSwapsPercentageOfPosSwaps = 1/posSwaps;
	
	double** markovMatrix = (double **)malloc(sizeof(double *) * totalStates);
    markovMatrix[0] = (double *)malloc(sizeof(double) * totalStates * totalStates);
    for(i = 0; i < totalStates; ++i)
        markovMatrix[i] = (*markovMatrix + totalStates * i);
	
	int** swapRecord = InitializeSwapRecord(freq, freqSize, stateSize, totalStates, tscs);
	
	short swapRecordIndex;
	for(i = 0; i < totalStates; ++i){//for each row
        swapR[i] = (*swapR + tscs * i * sizeof(int));
        markovMatrix[i][i] = stmsPercentageOfPosSwaps;
        for(swapRecordIndex = 0; swapRecordIndex < tscs; ++swapRecordIndex){
        	markovMatrix[i][swapRecord[swapRecordIndex]] = singleSwapsPercentageOfPosSwaps;
		}
	}
}
