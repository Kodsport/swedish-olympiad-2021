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
n = int(cmdlinearg("n"))
k = int(cmdlinearg("k"))
h = int(cmdlinearg("h"))


d = [0]*(n-1)

ans = 0
for i in range(n-2,-1,-1):
    if random.uniform(0,1)<0.6:
        d[i] = ((ans-1)*(k-1)+h-1)//h + random.randint(0,200)
    else:
        d[i] = random.randint(0,((ans-1)*(k-1)+h-1)//h+10)
    
    ans = max(ans,(d[i]*h+ans+k-1)//k)

    assert(d[i]<1000)

for i in range(len(d)):
    d[i]=max(1,d[i])

assert(ans<2e17)

print(n,k,h)
print(" ".join(map(str,d)))
