#!/usr/bin/python3

import sys
import random
import math

def cmdlinearg(name, default=None):
	for arg in sys.argv:
		if arg.startswith(name + "="):
			return int(arg.split("=")[1])
	if default is None:
		print("missing parameter", name)
		exit(1)
	return default

n, b, g = int(cmdlinearg("n")), int(cmdlinearg("b")), int(cmdlinearg("g"))
assert 1 <= g <= 5

assert n*b <= 200000

erange = (cmdlinearg("minE",0), cmdlinearg("maxE",1000))
wrange = (cmdlinearg("minW",0), cmdlinearg("maxW",1000))
crange = (cmdlinearg("minC",0), min(b, cmdlinearg("maxC",1000)))

w = random.randint(*wrange)
w = max(1,w);

batteries = []

nn = n

if g == 1:
	assert n <= 20
	
if g == 2:
	wrange = (0, 0)

if g == 3:
	c = random.randint(crange[0], crange[1])
	crange = (c, c)

if g == 5:
	w = int(1000)
	batteries.append((int(1000), int(1000), 1))
	erange = (100, 150)
	wrange = (100, 150)
	nn-=1

for x in range(nn):
	batteries.append((random.randint(*erange), random.randint(*wrange), random.randint(*crange)))


print(n, b, w)
for b in batteries:
	print(*b)
	

	

