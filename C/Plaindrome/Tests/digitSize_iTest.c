#include <stdio.h>
#include "../digitSize_i.c"

int main(){
	int x = 1234567;
	fputs("Maximum power of 10 in x: 1234567 is ", stdout);
	printf("%d", digitSize_i(x));
	return 0;
}
