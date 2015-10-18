#include "adjustForSkippedRows.c"

adjustIDsForSkippedRows (const int* palList, short numPalindrome, int* targetStates, int tsSize){
	int i;
	for(i = 0; i < tsSize; ++i){
		targetStates[i] = adjustForSkippedRows (palList, numPalindrome, targetStates[i]);
	}
}
