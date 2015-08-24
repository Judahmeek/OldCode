#include "../IO/printDoubleArray.c"

int main(){
	double x[] = {0.0, 1.234, -26.59867};
	fputs("Test: { 0.0, 1.234, -26.59867 } is output with precision of 4 as ", stdout);
	printDoubleArray(x, 4, 3);
	return 0;
}
