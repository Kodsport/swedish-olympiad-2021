#!/usr/bin/env python3

C = int(input())
(N, T) = map(int, input().split())
ans = []
for i in range(0, N):
    (ti, vi, ki) = map(int, input().split())
    bla = input()
    T -= ti
    if T >= 0:
        ans.append(i)
print(len(ans))
print(*ans)