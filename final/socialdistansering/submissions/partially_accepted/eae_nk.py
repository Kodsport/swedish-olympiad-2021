#!/usr/bin/python3
#@EXPECTED_GRADES@ RTE AC AC RTE RTE RTE
from math import inf

n, m, k = map(int, input().split())

blocked = [False] * k
for i in range(m):
	l, r = map(int, input().split())
	for x in range(l, r + 1):
		blocked[x] = True

nextNotBlocked = [0] * k
curNNB = k
for i in range(k - 1, -1, -1):
	if not blocked[i]:
		curNNB = i
	nextNotBlocked[i] = curNNB

def possible(dist):
	lastPos = 0
	while blocked[lastPos]:
		lastPos += 1
	for i in range(n - 1):
		nextPos = lastPos + dist
		if nextPos >= k:
			return False
		nextPos = nextNotBlocked[nextPos]
		if nextPos >= k:
			return False
		lastPos = nextPos
	return True

dist = k
while not possible(dist):
	dist -= 1
print(dist)
