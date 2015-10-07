#ifndef PRINTDOUBLEARRAYAS2D
#define PRINTDOUBLEARRAYAS2D

#include "printDoubleArray.c"
#include "intOutput.c"

void printDoubleArrayAs2D (const char* x, const double** twoD, int rows, int columns, short precision, int x){
	puts(x);
	int i;
	for(i = 0; i < rows; ++i){
		intOutput(i);
		fputs(": ", stdout);
		printDoubleArray (twoD[i], columns, precision);
		putchar('\n');
	}    	
};

#endif //PRINTDOUBLEARRAYAS2D
