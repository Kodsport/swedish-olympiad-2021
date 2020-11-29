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

k -= k%3
k3 = k//3

print(n,n-1,k)

for i in range(1, k3+1):
    print(n-k+i, n-k+i+k3)
    print(n-k+i, n-k+i+2*k3)
    if i < k3:
        print(n-k+i+k3, n-k+i+k3+1)

for i in range(1, n-k+1):
    print(i, n)
