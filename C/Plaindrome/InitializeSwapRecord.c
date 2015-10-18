#ifdef DEBUGSWAPRECORD
	#include "./IO/printTitledIntArray.c"
	#include "./IO/printTitledShortArray.c"
	#include "./IO/systemPause.c"
#endif
#ifdef MILESTONES
	#include "./IO/printIntArray.c"
	#include "./IO/systemPause.c"
#endif
#include <stdlib.h>
#include "state2steps.c"
#include "scanSwapRecord.c"
#include "insertSwapLink.c"
#include "bufferSignature.c"

int** initializeSwapRecord(const short freq[], short freqSize, short stateSize, int totalStates, int tscs)
{
	#ifdef DEBUGSWAPRECORD
		fputs("initializeSwapRecord(freq: ", stdout);
		printShortArray(freq, freqSize);
		printf(",freqSize: %d, state: ", freqSize);
		printf(", stateSize: %d, int totalStates, int tscs)\n\n", stateSize, totalStates, tscs);
	#endif
	
	int stateID, i;
	short sigSize = stateSize - 1;
	short bufferSig[totalStates][sigSize];
	short states[totalStates][stateSize];
	
	int** swapRecord = (int **)malloc(sizeof(int *) * totalStates);
    swapRecord[0] = (int *)malloc(sizeof(int) * totalStates * tscs);
    for(i = 0; i < totalStates; ++i)
        swapRecord[i] = (*swapRecord + tscs * i);
    
	for(stateID = 0; stateID < totalStates; ++stateID){ //Initializing
		steps2state(freq, freqSize, states[stateID], stateSize, stateID);
		bufferSignature(freq, freqSize, states[stateID], sigSize, bufferSig[stateID]);
		for(i = 0; i < tscs; ++i){
			swapRecord[stateID][i] = -1;
		}
		#ifdef DEBUGSWAPRECORD
			printf("Initialized row %d\n", stateID);
		#endif
	}
	
	//populating swapRecord
	short lowIndex, highIndex, swapRecordIndex, swapStateBuffer, partnerSwapIndex, j;
	short swapState[stateSize];
	for(stateID = 0; stateID < totalStates; ++stateID){
	
    	swapRecordIndex = 0, lowIndex = 0, highIndex = 1;
    	
    	while (states[stateID][lowIndex] == states[stateID][highIndex]){
    		if(swapRecordIndex >= bufferSig[stateID][lowIndex]){
				++lowIndex;
				highIndex = lowIndex + 1;
			}else
				++highIndex;
		}
    	
    	scanSwapRecord(states[stateID], stateSize, swapRecord[stateID], &swapRecordIndex, bufferSig[stateID], &lowIndex, &highIndex, tscs);
    	#ifdef DEBUGSWAPRECORD
	    	printf("\nstateID: %d state: ", stateID);
			printShortArray(states[stateID], stateSize);
	    	printTitledIntArray("\nswapRecord: ", swapRecord[stateID], tscs, 1);
	    	printf("scan moves lowIndex to %d and highIndex to %d\n", lowIndex, highIndex);
			#ifdef ENABLEPAUSE
				systemPause();
			#endif
    	#endif
    	
    	while(swapRecordIndex < tscs){
    		#ifdef DEBUGSWAPRECORD
	    		printf("\nswapRecordIndex: %d tscs: %d\n", swapRecordIndex, tscs);
				printf("state[lowIndex]: %d != state[highIndex]: %d\n", states[stateID][lowIndex], states[stateID][highIndex]);
			#endif
			for(j = 0; j < stateSize; ++j) //initialize swapState
				swapState[j] = states[stateID][j];
			
			swapState[lowIndex] = states[stateID][highIndex];
			swapState[highIndex] = states[stateID][lowIndex];
			
			swapStateBuffer = 0;
			for(j = lowIndex + 1; j < highIndex; ++j)
				if(swapState[lowIndex] != swapState[j])
					++swapStateBuffer;
			
			int partnerID = state2steps(freq, freqSize, swapState, stateSize);
			
			if(lowIndex == 0)
				partnerSwapIndex = swapStateBuffer;
			else
				partnerSwapIndex = bufferSig[partnerID][lowIndex - 1] + swapStateBuffer;
			
			insertSwapLink(&swapRecord[stateID][swapRecordIndex], &partnerID, &swapRecord[partnerID][partnerSwapIndex], &stateID);
			
			++swapRecordIndex;
			skipNonStateChangingSwaps(states[stateID], stateSize, &swapRecordIndex, bufferSig[stateID], &lowIndex, &highIndex);
			
			#ifdef DEBUGSWAPRECORD
				printf("Increments: SDI to %d, lowIndex to %d, and highIndex to %d\n", swapRecordIndex, lowIndex, highIndex);
			#endif
			scanSwapRecord(states[stateID], stateSize, swapRecord[stateID], &swapRecordIndex, bufferSig[stateID], &lowIndex, &highIndex, tscs);
			#ifdef DEBUGSWAPRECORD
				printf("sSR increments SDI to %d, lowIndex to %d, and highIndex to %d\n", swapRecordIndex, lowIndex, highIndex);
				printf("swapRecord[%d]: ", stateID);
				printIntArray(swapRecord[stateID], tscs);
				putchar('\n');
			#endif
		}
	}
	
	#ifdef MILESTONES
		for(i = 0; i < totalStates; ++i){
			printf("swapRecord[%d]: ", i);
			printIntArray(swapRecord[i], tscs);
			putchar('\n');
		}
		#ifdef ENABLEPAUSE
			systemPause();
		#endif
	#endif
	
	return swapRecord;
}
