#!/usr/bin/env python3

C = int(input())
(N, T) = map(int, input().split())
ans = []
nodes = []
for i in range(0, N):
    nodes.append(map(int, input().split()))
    bla = input()
for i in range(0, N):
    (ti, vi, ki) = nodes[N-i-1]
    T -= ti
    if T >= 0:
        ans.append(N-i-1)
print(len(ans))
print(*ans)