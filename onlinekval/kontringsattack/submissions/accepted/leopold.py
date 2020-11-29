#!/usr/bin/env python3
n = int(input())
differences = []
for i in range(n):
    f, m = [int(i) for i in input().split()]
    if f == m:
        continue
    differences.append((abs(m-f), -1 if f > m else 1))
differences.append((0, 0))
differences.append((1e9, 0))
differences.sort(reverse=True)
best = (0, 0)
won_matches = 0
for i in range(len(differences)-1):
    won_matches -= differences[i][1]
    if won_matches >= best[0]:
        best = (won_matches, differences[i+1][0])
print(best[1])
