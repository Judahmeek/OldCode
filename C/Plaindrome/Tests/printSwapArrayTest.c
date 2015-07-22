#include "../IO/printSwapArray.c"

int main() {
	swap array[] = {{1, 2}, {3, 4}, {5, 6}};
	short arraySize = 3;
	fputs("swapArray[]: {{1, 2}, {3, 4}, {5, 6}} is output as ", stdout);
	printSwapArray (array, arraySize);
	return 0;
}
