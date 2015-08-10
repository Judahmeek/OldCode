#include <stdio.h>
#include "../maxMultipleOf10_i.c"

int main(){
	int x = 1234567;
	fputs("Maximum multiple of 10 in x: 1234567 is ", stdout);
	printf("%d", maxMultipleOf10_i(x));
	return 0;
}
