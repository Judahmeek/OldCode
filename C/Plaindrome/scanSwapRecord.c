void scanSwapRecord(swapInstance swapRow[], short* swapRecordIndexPtr, short bufferSignatureRow[], short* leftDigitPtr, short* rightDigitPtr){
	while(swapRow[*swapRecordIndexPtr].index != -1 && *swapRecordIndexPtr < tscs){
		++*swapRecordIndexPtr;
		if(*swapRecordIndexPtr > bufferSignatureRow[*leftDigitPtr])
			++*leftDigitPtr;
		*rightDigitPtr = swapRow[*swapRecordIndexPtr].index + 1;
	}
}
