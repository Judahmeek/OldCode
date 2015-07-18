#ionclude "insertSwapLink

swap** swapRecord(const short freq, short freqSize[], short stateSize, int totalStates, int tscs)
{
	int stateID, i;
	short bufferSignature[totalStates][sigSize];
	short states[totalStates][stateSize];
	swap** swapRecord;
	
	swapRecord  = (int **)malloc(sizeof(int *) * totalStates);
    swapRecord[0] = (int *)malloc(sizeof(int) * totalStates * tscs);
 
    for(i = 0; i < totalStates; ++i)
        swapRecord[i] = (*swapRecord + tscs * i);
	
	//Initializing the bufferSignature and swapRecord arrays
	for(stateID = 0; stateID < totalStates; ++stateID){
		steps2state(freq, freqSize, states[stateID], stateSize, stateID);
		bufferSignature(freq, freqSize, states[stateID], bufferSignature[stateID], sigSize)
		for(i = 0; i < tscs; ++i){
			swapRecord[stateID][i].stateID = -1;
			swapRecord[stateID][i].index = -1;
		}
	}
	
	//populate swapRecord
	short leftDigit, rightDigit, swapRecordIndex, swapStateBuffer, j;
	short swapState[stateSize];
	for(stateID = 0; stateID < totalStates; ++stateID){
    	
    	leftDigit = 0, rightDigit = 1, swapRecordIndex = 0;
    	scanSwapRecord(swapRecord[stateID], &swapRecordIndex, bufferSignature[stateID], &leftDigit, &rightDigit);
    	
    	while(swapRecordIndex < tscs){
    		if(states[stateID][leftDigit] == states[stateID][rightDigit])
    			++rightDigit;
    		else{
    			for(j = 0; j < stateSize; ++j) //initialize swapState
    				swapState[j] = states[stateID][j];
    			
    			swapState[leftDigit] = states[stateID][rightDigit]; //perform swap
    			swapState[rightDigit] = states[stateID][leftDigit];
    			
    			swapStateBuffer = 0;
    			for(j = leftDigit + 1; j < rightDigit; ++j) //count diffValue
    				if(swapState[leftDigit] != swapState[j])
    					++swapStateBuffer
    			
    			
    			int partnerID = state2steps(freq, freqSize, swapState, stateSize);
    			insertSwapLink(swapRecord[stateID][swapRecordIndex], swapRecord[partnerID][bufferSignature[partnerID][leftDigit] + swapStateBuffer], partnerID, stateID, rightDigit);
    			
    			++swapRecordIndex, ++rightDigit;    			
    			scanSwapRecord(swapRecord[stateID], &swapRecordIndex, bufferSignature[stateID], &leftDigit, &rightDigit);
			}
			
			if(rightDigit >= stateSize){
				++leftDigit;
				rightDigit = leftDigit + 1;
			}
		}
	}
	return swapRecord;
}
