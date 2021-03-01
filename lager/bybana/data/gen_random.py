#!/usr/bin/python3

import sys
import random
import math
from make_solvable import make_solvable

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default

def linelengths(l,maxm,s):
    m = []
    k = max(1,s//maxm)
    st = s
    for i in range(l-1):
        mi = random.randint(2,max(2,2*st//k))
        mi = min(mi,maxm)
        mi = max(mi,math.ceil(st/(l-i)))
        if 2*(l-i)>st-mi:
            mi = 2
        m.append(mi)
        st -= mi
    m.append(st)
    while m[-1] <= 1:
        m[-2] += m[-1]
        m.pop()
        
    assert(len(m)<=l)
    assert(max(m)<=maxm)
    assert(sum(m)==s)
    return m

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))
l = int(cmdlinearg('l'))
maxm = int(cmdlinearg('maxm'))
s = int(cmdlinearg('s'))
mode = cmdlinearg('mode',"random")

lines = []
if l == 1:
    lines.append(random.sample(list(range(0,n)), min(maxm,n)))
else:
    s -= 2*int(l*0.2)
    l -= int(l*0.2)

    m = linelengths(l,maxm,s)

    if mode == "random":
        for mi in m:
            lines.append(random.sample(list(range(0,n)), min(mi,n)))
    elif mode == "long":
        order = list(range(l))+[n-1]
        c = l
        for i,mi in enumerate(m):
            line = order[i:i+min(mi,4)]
            while c!=n-1 and len(line)<mi:
                line.append(c)
                c+=1
            random.shuffle(line)
            lines.append(line)
    elif mode == "pairs":
        order = list(range(l))+[n-1]
        c = l
        for i,mi in enumerate(m):
            a = random.randint(0,len(order)-1)
            b = a
            while b==a:
                b = a + random.randint((-mi-1)//2,(mi+1)//2)
                b = max(b,0)
                b = min(len(order)-1,b)
            line = [order[a],order[b]]
            while c!=n-1 and len(line)<mi:
                line.append(c)
                c+=1
            line = line[len(line)//2:] + line[:len(line)//2]
            lines.append(line)
    else:
        raise Exception("Invalid mode")
    
    lines = make_solvable(n,lines)

p = list(range(1,n-1))
random.shuffle(p)
p = [0]+p+[n-1]

print(n,len(lines))
for l in lines:
    print(len(l),end=" ")
    print(" ".join([str(p[v]+1) for v in l]))
    