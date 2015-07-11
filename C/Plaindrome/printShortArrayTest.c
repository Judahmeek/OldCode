#include "printShortArray.c"

int main(){
	short x[] = {0, -1, 2};
	fputs("Test: { 0, -1, 2 } is output as ", stdout);
	printShortArray(x, 3);
	return 0;
}
