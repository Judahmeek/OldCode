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

#define BASICS
#define DEBUG
//#define DEBUGSWAPRECORD
#include <stdio.h>
#include "arrayFactorial.c"
#include "initializeMatrix.c"
#include "ReversedHeapsort.c"

int main() {
	const short SIZE = 26;
	const short zerothSIZE = SIZE - 1;
    short freq[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    short i,c,stateSize = 0;
    
    fputs("Anagram please: ", stdout);
    
    while(c != '\n'){ //input anagram of palindrome
    	c = getchar();
    	if(c >= 'a' && c <= 'z'){
    		++stateSize;
    		c -= 'a';
    		++freq[c];
		}
    }
	
    short odd = 0, freqSize = 0; //test for palindrome qualities
    for(i = 0; i<SIZE; ++i){
        if(freq[i] > 0){
        	++freqSize;
        	if(freq[i] % 2 != 0)
        		++odd;
		}
    }
    
    if(odd > 1){
    	puts("NOT A PALINDROME\n");
	}else{
    	reversedHeapsort(freq, SIZE);
    	
    	short tscs = 0; //tscs stands for total state changing swaps
    	for(i = 0; i < freqSize; ++i){
    		tscs += freq[i] * (stateSize - freq[i]);
		}
		tscs /= 2;
		
		int totalStates = factorial(stateSize)/arrayFactorial(freq, freqSize, 0, 0);
		int posSwaps = stateSize * (stateSize - 1) / 2;
		
		#ifdef BASICS
		printf("Total states: %d\n", totalStates);
		printf("Total state changing swaps: %d\n", tscs);
		printf("All possible swaps per state: %d\n", posSwaps);
		#endif
    	
		double** MarkovMatrix = initializeMatrix(freq, freqSize, stateSize, totalStates, tscs, posSwaps);
		//InvertMatrix();
		//CalculateFundamentalMatrix();
		//CalculateAverageofAllExpectedStepsToAbsorbingStates();
		//OutputResult();
	}
    
    return 0; //Todo List: matrix inversion, estimated step calculation: https://en.wikipedia.org/wiki/Absorbing_Markov_chain#Fundamental_matrix
}
