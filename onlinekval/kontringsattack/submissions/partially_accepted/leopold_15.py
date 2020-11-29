#!/usr/bin/env python3
n = int(input())
differences = []
for i in range(n):
    f, m = [int(i) for i in input().split()]
    differences.append(f-m)

def cc(k):
    return len([True for i in differences if i > k]) - len([True for i in differences if i < -1*k])
mx = (-1e9, 0)
for i in range(31):
    cur = cc(i)
    if mx[0] < cur:
        mx = (cur, i)
print(mx[1])
