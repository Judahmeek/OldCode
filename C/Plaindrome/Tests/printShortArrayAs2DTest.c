#include "../IO/printShortArrayAs2D.c"

int main() {
	short i, j, k = 0;
	int rows = 3;
	short columns = 4;
	short array[rows][columns];
	for(i = 0; i < rows; ++i){
		for(j = 0; j < columns; ++j){
			array[i][j] = k++;
		}
	}
	
	printShortArrayAs2D("printShortArrayAs2D Test:", array, columns, rows);
	return 0;
}
