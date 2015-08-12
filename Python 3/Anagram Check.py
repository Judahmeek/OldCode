first = input()
second = input()

firstFreq = [0]*26
secondFreq = [0]*26

for i in range(len(first)):
	pos = ord(first[i])-ord('a')
	firstFreq[pos] = firstFreq[pos] + 1

for i in range(len(second)):
	pos = ord(second[i])-ord('a')
	secondFreq[pos] = secondFreq[pos] + 1

j = 0
stillOK = True
while j<26 and stillOK:
	if firstFreq[j]==secondFreq[j]:
		j = j + 1
	else:
		stillOK = False

print(stillOK)
