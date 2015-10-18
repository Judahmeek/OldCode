#ifdef DEBUGPREPAREFUNDAMENTALMATRIX
	#include "./IO/systemPause.c"
	#include "./IO/printDoubleArrayAs2D.c"
	#include "./IO/printIntArray.c"
#endif
#ifdef MILESTONES
	#include "./IO/systemPause.c"
	#include "./IO/printDoubleArrayAs2D.c"
	#include "./IO/printIntArray.c"
#endif
#include "initializeSwapRecord.c"
#include "adjustForSkippedRows.c"

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
		printf("identityMatrixMinusSTMSPOPS: %f\n", identityMatrixMinusSTMSPOPS);
		printf("identityMatrixMinusSSPOPS: %f\n", identityMatrixMinusSSPOPS);
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
    		#ifdef DEBUGPREPAREFUNDAMENTALMATRIX
        		printf("swapRecord[j: %d][0]: %d == -tscs: %d\n", j, swapRecord[j][0], -tscs);
        	#endif
        
        matrix[i][adjustForSkippedRows(palList, numPalindrome, j)] = identityMatrixMinusSTMSPOPS;
        matrix[i][adjustForSkippedRows(palList, numPalindrome, j) + rows] = 1.0;
    	#ifdef DEBUGPREPAREFUNDAMENTALMATRIX
    	//if(i == 9) //bounds for limiting what is displayed
        	printf("matrix[%d]adjustForSkippedRows(palList, numPalindrome, %d): %d] = %f;\n", i, j, adjustForSkippedRows(palList, numPalindrome, j), identityMatrixMinusSTMSPOPS);
    	#endif
        
		if(swapRecord[j][0] < 0)
			swapRecordIndex = -swapRecord[j][0];
		else
			swapRecordIndex = 0;
		
        for(; swapRecordIndex < tscs; ++swapRecordIndex){
        	#ifdef DEBUGPREPAREFUNDAMENTALMATRIX
        	//if(i == 0){ //bounds for limiting what is displayed
				printf("swapRecord[%d]: ", j);
				printIntArray(swapRecord[j], tscs);
				putchar('\n');
        		printf("matrix[%d]adjustForSkippedRows(palList, numPalindrome, [swapRecord[%d][%d]): %d] = %f;\n", i, j, swapRecordIndex, adjustForSkippedRows(palList, numPalindrome, swapRecord[j][swapRecordIndex]), identityMatrixMinusSSPOPS);
        	//}
			#endif
        	matrix[i][adjustForSkippedRows(palList, numPalindrome, swapRecord[j][swapRecordIndex])] = identityMatrixMinusSSPOPS;
		}
	#ifdef DEBUGPREPAREFUNDAMENTALMATRIX
		#ifdef ENABLEPAUSE
			systemPause();
		#endif
	#endif
	}
	
	#ifdef MILESTONES
		printDoubleArrayAs2D("Preliminary Fundamental Matrix: ", matrix, rows, columns, 2);
		#ifdef ENABLEPAUSE
			systemPause();
		#endif
	#endif
	
	return matrix;
}
