#ifdef DEBUGSWAPRECORD
#include <stdio.h>
#include "./IO/printTitledIntArray.c"
#include "./IO/printTitledShortArray.c"
#include "./IO/systemPause.c"
#endif
#include <stdlib.h>
#include "state2steps.c"
#include "scanSwapRecord.c"
#include "insertSwapLink.c"
#include "bufferSignature.c"

int** initializeSwapRecord(const short freq[], short freqSize, short stateSize, int totalStates, int tscs)
{
	int stateID, i;
	short bufferSig[totalStates][stateSize];
	short states[totalStates][stateSize];
	
	int** swapRecord = (int **)malloc(sizeof(int *) * totalStates);
    swapRecord[0] = (int *)malloc(sizeof(int) * totalStates * tscs);
    for(i = 0; i < totalStates; ++i)
        swapRecord[i] = (*swapRecord + tscs * i);
    
	for(stateID = 0; stateID < totalStates; ++stateID){ //Initializing
		steps2state(freq, freqSize, states[stateID], stateSize, stateID);
		bufferSignature(freq, freqSize, states[stateID], stateSize, bufferSig[stateID]);
		for(i = 0; i < tscs; ++i){
			swapRecord[stateID][i] = -1;
		}
		#ifdef DEBUGSWAPRECORD
		printf("Initialized row %d\n", stateID);
		#endif
	}
	
	//populating swapRecord
	short lowIndex, highIndex, swapRecordIndex, swapStateBuffer, j;
	short swapState[stateSize];
	for(stateID = 0; stateID < totalStates; ++stateID){
	
    	lowIndex = 0, highIndex = 1, swapRecordIndex = 0;
    	
    	#ifdef DEBUGSWAPRECORD
    	printf("\nstateID: %d\n", stateID);
    	printTitledIntArray("swapRecord: ", swapRecord[stateID], tscs, 1);
    	scanSwapRecord(swapRecord[stateID], &swapRecordIndex, bufferSig[stateID], &lowIndex, &highIndex, tscs);
    	printf("scan moves lowIndex to %d and highIndex to %d\n", lowIndex, highIndex);
    	#endif
    	
    	while(swapRecordIndex < tscs){
    		#ifdef DEBUGSWAPRECORD
    		printf("\nswapRecordIndex: %d tscs: %d\n", swapRecordIndex, tscs);
    		#endif
    		if(states[stateID][lowIndex] == states[stateID][highIndex]){
    			++highIndex;
    			#ifdef DEBUGSWAPRECORD
    			puts("lowIndex and highIndex same. rD increments by one.");
    			#endif
			}
    		else{
    			for(j = 0; j < stateSize; ++j) //initialize swapState
    				swapState[j] = states[stateID][j];
    			
    			swapState[lowIndex] = states[stateID][highIndex]; //perform int
    			swapState[highIndex] = states[stateID][lowIndex];
    			
    			#ifdef DEBUGSWAPRECORD
    			if(arraySum(swapState, stateSize) != 6){
    				printf("lowIndex: %d, highIndex: %d\n", lowIndex, highIndex);
	    			printTitledShortArray("baseState: ", states[stateID], stateSize, 0);
	    			printf(", stateSize: %d stateSum: %d\n", stateSize, arraySum(states[stateID], stateSize));		
	    			printTitledShortArray("swapState: ", swapState, stateSize, 0);
	    			printf(", stateSize: %d stateSum: %d\n", stateSize, arraySum(swapState, stateSize));
				}
				#endif
    			
    			swapStateBuffer = 0;
    			for(j = lowIndex + 1; j < highIndex; ++j)
    				if(swapState[lowIndex] != swapState[j])
    					++swapStateBuffer;
    					
    			int partnerID = state2steps(freq, freqSize, swapState, stateSize);
    			
    			insertSwapLink(&swapRecord[stateID][swapRecordIndex], &partnerID, &swapRecord[partnerID][bufferSig[partnerID][lowIndex] + swapStateBuffer], &stateID);
    			
    			++swapRecordIndex, ++highIndex;
    			#ifdef DEBUGSWAPRECORD
    			printf("\nSRI incremented to %d\n", swapRecordIndex);
    			#endif
    			scanSwapRecord(swapRecord[stateID], &swapRecordIndex, bufferSig[stateID], &lowIndex, &highIndex, tscs);
    			#ifdef DEBUGSWAPRECORD
    			printf("scan moves lowIndex to %d and highIndex to %d\n", lowIndex, highIndex);
    			#endif
			}
			#ifdef DEBUGSWAPRECORD
			printf("\nlowIndex: %d, highIndex: %d, stateSize: %d\n", lowIndex, highIndex, stateSize);
			#endif
			if(highIndex >= stateSize){
				++lowIndex;
				highIndex = lowIndex + 1;
				#ifdef DEBUGSWAPRECORD
    			printf("lowIndex changed to %d and highIndex to %d\n", lowIndex, highIndex);
    			#endif
			}
		#ifdef DEBUGSWAPRECORD
		printf("swapRecord[%d]: ", stateID);
		printIntArray(swapRecord[stateID], tscs);
		putchar('\n');
		#endif
		}
	}
	
	#ifdef DEBUGSWAPRECORD
	for(i = 0; i < totalStates; ++i){
		printf("swapRecord[%d]: ", i);
		printIntArray(swapRecord[i], tscs);
		putchar('\n');
	}
	systemPause();
	#endif
	
	return swapRecord;
}
