#include "../IO/printTitledShortArray.c"
#include "../intArrayCompare.c"

int main() {
	int x[] = {3, 2, 2};
	int y[] = {3, 2, 2};
	short arraySize = 3;

	if(!intArrayCompare(x, y, arraySize)){
		printTitledShortArray("Short Arrays: ", x, arraySize, 0);
		printTitledShortArray(" == ", y, arraySize, 0);
		puts(" : Passed");
	}
	else{
		printTitledShortArray("Short Arrays: ", x, arraySize, 0);
		printTitledShortArray(" == ", y, arraySize, 0);
		puts(" : Passed");
	}
	
	return 0;
}

	
