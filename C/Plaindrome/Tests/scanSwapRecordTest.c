#include "../IO/printShortArray.c"
#include "../IO/printTitledShortArray.c"
#include "../scanSwapRecord.c"

int main(){ //freq[] = {2, 2};
	int swapRow[] = {-1, 0, -1, 3};
	short rowSize = 4;
	short bufferSignatureRow[] = {0, 2, 4, 4};
	short intRecordIndex = 0, leftDigit = 0, rightDigit = 1, tscs = 4;
	
	//Testing empty int behavior
	printTitledShortArray("scanSwapRecord(", swapRow, rowSize, 0);
	printf(", SRI: %d, ", intRecordIndex);
	printShortArray(bufferSignatureRow, rowSize);
	printf(" LD: %d, RD: %d)", leftDigit, rightDigit);
	puts("checks swapRow[0] and stops.");
	
	scanSwapRecord(swapRow, &intRecordIndex, bufferSignatureRow, &leftDigit, &rightDigit, tscs);
		
	printTitledShortArray("Results: (", swapRow, rowSize, 0);
	printf(", SRI: %d, ", intRecordIndex);
	printShortArray(bufferSignatureRow, rowSize);
	printf(" LD: %d, RD: %d\n)", leftDigit, rightDigit);
	
	if(intRecordIndex == 0 && leftDigit == 0 && rightDigit == 1)
		puts("PASSED");
	else
		puts("FAILED");
	
	//Testing filled int behavior
	intRecordIndex = 1;
	
	printTitledShortArray("scanSwapRecord(", swapRow, rowSize, 0);
	printf(", SRI: %d, ", intRecordIndex);
	printShortArray(bufferSignatureRow, rowSize);
	printf(" LD: %d, RD: %d)", leftDigit, rightDigit);
	puts("checks swapRow[1], increments intRecordIndex, and then stops.");
	
	scanSwapRecord(swapRow, &intRecordIndex, bufferSignatureRow, &leftDigit, &rightDigit, tscs);
		
	printTitledShortArray("Results: (", swapRow, rowSize, 0);
	printf(", SRI: %d, ", intRecordIndex);
	printShortArray(bufferSignatureRow, rowSize);
	printf(" LD: %d, RD: %d\n)", leftDigit, rightDigit);
	
	if(intRecordIndex == 2 && leftDigit == 1 && rightDigit == 2)
		puts("PASSED");
	else
		puts("FAILED");
	
	//Testing filled int & end of scanRecord behavior
	intRecordIndex = 3;
	
	printTitledShortArray("scanSwapRecord(", swapRow, rowSize, 0);
	printf(", SRI: %d, ", intRecordIndex);
	printShortArray(bufferSignatureRow, rowSize);
	printf(" LD: %d, RD: %d)", leftDigit, rightDigit);
	puts("checks swapRow[3], increments intRecordIndex, and then stops.");
	
	scanSwapRecord(swapRow, &intRecordIndex, bufferSignatureRow, &leftDigit, &rightDigit, tscs);
		
	printTitledShortArray("Results: (", swapRow, rowSize, 0);
	printf(", SRI: %d, ", intRecordIndex);
	printShortArray(bufferSignatureRow, rowSize);
	printf(" LD: %d, RD: %d\n)", leftDigit, rightDigit);
	
	if(intRecordIndex == 4 && leftDigit == 2 && rightDigit == 3)
		puts("PASSED");
	else
		puts("FAILED");
	
	return 0;
}
