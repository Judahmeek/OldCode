def switch(x):
    return {
        '(': 1,
        ')': -1,
        '{': 2,
        '}': -2,
        '[': 3,
        ']': -3,
        '<': 4,
        '>': -4,
    }.get(x, 0)

input = input()

inputFreq = [0]*5 #({[<

for i in range(len(input)):
	target = switch(input[i])
	pos = abs(target)
	if target > 0:
		inputFreq[pos] = inputFreq[pos] + 1
	if target < 0:
		inputFreq[pos] = inputFreq[pos] - 1

j = 0
stillOK = True
while j<5 and stillOK:
	if inputFreq[j] == 0:
		j = j + 1
	else:
		stillOK = False

print(stillOK)
