#ifdef DEBUGINITIALIZEMATRIX
#include "./IO/systemPause.c"
#endif
#include "initializeSwapRecord.c"
#include "./IO/printDoubleArrayAs2D.c"
#include "./IO/printIntArray.c"
#include "findMatrixRow.c"

/*	To save time, the markov matrix is initiated to I - Q, where I is the identity matrix of the transition matrix Q
*/

double ** initializeMatrix(int** swapRecord, int totalStates, int tscs, int* palList, short numPalindrome, int posSwaps){
	
	int i;
	int swapsThatMaintainState = (posSwaps - tscs);
	double stmsPercentageOfPosSwaps = (double)swapsThatMaintainState/(double)posSwaps;
	double singleSwapsPercentageOfPosSwaps = 1.0/(double)posSwaps;
	
	#ifdef BASICS
	printf("swapsThatMaintainState: %d\n", swapsThatMaintainState);
	printf("swapsThatMaintainState /  posSwaps: %f\n", stmsPercentageOfPosSwaps);
	printf("1 / posSwaps: %f\n", singleSwapsPercentageOfPosSwaps);
	#endif
	
	int transitionMatrixSize = totalStates - numPalindrome;
	double** markovMatrix = (double **)malloc(transitionMatrixSize * sizeof(double *));
    markovMatrix[0] = (double *)calloc(transitionMatrixSize * transitionMatrixSize, sizeof(double));
    for(i = 0; i < transitionMatrixSize; ++i)
        markovMatrix[i] = (markovMatrix[0] + transitionMatrixSize * i);
	
	int j = 0;
	short swapRecordIndex;
	for(i = 0; i < transitionMatrixSize; ++i, ++j){
    	
        while(swapRecord[j][0] == -tscs) //if state == palindrome
        	++j; //move to the next state
        
        markovMatrix[i][findMatrixRow(palList, numPalindrome, j)] = stmsPercentageOfPosSwaps;
    	#ifdef DEBUGINITIALIZEMATRIX
    	if(i == 9) //bounds for limiting what is displayed
        	printf("markovMatrix[%d]findMatrixRow(palList, numPalindrome, %d): %d] = %f;\n", i, j, findMatrixRow(palList, numPalindrome, j), stmsPercentageOfPosSwaps);
    	#endif
        
		if(swapRecord[j][0] < 0)
			swapRecordIndex = -swapRecord[j][0];
		else
			swapRecordIndex = 0;
		
        for(; swapRecordIndex < tscs; ++swapRecordIndex){
        	#ifdef DEBUGINITIALIZEMATRIX
        	if(i == 9){ //bounds for limiting what is displayed
				printf("swapRecord[%d]: ", j);
				printIntArray(swapRecord[j], tscs);
				putchar('\n');
        		printf("markovMatrix[%d]findMatrixRow(palList, numPalindrome, [swapRecord[%d][%d]): %d] = %f;\n", i, j, swapRecordIndex, findMatrixRow(palList, numPalindrome, swapRecord[j][swapRecordIndex]), singleSwapsPercentageOfPosSwaps);
        	}
			#endif
        	markovMatrix[i][findMatrixRow(palList, numPalindrome, swapRecord[j][swapRecordIndex])] = singleSwapsPercentageOfPosSwaps;
		}
	#ifdef DEBUGINITIALIZEMATRIX
	//systemPause();
	#endif
	}
	
	#ifdef DEBUGINITIALIZEMATRIX
	printDoubleArrayAs2D("Markov Matrix: ", markovMatrix[0], transitionMatrixSize, transitionMatrixSize, 2);
	#endif
	
	return markovMatrix;
}
