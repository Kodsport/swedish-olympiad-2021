#!/usr/bin/env python3
n = int(input())
differences = []
for i in range(n):
    f, m = [int(i) for i in input().split()]
    if f == m:
        continue
    # differences[i] = (abs(diff), -1 if filip == winner else 1)
    differences.append((abs(m-f), -1 if f > m else 1))
# protect against out of bounds error
differences.append((0, 0))
differences.append((1e9, 0))
# sorts in decreasing order with the matches that Filip won last
# when they have the same difference this will result in only
# looking at the last game of every difference because total_wins
# will be the highest otherwise you might think that a k is better than it is.
# ex:        (5, filip), (5,maria), (4, maria)...
# total_wins     1     ,    0     ,    -1
# looks like k = 5 will give you 1 win but really it should be:
#            (5, maria), (5, filip), (4, maria)...
# total_wins     -1    ,      0    ,     -1
differences.sort(reverse=True)
best = (0, 0)
won_matches = 0
for i in range(len(differences)-1):
    # adds the result of the game to the total
    won_matches -= differences[i][1]
    # less or equal because you want the lowest k
    if won_matches >= best[0]:
        # (won_matches, 1+(the differens of the next game))
        # because you will still have the same matches won but with a lower k
        best = (won_matches, differences[i+1][0])
print(best[1])  # best k
