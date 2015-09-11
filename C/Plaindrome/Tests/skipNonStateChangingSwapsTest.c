#include <stdio.h>
#include "../skipNonStateChangingSwaps.c"

main(){
	short state[] = {0, 1, 0, 0, 1};
	short stateSize = 5;
	short bufferSignatureRow[] = {34, 34, 34, 34};
	short swapRecordIndex = 0, lowIndex = 0, highIndex = 2;
	
    skipNonStateChangingSwaps(state, stateSize, &swapRecordIndex, bufferSignatureRow, &lowIndex, &highIndex);
    
	printf("swapRecordIndex: %d, lowIndex: %d, highIndex: %d", swapRecordIndex, lowIndex, highIndex);
	return 0;
}
