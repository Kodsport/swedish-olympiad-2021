#!env /bin/python3

import sys
sys.setrecursionlimit(100000)

n,k = input().split()
n = int(n)
k = int(k)
nuts = list(map(int, input().split()))
nut = [False for i in range(n)]
for nu in nuts:
    nut[nu-1] = True
e = [[] for i in range(n)]

for i in range(n-1):
    a,b = input().split()
    a = int(a)-1
    b = int(b)-1
    e[a].append(b)
    e[b].append(a)

def rec(v,l):
    ans = 0
    for u in e[v]:
        if u != l:
            ans += rec(u,v)
    if ans ==0 and not nut[v]:
        return 0
    else:
        return ans+2


print(rec(0,0)-2)
