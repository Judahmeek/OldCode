#include "initializeSwapRecord.c"
#include "./IO/displayMatrix.c"
#include "./IO/printIntArray.c"
#ifdef DEBUG
#include "./IO/systemPause.c"
#endif

double ** initializeMatrix(const short freq[], short freqSize, short stateSize, int totalStates, int tscs, int posSwaps){
	
	int i;
	int swapsThatMaintainState = (posSwaps - tscs);
	double stmsPercentageOfPosSwaps = (double)swapsThatMaintainState/(double)posSwaps;
	double singleSwapsPercentageOfPosSwaps = 1.0/(double)posSwaps;
	
	#ifdef BASICS
	printf("swapsThatMaintainState: %d\n", swapsThatMaintainState);
	printf("swapsThatMaintainState /  posSwaps: %f\n", stmsPercentageOfPosSwaps);
	printf("1 / posSwaps: %f\n", singleSwapsPercentageOfPosSwaps);
	#endif
	
	double** markovMatrix = (double **)calloc(totalStates, sizeof(double *));
    markovMatrix[0] = (double *)calloc(totalStates * totalStates, sizeof(double));
    for(i = 0; i < totalStates; ++i)
        markovMatrix[i] = (*markovMatrix + totalStates * i);
	
	int** swapRecord = initializeSwapRecord(freq, freqSize, stateSize, totalStates, tscs);
    
    #ifdef DEBUG
	for(i = 0; i < totalStates; ++i){
		printf("swapRecord[%d]: ", i);
		printIntArray(swapRecord[i], tscs);
		putchar('\n');
	}
	systemPause();
	#endif
	
	short swapRecordIndex;
	for(i = 0; i < totalStates; ++i){
        markovMatrix[i][i] = stmsPercentageOfPosSwaps;
        for(swapRecordIndex = 0; swapRecordIndex < tscs; ++swapRecordIndex){
        	#ifdef DEBUG
        	if(i > -1 && i < 1)
        		printf("markovMatrix[%d][swapRecord[%d][%d]: %d] = %f;\n", i, i, swapRecordIndex, swapRecord[i][swapRecordIndex], singleSwapsPercentageOfPosSwaps);
        	#endif
        	markovMatrix[i][swapRecord[i][swapRecordIndex]] = singleSwapsPercentageOfPosSwaps;
		}
	#ifdef DEBUG
	//systemPause();
	#endif
	}
	
	#ifdef BASICS
	displayMatrix(markovMatrix[0], totalStates, 2);
	#endif
	
	return markovMatrix;
}
