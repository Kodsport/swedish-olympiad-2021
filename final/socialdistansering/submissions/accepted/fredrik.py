#!/usr/bin/env python3

n,m,k = list(map(int,input().split()))

intv = []

for i in range(m):
    intv.append(list(map(int,input().split())))
    intv[-1][1] += 1

intv.sort(key=lambda x:x[0])

okintv = []
last = 0
for l,r in intv:
    okintv.append([last,l])
    last = r
okintv.append([last,k])


def test(dist):
    last = -1e18
    num = 0
    for l,r in okintv:
        l = max(l,last+dist)
        place = (r-l+dist-1)//dist
        if place>0:
            last = l+dist*(place-1)
            num+=place
    return num>=n

dn = 1
up = k+1

while dn+1<up:
    mid = (dn+up)//2
    if test(mid):
        dn = mid
    else:
        up = mid

print(dn)





