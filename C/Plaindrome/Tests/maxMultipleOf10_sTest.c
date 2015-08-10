#include <stdio.h>
#include "../maxMultipleOf10_s.c"

int main(){
	short x = 1234;
	fputs("Maximum multiple of 10 in x: 1234 is ", stdout);
	printf("%d", maxMultipleOf10_s(x));
	return 0;
}
