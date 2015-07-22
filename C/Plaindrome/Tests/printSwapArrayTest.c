#include "../IO/printSwapInstanceArray.c"

int main() {
	SwapInstance array[] = {{1, 2}, {3, 4}, {5, 6}};
	short arraySize = 3;
	fputs("SwapInstanceArray[]: {{1, 2}, {3, 4}, {5, 6}} is output as ", stdout);
	printSwapInstanceArray (array, arraySize);
	return 0;
}
