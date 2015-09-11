#ifndef BUFFERSIGNATURE
#define BUFFERSIGNATURE

#include "arraySum.c"

void bufferSignature(const short freq[], const short freqSize, const short state[], const short sigSize, short result[]){
	short i, j = 0;
	
	short copy[freqSize];
	for(i = 0; i < freqSize; ++i){
		copy[i] = freq[i];
	}
	
	short total = 0;
	for(i = 0; i < sigSize; ++i){
		total += arraySum (copy, freqSize) - copy[state[j]];
		result[i] = total;
		--copy[state[j]];
		++j;
	}
}

#endif //BUFFERSIGNATURE
