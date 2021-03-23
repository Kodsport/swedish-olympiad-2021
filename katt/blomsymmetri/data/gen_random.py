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
        exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))
k = int(cmdlinearg('k'))
mode = cmdlinearg('mode',"random")
ans = int(cmdlinearg('ans', 0))

a = []

while n-len(a)>1:
    x = random.randint(1,k)
    a.append(x)
    a.append(x)

if n!=len(a):
    a.append(random.randint(1,k))
if mode == "sorted":
    a.sort()
elif mode == "almost":
    for i in range(0, n):
        if i > n-i-1:
            a[i] = a[n-i-1]
        else:
            a[i] = random.randint(1,k)
    for _ in range(ans):
        i = random.randrange(0, n-1)
        (a[i], a[i+1]) = (a[i+1], a[i])
else:
    random.shuffle(a)
print(n,k)
print(" ".join(map(str,a)))
