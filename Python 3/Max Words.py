import string

def solution(string):
    max = 0
    words = 0
    space = False
    first = True
    for i in range(len(string)):
        if string[i].isspace():
            space = True
        elif string[i].isalpha() and space:
            words = words + 1
            space = False
			if first:
				first = False
        elif string[i].isalpha() and first:
            words = words + 1
            first = False
        elif not (string[i].isalpha() or string[i].isspace()):
            if words > max:
                max = words
            words = 0
			first = True
    if words > max:
        max = words
    return max
	
#https://codility.com/c/feedback/X6ASAS-XYK
#
#Test Cases:
#No letters
#No spaces
#No punctuation
#Multiple sentences
