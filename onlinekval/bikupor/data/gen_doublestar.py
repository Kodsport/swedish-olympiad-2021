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
mid = int(cmdlinearg('mid'))
k = int(cmdlinearg('k'))

print(n,n-1,k)

for i in range(0, k-2):
    print(n-1, n-2-i)
print(mid, n-1)
for i in range(1, n-k+1):
    print(i, n)
