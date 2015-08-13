int equiIndex(int array[], int size) {
    long before[size];
    long sum = 0;
    for(int i = 0; i<size; ++i){
        sum += array[i];
        before[i] = sum;
    }
	if(!size)
		return -1;
    if((sum - array[0]) == 0)
        return 0;
    for(int i = 1; i<size; ++i){
        int res = sum - (array[i] + before[i-1]);
        if(res == before[i-1])
            return i;
    }
    return -1;
}