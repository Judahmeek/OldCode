#include <stdio.h>
#include "../factorial.c"

int main() {
	short x = 4;
	int desiredResult = 24;
	
	printf("factorial(%d) == %d : ", x, desiredResult);
	
	if(factorial(x) == desiredResult)
		puts("Passed");
	else
		puts("Failed");
	return 0;
}
