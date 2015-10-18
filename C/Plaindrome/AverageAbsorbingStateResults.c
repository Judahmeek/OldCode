#include "./IO/doubleOutput.c"

void AverageAbsorbingStateResults (double** matrix, int rows, int columns, int* absorbingStatesPtr, int sttSize){
	int i, j;
	double total = 0;
	for (i = 0; i < sttSize; ++i){
		for (j = rows; j < columns; ++j){
			total += matrix[absorbingStatesPtr[i]][j];
		}
	}
	total /= sttSize;
	fputs("End Result: ", stdout);
	doubleOutput(total, 4);
}
