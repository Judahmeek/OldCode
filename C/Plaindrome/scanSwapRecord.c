#ifndef SCANSWAPRECORD
#define SCANSWAPRECORD

#include "swap.c"

void scanSwapRecord(swap swapRow[], short* swapRecordIndexPtr, short bufferSignatureRow[], short* lowIndexPtr, short* highIndexPtr, short tscs){
	while(swapRow[*swapRecordIndexPtr].index != -1 && *swapRecordIndexPtr < tscs){
		++*swapRecordIndexPtr;
		if(*swapRecordIndexPtr > bufferSignatureRow[*lowIndexPtr]){
			++*lowIndexPtr;
			*highIndexPtr = *lowIndexPtr + 1;
		} else {
			*highIndexPtr = swapRow[*swapRecordIndexPtr].index + 1;
		}
	}
}

#endif //SCANSWAPRECORD
