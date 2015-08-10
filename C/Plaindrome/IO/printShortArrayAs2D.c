#ifndef PRINTSHORTARRAYAS2D
#define PRINTSHORTARRAYAS2D

#include "printShortArray.c"

void printShortArrayAs2D (const char* x, const short* twoD, int columns, short rows){
	puts(x);
	int i;
	for(i = 0; i < rows; ++i){
		putchar(i + '0');
		fputs(": ", stdout);
		printShortArray (&twoD[i * columns], columns);
		putchar('\n');
	}    	
};

#endif //PRINTSHORTARRAYAS2D
