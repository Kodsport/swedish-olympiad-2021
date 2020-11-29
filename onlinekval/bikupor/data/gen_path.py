#!/usr/bin/env python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))
k = int(cmdlinearg('k'))
b = int(cmdlinearg('b'))

big = list(range(n-k+1,n+1))
medium = list(range(n-k-b,n-k+1))
small = list(range(1,n-k-b))

print(n,n-1,k)

b_size = k//b
medium = n-k
for i in range(n-k+1,n):
    if i%b_size == 0:
        print(i, medium)
        print(medium, i+1)
        medium -= 1
    else:
        print(i, i+1)
while medium > 0:
    print(medium, n)
    medium -= 1
