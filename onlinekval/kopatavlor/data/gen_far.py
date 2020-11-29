#!/usr/bin/env python3

import sys
import random
import math

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))
k = int(cmdlinearg('k'))

print(n,k)
a = [str(random.randint(990,1000)) for i in range(n)]

a[random.randint(0,3)] = random.randint(1,10)
a[-random.randint(1,4)] = random.randint(1,10)
for i in range(k-2):
    j = random.randint(0, len(a)-1)
    a[j] = random.randint(1,10)

print(*a)
