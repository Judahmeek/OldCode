#include "printShortArray.c"

void printTitledShortArray (const char* x, const short y[], short size){
	fputs(x, stdout);
	printShortArray (y, size);
    puts("");
};
