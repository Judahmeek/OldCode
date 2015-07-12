#include "../IO/printTitledIntArray.c"
#include "../intArrayCompare.c"

int main() {
	int x[] = {3, 2, 2};
	int y[] = {3, 2, 2};
	short arraySize = 3;

	printTitledIntArray("Int Arrays: ", x, arraySize, 0);
	printTitledIntArray(" == ", y, arraySize, 0);

	if(!intArrayCompare(x, y, arraySize))
		puts(" : Passed");
	else
		puts(" : Failed");
	
	return 0;
}

	
