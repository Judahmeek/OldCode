#ifndef REVERSEDHEAPSORT
#define REVERSEDHEAPSORT

#include <math.h>

void siftDown(short *a, short root, short end){

    while(root * 2 + 1 <= end){
        short child = root * 2 + 1;
        short swap = root;

        if(a[swap] > a[child])
            swap = child;
        if(child+1 <= end && a[swap] > a[child+1])
            swap = child + 1;
        if(swap == root)
            return;
        else{
            short temp = a[root];
	        a[root] = a[swap];
	        a[swap] = temp;
            root = swap;
        }
    }
};

void heapify(short *a, short count){
    short start = floor ((count - 2) / 2);
    
    while(start >= 0){
        siftDown(a, start, count - 1);
        start = start - 1;
    }
};

void reversedHeapsort(short a[], short count){
    heapify(a, count);
    short end = count - 1;
    while (end > 0){
        short temp = a[end];
	    a[end] = a[0];
	    a[0] = temp;
        end = end - 1;
        siftDown(a, 0, end);
    }
};

#endif //REVERSEDHEAPSORT