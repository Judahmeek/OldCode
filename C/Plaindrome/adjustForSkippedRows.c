#ifndef ADJUSTFORSKIPPEDROWS
#define ADJUSTFORSKIPPEDROWS

#ifdef DEBUGADJUSTFORSKIPPEDROWS
	#include <stdio.h>
	#include "./IO/systemPause.c"
#endif

int adjustForSkippedRows (const int* palList, short numPalindrome, int state){
	
	short low = -1, high = numPalindrome, middle = numPalindrome/2;
	while(high - low != 1){
    	if(palList[middle] - state > 0){
    		#ifdef DEBUGADJUSTFORSKIPPEDROWS
				printf("(palList[middle]: %d - state: %d ): %d > 0\n", palList[middle], state, palList[middle] - state);
				#ifdef ENABLEPAUSE
					systemPause();
				#endif
			#endif
    		high = middle;
    		middle = (high - low)/2 + low;
		} else {
			#ifdef DEBUGADJUSTFORSKIPPEDROWS
				printf("(palList[middle]: %d - state: %d ): %d < 0\n", palList[middle], state, palList[middle] - state);
				#ifdef ENABLEPAUSE
					systemPause();
				#endif
			#endif
    		low = middle;
    		middle = (high - low)/2 + low;
		}
	}
	state = state - high;
	
	#ifdef DEBUGADJUSTFORSKIPPEDROWS
		printf("adjustForSkippedRows Result: %d", state);
	#endif
	
	return state;
}

#endif //ADJUSTFORSKIPPEDROWS
