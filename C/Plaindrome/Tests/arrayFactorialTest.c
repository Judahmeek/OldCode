#include "../IO/printTitledShortArray.c"
#include "../arrayFactorial.c"

int main() {
	short array[] = {2, 3, 2};
	short arraySize = 3;
	short startingIndex = 0;
	short minus = 1;
	int desiredResult = 12;
	
	printTitledShortArray("arrayFactorial( array: ", array, arraySize, 0);
	printf(", arraySize: %d, startingIndex: %d, minus: %d) == %d : ", arraySize, startingIndex, minus, desiredResult);
	
	if(arrayFactorial(array, arraySize, startingIndex, minus) == 12)
		puts("Passed");
	else
		puts("Failed");
	return 0;
}
