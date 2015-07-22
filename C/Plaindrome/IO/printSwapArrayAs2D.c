#include "printSwapArray.c"

void printSwapArrayAs2D (const char* x, const swap* twoD, int rows, short columns){
	puts(x);
	int i;
	for(i = 0; i < rows; ++i){
		putchar(i + '0');
		fputs(": ", stdout);
		printSwapArray (&twoD[i * columns], columns);
		putchar('\n');
	}    	
};
