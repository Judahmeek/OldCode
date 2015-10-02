#ifndef SCANSWAPRECORD
#define SCANSWAPRECORD

#ifdef DEBUGSCANSWAPRECORD
#include <stdio.h>
#include "./IO/printShortArray.c"
#include "./IO/systemPause.c"
#endif

#include "skipNonStateChangingSwaps.c"

void scanSwapRecord(short* state, short stateSize, int swapRow[], short* swapRecordIndexPtr, short bufferSignatureRow[], short* lowIndexPtr, short* highIndexPtr, short tscs){
	#ifdef DEBUGSCANSWAPRECORD
	printShortArray(state, stateSize);
	putchar('\n');
	#endif
	while(swapRow[*swapRecordIndexPtr] != -1 && *swapRecordIndexPtr < tscs){
		++*swapRecordIndexPtr;
		skipNonStateChangingSwaps(state, stateSize, swapRecordIndexPtr, bufferSignatureRow, lowIndexPtr, highIndexPtr);
	}
	#ifdef DEBUGSCANSWAPRECORD
	printf("Final SRI: %d low: %d high: %d\n", *swapRecordIndexPtr, *lowIndexPtr, *highIndexPtr);
	systemPause();
	#endif
}

#endif //SCANSWAPRECORD
