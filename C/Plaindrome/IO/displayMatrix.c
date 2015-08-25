#ifndef DISPLAYMATRIX
#define DISPLAYMATRIX

#include "printDoubleArrayAs2D.c"

void displayMatrix (const double* matrix, int size){
	printDoubleArrayAs2D ("Markov Matrix: ", matrix, size, size, 8);
};

#endif //DISPLAYMATRIX
