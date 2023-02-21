#!/usr/bin/python3

import sys
from random import randint
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
n = int(cmdlinearg("n"))
m = int(cmdlinearg("m"))
max_dots = int(cmdlinearg("max_dots", m))

print(n,m)
for i in range(n):
    while True:
        row =[]
        for j in range(m):
            k = randint(0,3);
            if(k == 0): row.append('#')
            else: row.append('.')

        if row.count('.')<=max_dots:
            print("".join(row))
            break
