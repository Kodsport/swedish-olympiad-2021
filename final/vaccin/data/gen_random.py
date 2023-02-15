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
K = int(cmdlinearg("k"))
print(N, K)
for i in range(N):
	print(random.randint(0, 15), end=(" " if i!=N-1 else ""))
print()
for i in range(K):
	print(random.randint(0, N*10), end=(" " if i!=K-1 else ""))
print()
