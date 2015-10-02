#ifndef FINDMATRIXROW
#define FINDMATRIXROW

#ifdef DEBUGFINDMATRIXROW
#include <stdio.h>
#include "./IO/systemPause.c"
#endif

int findMatrixRow(const int* palList, short numPalindrome, int inputStateID){
	
	short low = -1, high = numPalindrome, middle = numPalindrome/2;
	while(high - low != 1){
    	if(palList[middle] - inputStateID > 0){
    		#ifdef DEBUGFINDMATRIXROW
			printf("(palList[middle]: %d - inputStateID: %d ): %d > 0\n", palList[middle], inputStateID, palList[middle] - inputStateID);
			systemPause();
			#endif
    		high = middle;
    		middle = (high - low)/2 + low;
		} else {
			#ifdef DEBUGFINDMATRIXROW
			printf("(palList[middle]: %d - inputStateID: %d ): %d < 0\n", palList[middle], inputStateID, palList[middle] - inputStateID);
			systemPause();
			#endif
    		low = middle;
    		middle = (high - low)/2 + low;
		}
	}
	inputStateID = inputStateID - high;
	
	#ifdef DEBUGFINDMATRIXROW
	printf("findMatrixRow Result: %d", inputStateID);
	#endif
	
	return inputStateID;
}

#endif //FINDMATRIXROW
