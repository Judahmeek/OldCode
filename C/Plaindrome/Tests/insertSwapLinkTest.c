#include <stdio.h>
#include "../insertSwapLink.c"

int main() {
	swap x = {0, 0};
	swap y = {0, 0};
	insertSwapLink(&x, 1, &y, 2, 3);
	
	printf("x: %d-%d y: %d-%d", x.partnerID, x.index, y.partnerID, y.index);
	return 0;
}
