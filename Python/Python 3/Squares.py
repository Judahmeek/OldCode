#https://www.hackerrank.com/contests/interfacecse-codedash/challenges/squares2

#Problem Statement

#Ram gives two integers A & B to Sai and asks if he can count the number of square integers between A and B (both inclusive).

#A square integer is an integer which is the square of any integer. For example, 1, 4, 9, 16 are some of the square integers as they are squares of 1, 2, 3, 4 respectively.

#Input Format 
#First line contains T, the number of testcases. T test cases follow, each in a newline. 
#Each testcase contains two space separated integers denoting A and B.

#Output Format 
#For each testcase, print the required answer in a new line.

#Constraints 
#1 ≤ T ≤ 100 
#1 ≤ A ≤ B ≤ 109

#Sample Input
#2
#3 9
#17 24

#Sample output
#2
#0

#Explanation 
#In the first testcase, 4 and 9 are the square numbers. 
#In second testcase no square numbers exist between 17 and 24 (both inclusive).

from math import sqrt, floor, ceil

cases = int(input())
for i in range(cases):
    bounds = input().split()
    low = ceil(sqrt(int(bounds[0])))
    high = floor(sqrt(int(bounds[1])))
    if low > high:
        print('0')
    elif low == high:
        print('1')
    else:
        print(str((high - low) + 1))
