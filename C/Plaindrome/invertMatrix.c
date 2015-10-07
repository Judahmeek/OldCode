/*
for pivot = 1 ... min(m,n):
   Find the pivot-th pivot:
   i_max  := argmax (i = pivot ... m, abs(Matrix[i, pivot]))
   if Matrix[i_max, pivot] = 0
     error "Matrix is singular!"
   swap rows(pivot, i_max)
   Do for all rows below pivot:
   for i = pivot + 1 ... m:
     Do for all remaining elements in current row:
     for j = pivot + 1 ... n:
       Matrix[i, j]  := Matrix[i, j] - Matrix[pivot, j] * (Matrix[i, pivot] / Matrix[pivot, pivot])
     Fill lower triangular matrix with zeros:
     Matrix[i, pivot]  := 0
*/

invertMatrix (double** Matrix, int matrixSize, int* statesToTracpivot, int sttSize){
	int i, j, pivot, max;
	int temp[matrixSize];
	for (pivot = 0; pivot < matrixSize; ++pivot){
	printDoubleArrayAs2D("Fundamental matrix: ", matrix, rows, columns, 2);
		max = pivot;
		
		for(i = pivot + 1, i < matrixSize; ++i){
			if(abs(Matrix[i][pivot]) > abs(Matrix[max][pivot])){
				max = i;
			}
		}
		
		for(i = 0; i < sttSize; ++i){
			if(statesToTracpivot[i] == max)
				statesToTracpivot[i] = pivot;
			else if (statesToTracpivot[i] == pivot)
				statesToTracpivot[i] = max;
		}
		
		for(i = 0; i < matrixSize; ++i){
			temp[i] = Matrix[pivot][i];
			Matrix[pivot][i] = Matrix[max][i];
			Matrix[max][i] = temp[i];
		}
		
		for(i = pivot + 1, i < matrixSize; ++i){
			for(j = pivot + 1, j < matrixSize; ++j){
				Matrix[i][j]  := Matrix[i][j] - Matrix[pivot][j] * (Matrix[i][pivot] / Matrix[pivot][pivot])
			}
			Matrix[i][pivot] = 0;
		printDoubleArrayAs2D("Fundamental matrix after step: ", matrix, rows, columns, 2);
		}
		printDoubleArrayAs2D("Fundamental matrix after step: ", matrix, rows, columns, 2);
	}
	printDoubleArrayAs2D("Inverted Fundamental matrix: ", matrix, rows, columns, 2);
}
