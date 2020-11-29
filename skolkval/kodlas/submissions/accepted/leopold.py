#!/usr/bin/env python3
n, m = [int(i) for i in input().split()]

def dp(i, op):
    if i == n:
        return 1 if op > 0 else 0
    if mem[i][op] != -1:
        return mem[i][op]
    res = 0
    for j in codes[i]:
        res += dp(i+1, op&j)
    mem[i][op] = res
    return res

mem = [[-1 for _ in range(1<<m)] for _ in range(n)]
codes = []
for i in range(n):
    rotation = [0 for i in range(m)]
    cur = input()
    for i in range(m):
        for j in range(m):
            rotation[j]+=((cur[i] == '.')<<((i+j)%m))
    codes.append(rotation)

print(dp(0, (1<<m)-1))
