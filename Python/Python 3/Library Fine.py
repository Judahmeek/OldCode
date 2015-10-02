#Problem Statement

#The Head Librarian at a library wants you to make a program that calculates the fine for returning the book after the return date. You are given the actual and the expected return dates. Calculate the fine as follows:

#If the book is returned on or before the expected return date, no fine will be charged, in other words fine is 0.
#If the book is returned in the same month as the expected return date, Fine = 15 Hackos × Number of late days
#If the book is not returned in the same month but in the same year as the expected return date, Fine = 500 Hackos × Number of late months
#If the book is not returned in the same year, the fine is fixed at 10000 Hackos.

#Input Format

#You are given the actual and the expected return dates in D M Y format respectively. There are two lines of input. The first line contains the D M Y values for the actual return date and the next line contains the D M Y values for the expected return date.

#Constraints 
#1≤D≤31 
#1≤M≤12 
#1≤Y≤3000

#Output Format

#Output a single value equal to the fine.

#Sample Input

#9 6 2015
#6 6 2015

#Sample Output

#45

#Explanation

#Since the actual date is 3 days later than expected, fine is calculated as 15×3=45 Hackos.

#Summary

#Input data
#Calculate Fine
#Output Fine

PseudoCode:

#Input actual timedate
#Input expected timedate
#check if actDate <= expDate
#if not
	#check if actMonth == expMonth
	#if not
		#check if actYear == expYear
		#if not
			#calculate fine
		#else
			#calculate fine
	#else
		#calculate fine
#else
	#calculate fine
	
#output fine


#Refined PseudoCode



#Code

date = [int(x) for x in input().split()]
aDay,aMonth,aYear = date[0],date[1],date[2]

date = [int(x) for x in input().split()]
eDay,eMonth,eYear = date[0],date[1],date[2]

if aDay + aMonth*31 + aYear*380 > eDay + eMonth*31 + eYear*380:
    if aYear == eYear:
        if aMonth == eMonth:
            fine = 15*(aDay-eDay)
        else:
            fine = 500*(aMonth-eMonth)
    else:
        fine = 10000
else:
    fine = 0
	
print(str(fine))