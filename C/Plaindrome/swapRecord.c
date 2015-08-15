#include <stdlib.h>
#include "state2steps.c"
#include "scanSwapRecord.c"
#include "insertSwapLink.c"
#include "bufferSignature.c"
#include "./IO/printTitledShortArray.c"
#include "./IO/printTitledSwapArray.c"

swap** swapRecord(const short freq[], short freqSize, short stateSize, int totalStates, int tscs)
{
	int stateID, i;
	short bufferSig[totalStates][stateSize];
	short states[totalStates][stateSize];
	swap** swapRecord;
	
	swapRecord = (swap **)malloc(sizeof(swap *) * totalStates);
    swapRecord[0] = (swap *)malloc(sizeof(swap) * totalStates * tscs);
 
    for(i = 0; i < totalStates; ++i)
        swapRecord[i] = (*swapRecord + tscs * i);
    
	for(stateID = 0; stateID < totalStates; ++stateID){ //Initializing
		steps2state(freq, freqSize, states[stateID], stateSize, stateID);
		bufferSignature(freq, freqSize, states[stateID], stateSize, bufferSig[stateID]);
		for(i = 0; i < tscs; ++i){
			swapRecord[stateID][i].partnerID = -1;
			swapRecord[stateID][i].index = -1;
		}
	}
	
	//populating swapRecord
	short leftDigit, rightDigit, swapRecordIndex, swapStateBuffer, j;
	short swapState[stateSize];
	int stop = totalStates - 1; //The final swapRecordRow will be completely filled in if everything else works correctly
	for(stateID = 0; stateID < stop; ++stateID){
	
    	leftDigit = 0, rightDigit = 1, swapRecordIndex = 0;
    	
    	
    	while(swapRecordIndex < tscs){
    		if(states[stateID][leftDigit] == states[stateID][rightDigit]){
    			++rightDigit;
			}
    		else{
    			for(j = 0; j < stateSize; ++j) //initialize swapState
    				swapState[j] = states[stateID][j];
    			
    			swapState[leftDigit] = states[stateID][rightDigit]; //perform swap
    			swapState[rightDigit] = states[stateID][leftDigit];
    			
    			swapStateBuffer = 0;
    			for(j = leftDigit + 1; j < rightDigit; ++j)
    				if(swapState[leftDigit] != swapState[j])
    					++swapStateBuffer;
    					
    			int partnerID = state2steps(freq, freqSize, swapState, stateSize);
    			
    			insertSwapLink(&swapRecord[stateID][swapRecordIndex], partnerID, &swapRecord[partnerID][bufferSig[partnerID][leftDigit] + swapStateBuffer], stateID, rightDigit);
    			
    			++swapRecordIndex, ++rightDigit;
    			scanSwapRecord(swapRecord[stateID], &swapRecordIndex, bufferSig[stateID], &leftDigit, &rightDigit, tscs);
			}
			if(rightDigit >= stateSize){
				++leftDigit;
				rightDigit = leftDigit + 1;
			}
		}
	}
	return swapRecord;
}
