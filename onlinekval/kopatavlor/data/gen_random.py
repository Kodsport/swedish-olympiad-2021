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
k = int(cmdlinearg('k'))

max_t = float(cmdlinearg('max_t'))

print(n,k)
print(" ".join([str(random.randint(1,max_t)) for i in range(n)]))
