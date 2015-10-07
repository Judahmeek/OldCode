#include <stdlib.h>
#include "../IO/printDoubleArrayAs2D.c"

int main() {
	short i, j;
	double k = 0.0;
	int rows = 3;
	short columns = 4;
	double** matrix = (double **)malloc(rows * sizeof(double *));
	matrix[0] = (double *)calloc(rows * columns, sizeof(double));
	for(i = 0; i < rows; ++i)
		matrix[i] = (matrix[0] + columns * i);
	for(i = 0; i < rows; ++i){
		for(j = 0; j < columns; ++j){
			matrix[i][j] = k++ * 1.1;
		}
	}
	
	printDoubleArrayAs2D("printDoubleArrayAs2D Test:", matrix, rows, columns, 4);
	puts("compared to printf:");
	for(i = 0; i < rows; ++i){
		printf("{%f, %f, %f, %f}\n", matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3]);
	}
	return 0;
}
