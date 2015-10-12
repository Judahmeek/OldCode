def solution(array):
    size = len(array)
    if size == 0:
        return -1
    sum = 0
    before = []
    for i in range(size):
        sum = sum + array[i]
        before.append(sum)
    if (sum - array[0]) == 0:
        return 0
    for i in range(1, size):
        res = sum - (array[i] + before[i-1])
        if res == before[i-1]:
            return i
    return -1