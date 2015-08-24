#ifndef SCANSWAPRECORD
#define SCANSWAPRECORD

void scanSwapRecord(int swapRow[], short* swapRecordIndexPtr, short bufferSignatureRow[], short* lowIndexPtr, short* highIndexPtr, short tscs){
	while(swapRow[*swapRecordIndexPtr] != -1 && *swapRecordIndexPtr < tscs){
		++*swapRecordIndexPtr;
		if(*swapRecordIndexPtr > bufferSignatureRow[*lowIndexPtr]){
			++*lowIndexPtr;
			*highIndexPtr = *lowIndexPtr + 1;
		} else {
			*highIndexPtr = swapRow[*swapRecordIndexPtr] + 1;
		}
	}
}

#endif //SCANSWAPRECORD
