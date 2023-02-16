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
        sys.exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
hi = int(cmdlinearg('hi', 1000))
noeq = bool(cmdlinearg('noeq', 0))

if noeq:
    while True:
        a = random.randint(0, hi)
        b = random.randint(0, hi)
        if a*7!=b*13:
            print(a, b)
            break
else:
    print(random.randint(0, hi), random.randint(0, hi))