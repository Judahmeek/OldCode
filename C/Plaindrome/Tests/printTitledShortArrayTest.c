#include "../IO/printTitledShortArray.c"

int main(){
	short x[] = {0, -1, 2};
	fputs("x[]: { 0, -1, 2 } is output as ", stdout);
	printTitledShortArray("x[]: ", x, 3, 1);
	puts("newline test");
	return 0;
}
