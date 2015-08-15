#ifndef SCANSWAPRECORD
#define SCANSWAPRECORD

#include "swap.c"

void scanSwapRecord(swap swapRow[], short* swapRecordIndexPtr, short bufferSignatureRow[], short* leftDigitPtr, short* rightDigitPtr, short tscs){
	while(swapRow[*swapRecordIndexPtr].index != -1 && *swapRecordIndexPtr < tscs){
		++*swapRecordIndexPtr;
		if(*swapRecordIndexPtr > bufferSignatureRow[*leftDigitPtr]){
			++*leftDigitPtr;
			*rightDigitPtr = *leftDigitPtr + 1;
		} else {
			*rightDigitPtr = swapRow[*swapRecordIndexPtr].index + 1;
		}
	}
}

#endif //SCANSWAPRECORD
