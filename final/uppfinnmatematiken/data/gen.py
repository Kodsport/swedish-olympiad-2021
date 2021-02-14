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

print(cmdlinearg('tc'))

N = int(cmdlinearg('N'))
T = int(cmdlinearg('T'))
K = int(cmdlinearg('K'))

mode = cmdlinearg('mode', 'random')

t = []
v = []
a = []

print(N,T)

def r():
    return int(10000*(random.uniform(0.3,1)**10))

if mode == 'random':
    for i in range(N):
        ai = random.sample(list(range(i)),random.randint(0,min(i,K)))
        ti = r()
        vi = r()
        print(ti,vi,len(ai))
        print(" ".join(list(map(str,ai))))

if mode == 'downtree':
    K = 1
    for i in range(N):
        ti = r()
        vi = r()
        if i==0:
            ai = []
        else:
            ai = [int(random.uniform(0,1)**2*i)]
        print(ti,vi,len(ai))
        print(" ".join(list(map(str,ai))))
    
if mode == 'uptree':
    K = 1
    a = [[] for _ in range(N)]
    for i in range(N-2,-1,-1):
        a[random.randint(i+1,N-1)].append(i)
    
    for i in range(N):
        print(r(),r(),len(a[i]))
        print(" ".join(list(map(str,a[i]))))

exit()
for i in range(N):
    print(i)
    t.append(random.randint(0, 1000))
    v.append(random.randint(0, 1000))
    a.append(random.sample(list(range(i)),random.randint(0,min(i,K))))

for i in range(N):
    print(t[i],v[i],len(a[i]))
    print(" ".join(list(map(str,a[i]))))
