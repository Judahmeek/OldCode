#include "../IO/printTitledShortArray.c"
#include "../arraySum.c"

int main() {
	short array[] = {2, 3, 2};
	short arraySize = 3;
	short desiredResult = 7;
	
	printTitledShortArray("arraySum( array: ", array, arraySize, 0);
	printf(", arraySize: %d) == %d : ", arraySize, desiredResult);
	
	if(arraySum(array, arraySize) == 7)
		puts("Passed");
	else
		puts("Failed");
		
	return 0;
}
