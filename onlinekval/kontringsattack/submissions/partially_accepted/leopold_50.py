#!/usr/bin/env python3
n = int(input())
differences = []
ks = [0]

for i in range(n):
    f, m = [int(i) for i in input().split()]
    if f==m:
        continue
    differences.append(f-m)
    if(f>m):
        continue
    ks.append(abs(f-m))

ks.sort()

def cc(k):
    return len([True for i in differences if i > k]) - len([True for i in differences if i < -1*k])
mx = (-1e9, 0)
for i in ks:
    cur = cc(i)
    if mx[0] < cur:
        mx = (cur, i)
print(mx[1])
