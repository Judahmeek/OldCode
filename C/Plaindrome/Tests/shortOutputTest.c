#include "shortOutput.c"

int main(){
	int x = 0;	
	printf("Test: %d is output as ", x);
	shortOutput(x);
	putchar('\n');
	
	x = -3468;
	printf("Test: %d is output as ", x);
	shortOutput(x);
	
	return 0;
}
