#define DEBUGPALINDROMELIST

#include "../palindromeList.c"

main(){
	short freq[] = {4, 2, 1};
	short freqHalf[] = {2, 1, 0};
	short freqSize = 3;
	short stateSize = 7;
	short numPalindrome = 3;
	palindromeList(freq, freqHalf, freqSize, stateSize, numPalindrome);
	return 0;
}
