#include <stdio.h>
#include "../insertSwap.c"

int main() {
	swap x = {0, 0};
	insertSwap(&x, 1, 2);
	
	printf("%d-%d", x.partnerID, x.index);
	return 0;
}
