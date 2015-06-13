#https://www.hackerrank.com/contests/interfacecse-codedash/challenges/stones2

#Problem Statement

#Ram is out on a hike with friends. he finds a trail of stones with numbers on them. he starts following the trail and notices that two consecutive stones have a difference of either a or b. Legend has it that there is a treasure trove at the end of the trail and if Ram can guess the value of the last stone, the treasure would be for him. Given that the number on the first stone was 0, find all the possible values for the number on the last stone.

#Note : The numbers on the stones are in increasing order

#Input Format 
#The first line contains an integer T i.e. the number of Test cases. T testcases follow. 
#Each testcase has 3 lines. The first line contains n ( the number of stones ) The second line contains a. The third line contains b.

#Output Format 
#Space separated list of numbers which are the possible values of the last stone in increasing order.

#Constraints 
#1 ≤ T ≤ 10 
#1 ≤ n, a, b ≤ 103

#Sample Input
#2
#3 
#1
#2
#4
#10
#100

#Sample Output
#2 3 4 
#30 120 210 300 

#Explanation

#All possible series for first test cases are given below.

#0,1,2
#0,1,3
#0,2,3
#0,2,4
#Hence the answer 2 3 4.

#Series with different number of final step for second test cases are

#0, 10, 20, 30
#0, 10, 20, 120
#0, 10, 110, 120
#0, 10, 110, 210
#0, 100, 110, 120
#0, 100, 110, 210
#0, 100, 200, 210
#0, 100, 200, 300
#hence the answer 30 120 210 300

cases = int(input())
for i in range(cases):
    steps = int(input())
    low = int(input())
    high = int(input())
    if low == high:
        print(str((steps - 1) * low))
    else:
        j = steps - 1
        poss = [None] * steps
        for k in range(steps):
            poss[k] = high * k + low * j
            j -= 1
        print(" ".join([str(i) for i in sorted(poss)]))