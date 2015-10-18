#include "../IO/printDoubleArray.c"

int main(){
	short prec = 4;
	double x[] = {0.0, 1.234, -26.59867, 2, 3};
	printf("Test: { %f, %f, %f %f, %f } is output with precision of %d as ", x[0], x[1], x[2], x[3], x[4], prec);
	printDoubleArray(x, 5, prec);
	return 0;
}
