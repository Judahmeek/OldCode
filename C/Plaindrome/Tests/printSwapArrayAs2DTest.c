#include "../IO/printSwapArrayAs2D.c"

int main() {
	int rows = 4;
	short columns = 3;
	swap array[] = {{1, 2}, {3, 4}, {5, 6}, {2, 2}, {4, 4}, {6, 6}, {3, 2}, {5, 4}, {7, 6}, {3, 3}, {5, 5}, {7, 7}};
	printSwapArrayAs2D("printSwapArrayAs2D Test:", array, rows, columns);
	return 0;
}
