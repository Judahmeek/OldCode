#include "../IO/intOutput.c"

int main(){
	int x = 0;
	printf("Test: %d is output as ", x);
	intOutput(x);
	putchar('\n');
	
	x = -2659867;
	printf("Test: %d is output as ", x);
	intOutput(x);
	
	return 0;
}
