/* https://www.hackerrank.com/challenges/palindromes

Problem Statement

Given a string, you keep swapping any two characters in the string randomly till the string becomes a palindrome. What is the expected number of swaps you will make? There will always be at least one palindrome which can be formed with the letters of the given string.

Input: 
The first line contains the number of test cases T. Each of the next T lines contains a string each.

Output: 
Output T lines containing the answer for the corresponding test case. Print the answer rounded to exactly 4 decimal places.

Constraints: 
T <= 10000 
The length of the string will be at most 8 characters. 
The string will consist of only lower-case letters 'a'-'z'.

Sample Input:

4  
b  
bb  
abb  
cbaabbb
Sample Output:

0.0000  
0.0000  
3.0000  
59.3380
Explanation:

For the first two cases, the string is already a palindrome so no swaps are needed.

For the third case, there are 3 possible swaps. The string will become "bab","bba" or remain "abb" with 1/3rd probability each. It's easy to see that the expected number of swaps needed is 3.0000

For the last case, the answer is 59.337962..., which should be printed as 59.3380

*/

/*#define ENABLEPAUSE
#define BASICS
#define MILESTONES
#define DEBUGSTATE2STEPS
#define DEBUGSTEPS2STATE
#define DEBUGSWAPRECORD
#define DEBUGPALINDROMELIST
#define DEBUGSANITIZESWAPRECORD
#define DEBUGPREPAREFUNDAMENTALMATRIX
#define DEBUGINVERTMATRIX*/
#ifdef BASICS
	#include "./IO/printTitledShortArray.c"
	#include "./IO/systemPause.c"
#endif
#include <stdio.h>
#include <stdlib.h>
#include "adjustIDsForSkippedRows.c"
#include "arrayFactorial.c"
#include "AverageAbsorbingStateResults.c"
#include "invertMatrix.c"
#include "palindromeList.c"
#include "prepareFundamentalMatrix.c"
#include "sanitizeSwapRecord.c"

int main() {
    
    fputs("Anagram please: ", stdout);
    
    const short SIZE = 26;
    short i,c,memLimit = 8, stateSize = 0;
    short* freq = (short*)calloc(SIZE, sizeof(short));
    short* inputState = (short*)malloc(sizeof(short) * memLimit);
    while(c != '\n'){ //input anagram of palindrome
    	c = getchar();
    	if(c >= 'a' && c <= 'z'){
    		c -= 'a';
    		inputState[stateSize] = c;
    		++stateSize;
    		if(stateSize > memLimit){
    			memLimit *= 2;
    			void* reallocResult = realloc(inputState, sizeof(short) * memLimit);
    			if(!reallocResult){
    				short* temp = (short*)malloc(sizeof(short) * memLimit);
    				for(i = 0; i<stateSize; ++i)
    					temp[i] = inputState[i];
    				inputState = temp;
				} else
					inputState = (short*) reallocResult;
			}
    		++freq[c];
		}
    }
	
    short odd = 0, freqSize = 0, oddValue; //test for palindrome qualities
    for(i = 0; i<SIZE; ++i){
        if(freq[i] > 0){
        	++freqSize;
		}
    }
    
    if(freqSize < 2)
    	puts("0.0000");
	else{
		
		#ifdef BASICS
			printTitledShortArray("freq: ", freq, SIZE, 1);
			#ifdef ENABLEPAUSE
				systemPause();
			#endif
		#endif
		
		short newFreq[freqSize];
		c = -1;
		for(i = 0; i<SIZE; ++i){
			if(freq[i] > 0){
				if(freq[i] % 2 != 0){
					++odd;
					newFreq[freqSize - 1] = freq[i];
					freq[i] = freqSize - 1;
				} else {
					newFreq[++c] = freq[i];
					freq[i] = c;
				}
			}
		}
		
		if(odd > 1){
	    	puts("NOT AN ANAGRAM OF A PALINDROME\n");
		}else{
			for(i = 0; i<stateSize; ++i){
				inputState[i] = freq[inputState[i]];
			}
			
			free(freq);
			
			#ifdef BASICS
				printTitledShortArray("Input State: ", inputState, stateSize, 1);
				printTitledShortArray("freq: ", freq, SIZE, 1);
				printTitledShortArray("Frequencies: ", newFreq, freqSize, 1);
				#ifdef ENABLEPAUSE
					systemPause();
				#endif
			#endif
			
	    	int inputStateID = state2steps(newFreq, freqSize, inputState, stateSize);
	    
		    #ifdef BASICS
				printf("inputStateID: %d\n", inputStateID);
			#endif
	    	
	    	short tscs = 0; //tscs stands for total state changing swaps
	    	for(i = 0; i < freqSize; ++i){
	    		tscs += newFreq[i] * (stateSize - newFreq[i]);
			}
			tscs /= 2;
			
			int totalStates = factorial(stateSize)/arrayFactorial(newFreq, freqSize, 0, 0);
			int posSwaps = stateSize * (stateSize - 1) / 2;
			
			short freqHalf[freqSize];
			for(i = 0; i < freqSize; ++i){
				freqHalf[i] = newFreq[i] / 2;
			}
			short numPalindrome = factorial(stateSize/2)/arrayFactorial(freqHalf, freqSize, 0, 0);
			
			#ifdef BASICS
				printf("Total states: %d\n", totalStates);
				printf("Total state changing swaps: %d\n", tscs);
				printf("All possible swaps per state: %d\n", posSwaps);
				printf("Number of Palindromes: %d\n", numPalindrome);
				#ifdef ENABLEPAUSE
					systemPause();
				#endif
			#endif
			
	    	int rows = totalStates - numPalindrome;
	    	int columns = rows * 2;
			int* statesToTrack = &inputStateID;
			int arraySize = 1;
	    	
			int* palList = palindromeList(newFreq, freqHalf, freqSize, stateSize, numPalindrome);
			int** swapRecord = initializeSwapRecord(newFreq, freqSize, stateSize, totalStates, tscs);
			sanitizeSwapRecord(swapRecord, totalStates, palList, numPalindrome, tscs);
			double** MarkovMatrix = prepareFundamentalMatrix(swapRecord, totalStates, tscs, palList, numPalindrome, posSwaps);
			adjustIDsForSkippedRows(palList, numPalindrome, statesToTrack, arraySize);
			invertMatrix(MarkovMatrix, rows, columns, statesToTrack, arraySize);
			AverageAbsorbingStateResults(MarkovMatrix, rows, columns, statesToTrack, arraySize);
		}
	}
    
    return 0;
}
