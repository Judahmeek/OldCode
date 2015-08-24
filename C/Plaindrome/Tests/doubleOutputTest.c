#include "../IO/doubleOutput.c"

int main(){
	double x = 0;
	short prec = 10;
	printf("Test: doubleOutput(num: %f, precision: %d) is output as ", x, prec);
	doubleOutput(x, prec);
	putchar('\n');
	
	x = -26.59867;
	printf("Test: doubleOutput(num: %f, precision: %d) is output as ", x, prec);
	doubleOutput(x, prec);
	putchar('\n');
	
	double y = 26.59867;
	printf("Test: doubleOutput(num: %f, precision: %d) is output as ", y, prec);
	doubleOutput(y, prec);
	putchar('\n');
	
	double result = x + y;
	printf("Test: doubleOutput(num: x + y, precision: %d) is output as ", prec);
	doubleOutput(result, prec);
	putchar('\n');
	
	return 0;
}
