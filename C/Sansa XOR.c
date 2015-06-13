/* https://www.hackerrank.com/contests/interfacecse-codedash/challenges/sansa-and-xor

Problem Statement
Sansa has an array. She wants to find the value obtained by XOR-ing the contiguous subarrays, followed by XOR-ing the values thus obtained. Can you help her in this task?

Note : [5,7,5] is contiguous subarray of [4,5,7,5] while [4,7,5] is not.

Input Format 
First line contains an integer T, number of the test cases. 
The first line of each test case contains an integer N, number of elements in the array. 
The second line of each test case contains N integers that are elements of the array.

Output Format 
Print the answer corresponding to each test case in a seperate line.

Constraints 
1≤T≤5 
2≤N≤105 
1≤numbers in array≤108

Sample Input
2
3
1 2 3
4
4 5 7 5

Sample Output
2
0

Explanation

Test case #00: 
1∆2∆3∆(1∆2)∆(2∆3)∆(1∆2∆3)= 2 

Test case #01: 
4∆5∆7∆5∆(4∆5)∆(5∆7)∆(7∆5)∆(4∆5∆7)∆(5∆7∆5)∆(4∆5∆7∆5)=0

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int cases, res;
    scanf("%d",&cases);
    for(int o = 0; o<cases; ++o){
        int size;
        scanf("%d",&size);
        int a[size];
        for(int i = 0; i < size; ++i)
                scanf("%d", &a[i]);
        if(size % 2 == 0){
            puts("0");
        }else {
            res = a[0];
            for(int i = 2; i < size; i += 2){
                res ^= a[i];
            }
            printf("%d\n", res);
        }
    }
    return 0;
}