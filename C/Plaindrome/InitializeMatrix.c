#include "InitializeSwapRecord.c"

double ** initializeMatrix(const short freq[], short freqSize, short stateSize, int totalStates, int tscs, int posSwaps){
	
	int i;
	int swapsThatMaintainState = (posSwaps - tscs);
	double stmsPercentageOfPosSwaps = swapsThatMaintainState/posSwaps;
	double singleSwapsPercentageOfPosSwaps = 1/posSwaps;
	
	double** markovMatrix = (double **)malloc(sizeof(double *) * totalStates);
    markovMatrix[0] = (double *)malloc(sizeof(double) * totalStates * totalStates);
    for(i = 0; i < totalStates; ++i)
        markovMatrix[i] = (*markovMatrix + totalStates * i);
	
	int** swapRecord = InitializeSwapRecord(freq, freqSize, stateSize, totalStates, tscs);
    
    #ifdef DEBUG
	for(i = 0; i < totalStates; ++i){
		printf("swapRecord[%d]: ", i);
		printIntArray(swapRecord[i], tscs);
		putchar('\n');
	}
	#endif
	
	short swapRecordIndex;
	for(i = 0; i < totalStates; ++i){
        markovMatrix[i][i] = stmsPercentageOfPosSwaps;
        for(swapRecordIndex = 0; swapRecordIndex < tscs; ++swapRecordIndex){
        	#ifdef DEBUG
        	printf("markovMatrix[%d][swapRecord[%d][%d]: %d] = %d;\n", i, i, swapRecordIndex, swapRecord[i][swapRecordIndex], singleSwapsPercentageOfPosSwaps);
        	#endif
        	markovMatrix[i][swapRecord[i][swapRecordIndex]] = singleSwapsPercentageOfPosSwaps;
		}
	}
	return markovMatrix;
}
