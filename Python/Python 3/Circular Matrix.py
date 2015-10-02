#https://www.hackerrank.com/contests/interfacecse-codedash/challenges/dash-4

#Problem Statement

#CIRCULAR MATRIX

#RamPrasath wants to learn about the number system with anyone of the mathematical model.so,he decided to study the number system with the matrix.

#The problem is you want to print the given matrix in the following form

#Input Format
#There will be two lines of input:

#n - No. of Testcases
#i - No. of Rows,Columns
#It is square matrix always.

#1 ≤ n,i≤ 100

#Output Format

#CIRCULAR MATRIX

#Sample Input

#1

#3

#Sample Output

#1 8 7

#2 9 6

#3 4 5

cases = int(input())
for j in range(cases):
    input()
    size = int(input())
    elements = [[0 for x in range(size)] for x in range(size)]
    x,y,length,d,i = 0,-1,size,1,0
    for k in range(1, 2*size):
        if k % 2 == 0:
            length -= 1
            goal = x + d * length
            while x != goal:
                i += 1
                x += d
                elements[y][x] = i
            d *= -1
        else:
            goal = y + d * length
            while y != goal:
                i += 1
                y += d
                elements[y][x] = i
    for m in range(size):
        print(' '.join([str(x) for x in elements[m]]))
        print("")