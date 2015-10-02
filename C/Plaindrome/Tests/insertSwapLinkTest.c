#include <stdio.h>
#include "../insertSwapLink.c"

int main() {
	int x = 2, y = 1, a = 1, b = 2;
	insertSwapLink(&x, &a, &y, &b);
	
	printf("x: %d y: %d", x, y);
	if(x == 1 && y == 2)
		puts(" : Passed");
	else
		puts(" : Failed");
	return 0;
}
