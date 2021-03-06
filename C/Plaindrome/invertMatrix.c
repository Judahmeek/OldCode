#ifdef DEBUGINVERTMATRIX
	#include "./IO/printDoubleArrayAs2D.c"
	#include "./IO/printTitledIntArray.c"
	#include "./IO/systemPause.c"
#endif
#ifdef MILESTONES
	#include "./IO/printDoubleArrayAs2D.c"
	#include "./IO/printTitledIntArray.c"
	#include "./IO/systemPause.c"
#endif

void invertMatrix (double** matrix, int rows, int columns, int* statesToTrackPtr, int sttSize){

	#ifdef DEBUGINVERTMATRIX
		printDoubleArrayAs2D("Fundamental matrix: ", matrix, rows, columns, 2);
		printTitledIntArray("Target states: ", statesToTrackPtr, sttSize, 1);
		#ifdef ENABLEPAUSE
			systemPause();
		#endif
		putchar('\n');
	#endif
	
	int i, j, pivot, max, stopPivot = rows - 1, subtractor, rowAbove;
	double* tempPtr;
	for (pivot = 0; pivot < stopPivot; ++pivot){
		max = pivot;
		#ifdef DEBUGINVERTMATRIX
			printf("step %d\n", pivot);
		#endif
		
		for(i = pivot + 1; i < rows; ++i){
			if(abs(matrix[i][pivot]) > abs(matrix[max][pivot])){
				max = i;
			}
		}
		
		#ifdef DEBUGINVERTMATRIX
			printf("max found: %d\n", max);
		#endif
		
		for(i = 0; i < sttSize; ++i){
			if(statesToTrackPtr[i] == max)
				statesToTrackPtr[i] = pivot;
			else if (statesToTrackPtr[i] == pivot)
				statesToTrackPtr[i] = max;
		}
		
		if(max != pivot){
			tempPtr = matrix[pivot];
			matrix[pivot] = matrix[max];
			matrix[max] = tempPtr;
		}
		
		for(i = pivot + 1; i < rows; ++i){
			for(j = pivot + 1; j < columns; ++j){
				matrix[i][j] = matrix[i][j] - matrix[pivot][j] * (matrix[i][pivot] / matrix[pivot][pivot]);
			}
			matrix[i][pivot] = 0;
		}
		
		#ifdef DEBUGINVERTMATRIX
			printDoubleArrayAs2D("Fundamental matrix after step: ", matrix, rows, columns, 2);
			printTitledIntArray("Target states: ", statesToTrackPtr, sttSize, 1);
				#ifdef ENABLEPAUSE
					systemPause();
				#endif
			putchar('\n');
		#endif
	}
	
	for(; pivot > 0; --pivot){
		rowAbove = pivot - 1;
		if(matrix[pivot][pivot] != 1){
			for(i = rows; i < columns; ++i)
				matrix[pivot][i] /= matrix[pivot][pivot];
			matrix[pivot][pivot] = 1;
		}
		
		for(subtractor = pivot; subtractor < rows; ++subtractor){
			if(matrix[rowAbove][subtractor] != 0)
				for(i = rows; i < columns; ++i)
					matrix[rowAbove][i] -= matrix[subtractor][i] * matrix[rowAbove][subtractor];
			matrix[rowAbove][subtractor] = 0;
		}
		
		#ifdef DEBUGINVERTMATRIX
			printDoubleArrayAs2D("Fundamental matrix after step: ", matrix, rows, columns, 2);
			printTitledIntArray("Target states: ", statesToTrackPtr, sttSize, 1);
				#ifdef ENABLEPAUSE
					systemPause();
				#endif
			putchar('\n');
		#endif

	}
	
	for(i = rows; i < columns; ++i)
		matrix[pivot][i] /= matrix[pivot][pivot];
	matrix[pivot][pivot] = 1;
	
	#ifdef MILESTONES
		double matrixRowTotal = 0;
		puts("Inverted Fundamental matrix: ");
		for(i = 0; i < rows; ++i){
			intOutput(i);
			fputs(": ", stdout);
			printDoubleArray (matrix[i], columns, 4);
			for (j = rows; j < columns; ++j)
				matrixRowTotal += matrix[i][j];
			printf(": %f ", matrixRowTotal);
			matrixRowTotal = 0;
		}
		printTitledIntArray("Modified target states: ", statesToTrackPtr, sttSize, 1);
		#ifdef ENABLEPAUSE
			systemPause();
		#endif
	#endif
}
