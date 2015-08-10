#include "printSwapInstanceArray.c"
#ifndef PRINTSWAPINSTANCEARRAYAS2D
#define PRINTSWAPINSTANCEARRAYAS2D

void printSwapInstanceArrayAs2D (const char* x, const swapInstance* twoD, int rows, short columns){
	puts(x);
	int i;
	for(i = 0; i < rows; ++i){
		putchar(i + '0');
		fputs(": ", stdout);
		printSwapInstanceArray (&twoD[i * columns], columns);
		putchar('\n');
	}    	
};

#endif //PRINTSWAPARRAYAS2D
