#ifndef SKIPNONSTATECHANGINGSWAPS
#define SKIPNONSTATECHANGINGSWAPS

void skipNonStateChangingSwaps(short* state, short stateSize, short* swapRecordIndexPtr, short bufferSignatureRow[], short* lowIndexPtr, short* highIndexPtr){
	do {
		if(*swapRecordIndexPtr >= bufferSignatureRow[*lowIndexPtr]){
			++*lowIndexPtr;
			*highIndexPtr = *lowIndexPtr + 1;
		}else
			++*highIndexPtr;
	} while (state[*lowIndexPtr] == state[*highIndexPtr]);
};

#endif //SKIPNONSTATECHANGINGSWAPS
