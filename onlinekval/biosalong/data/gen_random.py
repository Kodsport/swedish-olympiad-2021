#!/usr/bin/env python3
# Entirely random grid, with # occurring with probability 'box_ratio'.

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
free_ratio = float(cmdlinearg('free_ratio'))

print(n)
a = "".join([('.' if random.uniform(0,1) < free_ratio else '#') for _ in range(n)])
while a.count('.') < 2:
    i = random.randint(0, len(a)-1)
    a = a[:i] + '.' + a[(i+1):]
print(a)
