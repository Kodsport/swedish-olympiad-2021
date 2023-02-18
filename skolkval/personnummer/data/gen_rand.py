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

symbol = cmdlinearg('symbol')

print(random.randint(21, 99), end="")
print(str(random.randint(1,12)).zfill(2),end="")
print(str(random.randint(1,28)).zfill(2),end="")

print(symbol,end="")
print(str(random.randint(0,9999)).zfill(4))
