#!/usr/bin/env python3
n,m = [int(i) for i in input().split()]
ans = m
for i in range(n):
    line = input()
    dots = 0
    for j in line:
        if(j == '.'):
            dots += 1
    ans *= dots
print(ans)
