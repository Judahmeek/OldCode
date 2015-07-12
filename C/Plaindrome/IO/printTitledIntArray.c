#include "printIntArray.c"

void printTitledIntArray (const char* x, const int y[], short size){
	fputs(x, stdout);
	printIntArray (y, size);
    puts("");
};
