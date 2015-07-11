#include <stdio.h>
#include "Factorial.c"

int main() {
	if(factorial(4) == 24)
		puts("factorial(4) == 24 : Passed");
	else
		puts("factorial(4) == 24 : Failed");
	return 0;
}
