#define DEBUGDOUBLEOUTPUT
#include "../IO/doubleOutput.c"

int main(){
	double x = 0;
	short prec = 2;
	printf("Test: doubleOutput(num: %f, precision: %d) is output as ", x, prec);
	doubleOutput(x, prec);
	putchar('\n');
	
	x = 3;
	printf("Test: doubleOutput(num: %f, precision: %d) is output as ", x, prec);
	doubleOutput(x, prec);
	putchar('\n');
	
	double y = 26.99867;
	printf("Test: doubleOutput(num: %f, precision: %d) is output as ", y, prec);
	doubleOutput(y, prec);
	putchar('\n');
	
	double z = 0.1;
	printf("Test: doubleOutput(num: %f, precision: %d) is output as ", z, prec);
	doubleOutput(z, prec);
	putchar('\n');
	
	return 0;
}
