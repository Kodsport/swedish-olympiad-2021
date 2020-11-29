#!/usr/bin/env python3
import sys

mem = [[-1 for _ in range(2001)] for _ in range(2001)]
n,k = [int(i) for i in input().split()]
l = [int(i) for i in input().split()]

for ind in range(n,-1,-1):
    for left in range(k+1):
        if left == 0:
            mem[ind][left] = 0
            continue
        if ind == n:
            mem[ind][left] = 1e9
            continue
        mem[ind][left] = min(mem[ind+1][k],1+mem[ind+1][left], 1+l[ind]+mem[ind+1][left-1])

print(mem[0][k]-1)
