#include "../IO/printDoubleArray.c"

int main(){
	short prec = 6;
	double x[] = {0.0, 1.234, -26.59867};
	printf("Test: { %f, %f, %f } is output with precision of %d as ", x[0], x[1], x[2], prec);
	printDoubleArray(x, 3, prec);
	return 0;
}
