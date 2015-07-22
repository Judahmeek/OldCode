void scanSwapRecord(swap swapRow[], short* swapRecordIndexPtr, short bufferSignatureRow[], short* leftDigitPtr, short* rightDigitPtr, short tscs){
	while(swapRow[*swapRecordIndexPtr].index != -1 && *swapRecordIndexPtr < tscs){
		*rightDigitPtr = swapRow[*swapRecordIndexPtr].index + 1;
		++*swapRecordIndexPtr;
		if(*swapRecordIndexPtr > bufferSignatureRow[*leftDigitPtr])
			++*leftDigitPtr;
		if(*rightDigitPtr <= *leftDigitPtr)
			*rightDigitPtr = *leftDigitPtr + 1;
	}
}
