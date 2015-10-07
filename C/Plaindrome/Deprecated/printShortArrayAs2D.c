#ifndef PRINTSHORTARRAYAS2D
#define PRINTSHORTARRAYAS2D

#include "printShortArray.c"
#include "intOutput.c"

void printShortArrayAs2D (const char* x, const short** twoD, int rows, int columns, int x){
	puts(x);
	int i;
	for(i = 0; i < rows; ++i){
		intOutput(i);
		fputs(": ", stdout);
		printShortArray (twoD[i], columns);
		putchar('\n');
	}    	
};

#endif //PRINTSHORTARRAYAS2D
