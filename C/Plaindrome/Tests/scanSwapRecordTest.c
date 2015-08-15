#include "../IO/printShortArray.c"
#include "../IO/printTitledSwapArray.c"
#include "../scanSwapRecord.c"

int main(){ //freq[] = {2, 2};
	swap swapRow[] = {{-1, -1}, {0, 0}, {-1, -1}, {3, 4}};
	short rowSize = 4;
	short bufferSignatureRow[] = {0, 2, 4, 4};
	short swapRecordIndex = 0, leftDigit = 0, rightDigit = 1, tscs = 4;
	
	//Testing empty swap behavior
	printTitledSwapArray("scanSwapRecord(", swapRow, rowSize, 0);
	printf(", SRI: %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, rowSize);
	printf(" LD: %d, RD: %d)", leftDigit, rightDigit);
	puts("checks swapRow[0] and stops.");
	
	scanSwapRecord(swapRow, &swapRecordIndex, bufferSignatureRow, &leftDigit, &rightDigit, tscs);
		
	printTitledSwapArray("Results: (", swapRow, rowSize, 0);
	printf(", SRI: %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, rowSize);
	printf(" LD: %d, RD: %d\n)", leftDigit, rightDigit);
	
	if(swapRecordIndex == 0 && leftDigit == 0 && rightDigit == 1)
		puts("PASSED");
	else
		puts("FAILED");
	
	//Testing filled swap behavior
	swapRecordIndex = 1;
	
	printTitledSwapArray("scanSwapRecord(", swapRow, rowSize, 0);
	printf(", SRI: %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, rowSize);
	printf(" LD: %d, RD: %d)", leftDigit, rightDigit);
	puts("checks swapRow[1], increments swapRecordIndex, and then stops.");
	
	scanSwapRecord(swapRow, &swapRecordIndex, bufferSignatureRow, &leftDigit, &rightDigit, tscs);
		
	printTitledSwapArray("Results: (", swapRow, rowSize, 0);
	printf(", SRI: %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, rowSize);
	printf(" LD: %d, RD: %d\n)", leftDigit, rightDigit);
	
	if(swapRecordIndex == 2 && leftDigit == 1 && rightDigit == 2)
		puts("PASSED");
	else
		puts("FAILED");
	
	//Testing filled swap & end of scanRecord behavior
	swapRecordIndex = 3;
	
	printTitledSwapArray("scanSwapRecord(", swapRow, rowSize, 0);
	printf(", SRI: %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, rowSize);
	printf(" LD: %d, RD: %d)", leftDigit, rightDigit);
	puts("checks swapRow[3], increments swapRecordIndex, and then stops.");
	
	scanSwapRecord(swapRow, &swapRecordIndex, bufferSignatureRow, &leftDigit, &rightDigit, tscs);
		
	printTitledSwapArray("Results: (", swapRow, rowSize, 0);
	printf(", SRI: %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, rowSize);
	printf(" LD: %d, RD: %d\n)", leftDigit, rightDigit);
	
	if(swapRecordIndex == 4 && leftDigit == 2 && rightDigit == 3)
		puts("PASSED");
	else
		puts("FAILED");
	
	return 0;
}
