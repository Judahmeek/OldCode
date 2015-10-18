#ifdef DEBUGSANITIZESWAPRECORD
#include "./IO/printIntArray.c"
#endif
#ifdef MILESTONES
#include "./IO/printIntArray.c"
#endif

void sanitizeSwapRecord(int** swapRecord, int totalStates, const int* palList, short numPalindrome, int tscs){
	
	#ifdef DEBUGSANITIZESWAPRECORD
		fputs("sanitizeSwapRecord(swapRecord, palList: ", stdout);
		printIntArray(palList, numPalindrome);
		printf(", numPalindrome: %d)\n\n", numPalindrome, tscs);
	#endif
	
	int i, k, l, m;
	int *palindrome, *partner;
	for(i = 0; i < numPalindrome; ++i){
		palindrome = swapRecord[palList[i]];
		for(k = 0; k < tscs; ++k){
			partner = swapRecord[palindrome[k]];
			for(l = 0; l < tscs; ++l){
				for(m = 0; m < numPalindrome; ++m){
					if(partner[l] == palList[m]){
						if(partner[0] > 0){
							partner[l] = partner[0];
							partner[0] = -1;
						} else {
							partner[l] = partner[partner[0] * -1];
							#ifdef DEBUGSANITIZESWAPRECORD
								partner[partner[0] * -1] = -1;
							#endif
							--partner[0];
						}
					}
				}
			}
		}
		palindrome[0] = -tscs;
	}
	#ifdef MILESTONES
		puts("sanitized swapRecord:");
		for(i = 0; i < totalStates; ++i){
			printf("[%d]: ", i);
			printIntArray(swapRecord[i], tscs);
			putchar('\n');
		}
		#ifdef ENABLEPAUSE
			systemPause();
		#endif
	#endif
}
