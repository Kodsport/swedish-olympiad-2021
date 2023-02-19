#!/usr/bin/python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))

def solve(n):
    ans = 0
    while n>0:
        v = 1
        while v*10+1<=n:
            v = 10*v+1
        n-=v
        ans+=1
    return ans


n = int(cmdlinearg('n'))
mode = cmdlinearg("mode","default")

if mode=="default":
    print(n)
elif mode=="largeans":
    bestn = -1
    bestits=-1
    for i in range(100):
        c = random.randint(1, n)
        its = solve(c)
        if its>bestits:
            bestits=its
            bestn=c
    print(c)