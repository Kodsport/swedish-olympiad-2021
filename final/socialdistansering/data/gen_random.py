#!/usr/bin/python3

import sys
import random
import math

def cmdlinearg(name, default=None):
	for arg in sys.argv:
		if arg.startswith(name + "="):
			return arg.split("=")[1]
	if default is None:
		print("missing parameter", name)
		exit(1)
	return default

N = int(cmdlinearg("n"))
M = int(cmdlinearg("m"))
K = int(cmdlinearg("k"))

blockedStart = int(cmdlinearg("blockedStart", 0))
blockedEnd = int(cmdlinearg("blockedEnd", 0))

assert K - N >= 2 * M

print(N, M, K)

points = set()
if blockedStart:
	points.add(0)
if blockedEnd:
	points.add(K - 1)
while len(points) < 2 * M:
	points.add(random.randint(0, K - 1))
points = sorted(points)

intvs = [(points[i * 2], points[i * 2 + 1]) for i in range(M)]

for i in range(random.randint(0, M // 2)):
	idx = random.randrange(0, len(intvs))
	x = random.randint(intvs[idx][0], intvs[idx][1])
	intvs[idx] = (x, x)

numEmpty = 0
emptyBegin = 0
for (st, ed) in intvs:
	numEmpty += st - emptyBegin
	emptyBegin = ed + 1
numEmpty += K - emptyBegin

longIntervals = list(filter(lambda i: intvs[i][1] - intvs[i][0] > 1, range(0, len(intvs))))
random.shuffle(longIntervals)
while numEmpty < N:
	idx = longIntervals[-1]
	step = min(N - numEmpty, intvs[idx][1] - intvs[idx][0] - 1)
	intvs[idx] = (intvs[idx][0] + step, intvs[idx][1])
	numEmpty += step
	longIntervals.pop()

random.shuffle(intvs)
for intv in intvs:
	print(*intv)
