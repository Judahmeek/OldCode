'''
Given the following parameters:
first: a list of strings representing source code
second: a list of string representing source code

return: True if first can be transformed into second by using a text editor's "find and replace"
functionality to modify variable names OR if first == second. Otherwise, return False
'''
import re

def plagiarism?(first, second):
    def sub(m):
        return '' if m.group() in s else m.group()
    if len(code1) != len(second):
        print "difference in number of lines"
        return False
    s = set()
    match = {}
    lines = zip(first, second)
    for pair in lines:
        control = [x for x in re.split("\W*", pair[0]) if x and not x[0].isdigit()]
        s |= set(control)
        test = [x for x in re.split("\W*", pair[1]) if x and not x[0].isdigit()]
        s |= set(test)
        if re.sub("\w+", sub, pair[0]) != re.sub("\w+", sub, pair[1]):
			print "code structure changed"
            return False
        if len(control) != len(test):
            print "difference in number of words"
            return False
        words = zip(control, test)
        for word in words:
            if word[0] in match:
                if word[1] != match[word[0]]:
                    print word[1], "doesnt match", word[0], "or", match[word[0]]
                    return False
            else:
                match[word[0]] = word[1]
    return True