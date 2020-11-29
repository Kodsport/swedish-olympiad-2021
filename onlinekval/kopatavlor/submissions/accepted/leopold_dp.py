#!/usr/bin/env python3
import sys
sys.setrecursionlimit(150000)
mem = [[-1 for _ in range(2001)] for _ in range(2001)]

n,k = [int(i) for i in input().split()]
l = [int(i) for i in input().split()]

def dp(ind, left):
    if left == 0:
        return 0
    global mem, k, l, n
    if ind == n:
        return 1e9
    if mem[ind][left] != -1:
        return mem[ind][left]
    else:
        mem[ind][left] = min(dp(ind+1, k),1+dp(ind+1, left), 1+l[ind]+dp(ind+1, left-1))
    return mem[ind][left]

print(dp(0, k)-1)
