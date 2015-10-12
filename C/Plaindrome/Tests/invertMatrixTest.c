#define DEBUGINVERTMATRIX

#include <stdlib.h>
#include "../invertMatrix.c"


main(){

	int i,j, rows = 3, columns = 6;
	
	double** matrix = (double **)malloc(rows * sizeof(double *));
	matrix[0] = (double *)calloc(rows * columns, sizeof(double));
	for(i = 0; i < rows; ++i)
		matrix[i] = (matrix[0] + columns * i);
	
	double array[] =  {1, 0, 4, 1, 0, 0};
	matrix[0] = &array;
	double array1[] = {0, 3, 1, 0, 1, 0};
	matrix[1] = &array1;
	double array2[] = {.5, 1, 2, 0, 0, 1};
	matrix[2] = &array2;
	
	/*
	 1 0 4 ->  -5 -4 12
	 0 3 1 -> -.5  0  1
	.5 1 2 -> 1.5  1 -3
	*/
	
	int sttSize = 1;
	int statesToTrack = 2;
	int* statesToTrackptr = &statesToTrack;
	
	invertMatrix (matrix, rows, columns, statesToTrackptr, sttSize);

}
