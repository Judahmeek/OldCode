#ifdef DEBUGPREPAREFUNDAMENTALMATRIX
#include "./IO/systemPause.c"
#endif
#include "initializeSwapRecord.c"
#include "./IO/printDoubleArrayAs2D.c"
#include "./IO/printIntArray.c"
#include "findMatrixRow.c"

/*	To save time, the markov matrix is initiated to I - Q, where I is the identity matrix of the transition matrix Q
*/

double ** prepareFundamentalMatrix(int** swapRecord, int totalStates, int tscs, int* palList, short numPalindrome, int posSwaps){
	
	int i;
	int swapsThatMaintainState = (posSwaps - tscs);
	double stmsPercentageOfPosSwaps = (double)swapsThatMaintainState/(double)posSwaps;
	double singleSwapsPercentageOfPosSwaps = 1.0/(double)posSwaps;
	//prep for fundamental matrix (I - Q)^-1 is I - Q
	double identityMatrixMinusSTMSPOPS = 1.0 - stmsPercentageOfPosSwaps;
	double identityMatrixMinusSSPOPS = -singleSwapsPercentageOfPosSwaps;
	
	#ifdef BASICS
	printf("swapsThatMaintainState: %d\n", swapsThatMaintainState);
	printf("swapsThatMaintainState /  posSwaps: %f\n", stmsPercentageOfPosSwaps);
	printf("1 / posSwaps: %f\n", singleSwapsPercentageOfPosSwaps);
	#endif
	
	int transitionMatrixRows = totalStates - numPalindrome;
	int transitionMatrixColumns = transitionMatrixRows * 2;
	double** matrix = (double **)malloc(transitionMatrixRows * sizeof(double *));
	matrix[0] = (double *)calloc(transitionMatrixRows * transitionMatrixColumns, sizeof(double));
	for(i = 0; i < transitionMatrixRows; ++i)
		matrix[i] = (matrix[0] + transitionMatrixColumns * i);
	
	int j = 0;
	short swapRecordIndex;
	for(i = 0; i < transitionMatrixRows; ++i, ++j){
    	
        while(swapRecord[j][0] == -tscs) //if state == palindrome
        	++j; //move to the next state
        
        matrix[i][findMatrixRow(palList, numPalindrome, j)] = identityMatrixMinusSTMSPOPS;
        matrix[i][findMatrixRow(palList, numPalindrome, j) + transitionMatrixRows] = 1.0;
    	#ifdef DEBUGPREPAREFUNDAMENTALMATRIX
    	if(i == 9) //bounds for limiting what is displayed
        	printf("matrix[%d]findMatrixRow(palList, numPalindrome, %d): %d] = %f;\n", i, j, findMatrixRow(palList, numPalindrome, j), identityMatrixMinusSTMSPOPS);
    	#endif
        
		if(swapRecord[j][0] < 0)
			swapRecordIndex = -swapRecord[j][0];
		else
			swapRecordIndex = 0;
		
        for(; swapRecordIndex < tscs; ++swapRecordIndex){
        	#ifdef DEBUGPREPAREFUNDAMENTALMATRIX
        	if(i == 0){ //bounds for limiting what is displayed
				printf("swapRecord[%d]: ", j);
				printIntArray(swapRecord[j], tscs);
				putchar('\n');
        		printf("matrix[%d]findMatrixRow(palList, numPalindrome, [swapRecord[%d][%d]): %d] = %f;\n", i, j, swapRecordIndex, findMatrixRow(palList, numPalindrome, swapRecord[j][swapRecordIndex]), identityMatrixMinusSSPOPS);

        	}
			#endif
        	matrix[i][findMatrixRow(palList, numPalindrome, swapRecord[j][swapRecordIndex])] = identityMatrixMinusSSPOPS;
		}
	#ifdef DEBUGPREPAREFUNDAMENTALMATRIX
	//systemPause();
	#endif
	}
	
	#ifdef DEBUGPREPAREFUNDAMENTALMATRIX
	printDoubleArrayAs2D("Preliminary Fundamental Matrix: ", matrix[0], transitionMatrixRows, transitionMatrixColumns, 2);
	#endif
	
	return matrix;
}
