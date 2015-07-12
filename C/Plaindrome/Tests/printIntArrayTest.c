#include "../IO/printIntArray.c"

int main(){
	int x[] = {0, -1, 2};
	fputs("Test: { 0, -1, 2 } is output as ", stdout);
	printIntArray(x, 3);
	return 0;
}
