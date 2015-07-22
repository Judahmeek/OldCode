#include "printSwapArray.c"

void printTitledSwapArray (const char* x, const swap y[], short size, _Bool newline){
	fputs(x, stdout);
	printSwapArray (y, size);
    if(newline)
    	putchar('\n');
};
