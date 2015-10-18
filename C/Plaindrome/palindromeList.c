#ifdef DEBUGPALINDROMELIST
	#include "./IO/printShortArray.c"
#endif

#include <stdlib.h>
#include "state2steps.c"

int* palindromeList(const short freq[], short freqHalf[], short freqSize, short stateSize, short numPalindrome){
	
	#ifdef DEBUGPALINDROMELIST
		fputs("palindromeList(freq: ", stdout);
		printShortArray(freq, freqSize);
		fputs(", freqHalf: ", stdout);
		printShortArray(freqHalf, freqSize);
		printf(",freqSize: %d, stateSize: %d, numPalindrome: %d)\n\n", freqSize, stateSize, numPalindrome);
	#endif
	
	int* list = (int*)malloc(numPalindrome * sizeof(int));
	
	short i, j, halfSize = stateSize / 2, size = stateSize - 1;
	short state[stateSize];
	if(stateSize % 2 != 0){
		state[halfSize] = freqSize - 1;
	}
	
	for(i = 0; i < numPalindrome; ++i){
		
		steps2state(freqHalf, freqSize, state, halfSize, i);
		for(j = 0; j < halfSize; ++j){
			state[size - j] = state[j];
		}
		
		#ifdef DEBUGPALINDROMELIST
			printf("state[%d]: ", i);
			printShortArray(state, stateSize);
			putchar('\n');
		#endif
		
		list[i] = state2steps(freq, freqSize, state, stateSize);
	}
	
	return list;
}
