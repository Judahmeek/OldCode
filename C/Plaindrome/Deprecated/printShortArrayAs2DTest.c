#include <stdlib.h>
#include "../IO/printShortArrayAs2D.c"

int main() {
	short i, j, k = 0;
	int rows = 3;
	short columns = 4;
	short** matrix = (short **)malloc(rows * sizeof(short *));
	matrix[0] = (short *)calloc(rows * columns, sizeof(short));
	for(i = 0; i < rows; ++i)
		matrix[i] = (matrix[0] + columns * i);
	for(i = 0; i < rows; ++i){
		for(j = 0; j < columns; ++j){
			matrix[i][j] = k++;
		}
	}
	
	printShortArrayAs2D("printShortArrayAs2D Test:", matrix, rows, columns);
	puts("compared to printf:");
	for(i = 0; i < rows; ++i){
		printf("{%d, %d, %d, %d}\n", matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3]);
	}
	return 0;
}
