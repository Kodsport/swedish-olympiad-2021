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
valid = int(cmdlinearg('valid', 1))

points = set()
print(n, d)

start = random.randint(0, 1)

for i in range(0, n):
    x = random.randint(1, max_x)
    while x in points or (d%2 == 1 and valid == 1 and x%2 != (start+i)%2):
        x = random.randint(1, max_x)
    points.add(x)

print(*points)