#!/usr/bin/env python3
n = int(input())
s = input()
ans = n
prev = -n
for i in range(0, n):
    if s[i] == '.':
        ans = min(ans, i-prev-1)
        prev = i
print(ans)
