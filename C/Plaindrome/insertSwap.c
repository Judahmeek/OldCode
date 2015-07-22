#include "swap.c"

void insertSwap(swap* x, int partnerID, short index){
	(*x).partnerID = partnerID;
	(*x).index = index;
}
