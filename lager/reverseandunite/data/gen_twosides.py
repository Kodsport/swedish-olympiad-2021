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
d = int(cmdlinearg('d'))
max_x = int(cmdlinearg('x'))
back = int(cmdlinearg('back', n//2))
odd = int(cmdlinearg('odd', 0))

print(n, d)

front = n - back
points = []
for i in range(0, front):
    if odd == 1:
        points.append(2*i+1)
    else:
        points.append(i+1)

for i in range(0, back):
    if odd == 1:
        points.append(max_x-2*i-max_x%2)
    else:
        points.append(max_x-i)

print(*points)