#ifndef PRINTSWAPINSTANCEARRAYAS2D
#define PRINTSWAPINSTANCEARRAYAS2D

#include "printSwapArray.c"

void printSwapArrayAs2D (const char* x, swap* twoD, short columns, int rows){
	puts(x);
	int i;
	for(i = 0; i < rows; ++i){
		putchar(i + '0');
		fputs(": ", stdout);
		printSwapArray (&twoD[i * columns], columns);
		putchar('\n');
	}    	
};

#endif //PRINTSWAPARRAYAS2D
