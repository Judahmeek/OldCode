#define DEBUGFINDMATRIXROW
#include <stdlib.h>
#include "../findMatrixRow.c"

main(){
	int i, inputStateID = 8;
	short numPalindrome = 3;
	
	int palList[] = {3,5,7};
	
	findMatrixRow(palList, numPalindrome, inputStateID);
	
	return 0;
}
