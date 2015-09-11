#include "../IO/printShortArray.c"
#include "../IO/printTitledIntArray.c"
#include "../scanSwapRecord.c"

int main(){ //freq[] = {2, 2};
	int swapRow[] = {-1, -1, 0, -1, 0, 0, -1, 3};
	short bufferSignatureRow[] = {3, 5, 7, 8};
	short tscs = 8, stateSize = 5, sigSize = 4;
	short state[] = {0, 1, 1, 0, 2};
	
	//Testing empty int behavior
	short swapRecordIndex = 0, lowIndex = 0, highIndex = 1;
	
	printTitledIntArray("scanSwapRecord(", swapRow, tscs, 0);
	printf(", SRI: %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, sigSize);
	printf(" LD: %d, RD: %d)", lowIndex, highIndex);
	puts("checks swapRow[0] and stops.");
	
	scanSwapRecord(state, stateSize, swapRow, &swapRecordIndex, bufferSignatureRow, &lowIndex, &highIndex, tscs);
		
	printTitledIntArray("Results: (", swapRow, tscs, 0);
	printf(", SRI: %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, sigSize);
	printf(" LD: %d, RD: %d\n)", lowIndex, highIndex);
	
	if(swapRecordIndex == 0 && lowIndex == 0 && highIndex == 1)
		puts("PASSED");
	else
		puts("FAILED");
	
	//Testing single filled swap with highIndex at bufferSig limit
	swapRecordIndex = 2, lowIndex = 0, highIndex = 4;
	
	printTitledIntArray("\nscanSwapRecord(", swapRow, tscs, 0);
	printf(", SRI: %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, sigSize);
	printf(" LD: %d, RD: %d)", lowIndex, highIndex);
	puts("checks swapRow[1], increments swapRecordIndex, and then stops.");
	
	scanSwapRecord(state, stateSize, swapRow, &swapRecordIndex, bufferSignatureRow, &lowIndex, &highIndex, tscs);
		
	printTitledIntArray("Results: (", swapRow, tscs, 0);
	printf(", SRI: %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, sigSize);
	printf(" LD: %d, RD: %d\n)", lowIndex, highIndex);
	
	if(swapRecordIndex == 3 && lowIndex == 1 && highIndex == 3)
		puts("PASSED");
	else
		puts("FAILED");
		
	//Testing double filled swaps
	swapRecordIndex = 4, lowIndex = 1, highIndex = 4;
	
	printTitledIntArray("\nscanSwapRecord(", swapRow, tscs, 0);
	printf(", SRI: %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, sigSize);
	printf(" LD: %d, RD: %d)", lowIndex, highIndex);
	puts("checks swapRow[1], increments swapRecordIndex, and then stops.");
	
	scanSwapRecord(state, stateSize, swapRow, &swapRecordIndex, bufferSignatureRow, &lowIndex, &highIndex, tscs);
		
	printTitledIntArray("Results: (", swapRow, tscs, 0);
	printf(", SRI: %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, sigSize);
	printf(" LD: %d, RD: %d\n)", lowIndex, highIndex);
	
	if(swapRecordIndex == 6 && lowIndex == 2 && highIndex == 4)
		puts("PASSED");
	else
		puts("FAILED");
	
	//Testing filled swap @ end of swapRow
	swapRecordIndex = 7, lowIndex = 3, highIndex = 4;
	
	printTitledIntArray("\nscanSwapRecord(", swapRow, tscs, 0);
	printf(", SRI: %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, sigSize);
	printf(" LD: %d, RD: %d)", lowIndex, highIndex);
	puts("checks swapRow[3], increments swapRecordIndex, and then stops.");
	
	scanSwapRecord(state, stateSize, swapRow, &swapRecordIndex, bufferSignatureRow, &lowIndex, &highIndex, tscs);
		
	printTitledIntArray("Results: (", swapRow, tscs, 0);
	printf(", SRI: %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, sigSize);
	printf(" LD: %d, RD: %d\n)", lowIndex, highIndex);
	
	if(swapRecordIndex == 8 && lowIndex == 4 && highIndex == 5)
		puts("PASSED");
	else
		puts("FAILED");
	
	return 0;
}
