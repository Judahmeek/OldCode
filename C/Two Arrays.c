/* https://www.hackerrank.com/contests/interfacecse-codedash/challenges/two-arrays

Problem Statement
You are given two integer arrays, A and B, each containing N integers. The size of the array is less than or equal to 1000. You are free to permute the order of the elements in the arrays.

Now here's the real question: Is there an permutation A', B' possible of A and B, such that, A'i+B'i ≥ K for all i, where A'i denotes the ith element in the array A' and B'i denotes ith element in the array B'.


Input Format
The first line contains an integer, T, the number of test-cases. T test cases follow. Each test case has the following format:

The first line contains two integers, N and K. The second line contains N space separated integers, denoting array A. The third line describes array B in a same format.

Output Format
For each test case, if such an arrangement exists, output "YES", otherwise "NO" (without quotes).


Constraints
1 <= T <= 10
1 <= N <= 1000
1 <= K <= 109
0 <= Ai, Bi ≤ 109


Sample Input
2
3 10
2 1 3
7 8 9
4 5
1 2 2 1
3 3 3 4

Sample Output
YES
NO

Explanation

The first input has 3 elements in Array A and Array B, we see that the one of the arrangements, 3 2 1 and 7 8 9 has each pair of elements (3+7, 2 + 8 and 9 + 1) summing upto 10 and hence the answer is "YES".

The second input has array B with three 3s. So, we need at least three numbers in A that are greater than 1. As this is not the case, the answer is "NO".

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void siftDown(int *a, int root, int end){

    while(root * 2 + 1 <= end){
        int child = root * 2 + 1;
        int swap = root;

        if(a[swap] < a[child])
            swap = child;
        if(child+1 <= end && a[swap] < a[child+1])
            swap = child + 1;
        if(swap == root)
            return;
        else{
            int temp = a[root];
	        a[root] = a[swap];
	        a[swap] = temp;
            root = swap;
        }
    }
};

void heapify(int *a, int count){
    int start = floor ((count - 2) / 2);
    
    while(start >= 0){
        siftDown(a, start, count - 1);
        start = start - 1;
    }
};

void heapsort(int *a, int count){
    heapify(a, count);
    int end = count - 1;
    while (end > 0){
        int temp = a[end];
	    a[end] = a[0];
	    a[0] = temp;
        end = end - 1;
        siftDown(a, 0, end);
    }
};

int main() {
    int cases;
    scanf("%d",&cases);
    for(int o = 0; o<cases; ++o){
        int size, goal, i, out = 1;
        scanf("%d %d", &size, &goal);
        int a[size], b[size];
        for(i = 0; i < size; ++i)
            scanf("%d", &a[i]);
        for(i = 0; i < size; ++i)
            scanf("%d", &b[i]);
        heapsort(a, size);
        heapsort(b, size);
        for(i = 0; i < size; ++i){
            if(a[i] + b[size - (i + 1)] < goal)
                out = 0;
        }
        if(out)
              puts("YES");
        else
              puts("NO");
    }
    return 0;
}