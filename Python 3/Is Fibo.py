#https://www.hackerrank.com/challenges/is-fibo

#Problem Statement

#You are given an integer, N. Write a program to determine if N is an element of the Fibonacci sequence.

#The first few elements of the Fibonacci sequence are 0,1,1,2,3,5,8,13,⋯. A Fibonacci sequence is one where every element is a sum of the previous two elements in the sequence. The first two elements are 0 and 1.

#Formally: 
#fib0=0
#fib1=1
#fibn=fibn−1+fibn−2∀n>1
#Input Format 
#The first line contains T, number of test cases. 
#T lines follow. Each line contains an integer N.

#Output Format 
#Display IsFibo if N is a Fibonacci number and IsNotFibo if it is not. The output for each test case should be displayed in a new line.

#Constraints 
#1≤T≤105 
#1≤N≤1010

#Sample Input
#3
#5
#7
#8

#Sample Output
#IsFibo
#IsNotFibo
#IsFibo

#Explanation 
#5 is a Fibonacci number given by fib5=3+2 
#7 is not a Fibonacci number 
#8 is a Fibonacci number given by fib6=5+3

from collections import defaultdict

cases = int(input())
dct = defaultdict(set)
for i in range(cases):
	dct[int(input())].add(i)
fibo = 1
low = 1
high = 1
for numb, order in sorted(dct.items()):
	if numb == 1:
		dct[True] = dct[True].union(dct[numb])
	else:
		while fibo < numb:
			fibo = low + high
			low = high
			high = fibo
		if fibo == numb:
			dct[True] = dct[True].union(dct[numb])
for i in range(cases):
    print("IsFibo" if i in dct[True] else "IsNotFibo")