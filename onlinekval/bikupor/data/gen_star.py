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
for i in range(0, n):
    if i+1 != mid:
        print(mid, i+1)