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

def solve(n):
    e = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]

    def energy(p):
        seconds = p%60
        p//=60
        minutes = p%60
        p//=60
        hours = p
        return(e[seconds//10] + e[seconds%10] +
            e[minutes//10] + e[minutes%10] +
            e[hours // 10] + e[hours % 10])

    a = 0
    b = -1
    s = 0
    ans = 0
    while(b < 24*60*60):
        if(s == n): ans+=1
        if(s <= n):
            b += 1
            s += energy(b)
        else:
            s -= energy(a)
            a += 1
    return ans


random.seed(int(cmdlinearg('seed', sys.argv[-1])))
maxn = int(cmdlinearg("n"))
mode = cmdlinearg("mode", "random")

if mode=="specific":
    print(maxn)
elif mode=="random":
    while True:
        n = random.randint(1,maxn)
        if solve(n):
            print(n)
            break
else:
    def larger(a,b): return a>b
    def smaller(a,b): return a<b

    func = -1
    bestans = -1
    if mode=="largeans":
        func=larger
    if mode=="smallans":
        func = smaller
        bestans=10000000

    best = -1
    i=0
    while i < 100 or best==-1:
        n = random.randint(1,maxn)
        ans = solve(n)
        if ans==0:
            continue
        
        if func(ans,bestans):
            bestans=ans
            best=n

        i+=1

    print(best)