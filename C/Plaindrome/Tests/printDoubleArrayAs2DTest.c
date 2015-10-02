#include "../IO/printDoubleArrayAs2D.c"

int main() {
	short i, j;
	double k = 0.0;
	int rows = 3;
	short columns = 4;
	double array[rows][columns];
	for(i = 0; i < rows; ++i){
		for(j = 0; j < columns; ++j){
			array[i][j] = k++ * 1.1;
		}
	}
	
	printDoubleArrayAs2D("printDoubleArrayAs2D Test:", array, columns, rows, 4);
	puts("compared to printf:");
	for(i = 0; i < rows; ++i){
		printf("{%f, %f, %f, %f}\n", array[i][0], array[i][1], array[i][2], array[i][3]);
	}
	return 0;
}
