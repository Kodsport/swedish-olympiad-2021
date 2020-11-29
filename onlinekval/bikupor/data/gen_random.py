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
m = int(cmdlinearg('m'))
k = int(cmdlinearg('k'))

edge_set = set()
edges = []

for i in range(1, n):
    root = random.randrange(0, i)
    edges.append((root, i))
    edge_set.add((root, i))
    edge_set.add((i, root))

for i in range(0, m-n+1):
    i = random.randrange(0, n)
    j = random.randrange(0, n)
    while i == j or (i,j) in edge_set:
        i = random.randrange(0, n)
        j = random.randrange(0, n)
    edges.append((i, j))
    edge_set.add((i, j))
    edge_set.add((j, i))

print(n,m,k)
for (i,j) in edges:
    print(i+1, j+1)