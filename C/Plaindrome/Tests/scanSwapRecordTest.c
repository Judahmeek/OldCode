#include "../IO/printShortArray.c"
#include "../IO/printTitledSwapArray.c"
#include "../scanSwapRecord.c"

int main(){ //freq[] = {2, 2};
	swap swapRow[] = {{-1, -1}, {0, 0}, {-1, -1}, {3, 4}};
	short rowSize = 4;
	short bufferSignatureRow[] = {0, 2, 4, 4};
	short swapRecordIndex = 0, leftDigit = 0, rightDigit = 1, tscs = 4;
	
	printTitledSwapArray("scanSwapRecord(", swapRow, rowSize, 0);
	printf(", %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, rowSize);
	printf(" %d, %d)", leftDigit, rightDigit);
	puts("checks swapRow[0] and stops.");
	
	scanSwapRecord(swapRow, &swapRecordIndex, bufferSignatureRow, &leftDigit, &rightDigit, tscs);
		
	printTitledSwapArray("Results: (", swapRow, rowSize, 0);
	printf(", %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, rowSize);
	printf(" %d, %d)\n", leftDigit, rightDigit);
	
	swapRecordIndex = 1;
	
	printTitledSwapArray("scanSwapRecord(", swapRow, rowSize, 0);
	printf(", %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, rowSize);
	printf(" %d, %d)", leftDigit, rightDigit);
	puts("checks swapRow[1], increments swapRecordIndex, and then stops.");
	
	scanSwapRecord(swapRow, &swapRecordIndex, bufferSignatureRow, &leftDigit, &rightDigit, tscs);
		
	printTitledSwapArray("Results: (", swapRow, rowSize, 0);
	printf(", %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, rowSize);
	printf(" %d, %d)\n", leftDigit, rightDigit);
	
	swapRecordIndex = 3;
	
	printTitledSwapArray("scanSwapRecord(", swapRow, rowSize, 0);
	printf(", %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, rowSize);
	printf(" %d, %d)", leftDigit, rightDigit);
	puts("checks swapRow[3], increments swapRecordIndex, and then stops.");
	
	scanSwapRecord(swapRow, &swapRecordIndex, bufferSignatureRow, &leftDigit, &rightDigit, tscs);
		
	printTitledSwapArray("Results: (", swapRow, rowSize, 0);
	printf(", %d, ", swapRecordIndex);
	printShortArray(bufferSignatureRow, rowSize);
	printf(" %d, %d)\n", leftDigit, rightDigit);
	
	return 0;
}
