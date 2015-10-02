#ifndef DISPLAYMATRIX
#define DISPLAYMATRIX

#include "printDoubleArrayAs2D.c"

void displayMatrix (const double* matrix, int size, short precision){
	printDoubleArrayAs2D ("Markov Matrix: ", matrix, size, size, precision);
};

#endif //DISPLAYMATRIX
