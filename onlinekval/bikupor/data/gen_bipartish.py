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
b = int(cmdlinearg('b'))
same = int(cmdlinearg('same'))

edge_set = set()
edges = []


stop = set()
if same == 1:
    for i in range(n-k+1, n):
        if i%(k//b) == (n-k)%(k//b):
            stop.add(i)
    b = len(stop)+1
else:
    stop = set(random.sample(range(n-k+1,n), b-1))

for i in range(n-k+1, n):
    if i not in stop:
        edges.append((i, i+1))
        edge_set.add((i, i+1))
        edge_set.add((i+1, i))
        m -= 1

for i in [*stop, n]:
    edges.append((1, i))
    edge_set.add((i, 1))
    edge_set.add((1, i))
    m -= 1

for i in range(2, n-k+1):
    j = random.randint(n-k+1, n)
    edges.append((i, j))
    edge_set.add((i, j))
    edge_set.add((j, i))
    m -= 1

while m > 0:
    i = random.randint(1, n-k)
    j = random.randint(n-k+1, n)
    while (i,j) in edge_set:
        i = random.randint(1, n-k)
        j = random.randint(n-k+1, n)
    edges.append((i,j))
    edge_set.add((i,j))
    edge_set.add((j,i))
    m -= 1

print(n,len(edges),k)
for (i,j) in edges:
    print(i, j)