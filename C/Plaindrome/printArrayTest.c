#include "printArray.c"

void main(){
	short x[] = {0, -1, 2};
	int y[] = {3, -4, 5};
	
	printShortArray("x: ", x, 3);
	printIntArray("y: ", y, 3);
}
