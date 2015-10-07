#define DEBUGINVERTMATRIX

#include <stdlib.h>
#include "../invertMatrix.c"


main(){

	int i,j, rows = 3, columns = 6;
	
	double** matrix = (double **)malloc(rows * sizeof(double *));
	matrix[0] = (double *)calloc(rows * columns, sizeof(double));
	for(i = 0; i < rows; ++i)
		matrix[i] = (matrix[0] + columns * i);
		
	for(i = 0; i<rows; ++i){
		for(j = 0; j<rows; ++j){
			matrix[i][j] = i + j;
		}
		matrix[i][i + rows] = 1;
	}
	
	matrix[rows - 1][rows - 1] += 1;
	
	/*
	0 1 2
	1 2 3
	2 3 4
	*/
	
	int sttSize = 1;
	int statesToTrack = 2;
	int* statesToTrackptr = &statesToTrack;
	
	invertMatrix (matrix, rows, columns, statesToTrackptr, sttSize);

}
