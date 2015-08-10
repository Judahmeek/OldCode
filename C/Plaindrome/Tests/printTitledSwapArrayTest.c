#include "../IO/printTitledSwapArray.c"

int main(){
	swap x[] = {{1, 2}, {3, 4}, {5, -1}};
	fputs("x[]: {{1,2}, {3, 4}, {5, -1}} is output as ", stdout);
	printTitledSwapArray("x[]: ", x, 3, 1);
	puts("newline test");
	return 0;
}
