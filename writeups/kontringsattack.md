# Kontringsattack

### 50p
För 50 poäng testar vi alla k mellan 0 och den största skillnaden mellan Friberg och Skog på en match (vi kan sätta in 1000 då poängen är mindre än 1000). För varje k räknar vi differensen mellan antalet matcher då Friberg är bättre och antalet matcher då Skog är bättre och skriver ut det k som ger störst differens.

Tidskomplexitet: O(n max(F, S)) ≈ 10^6 operationer

```python
#!/usr/bin/env python3
n = int(input())
matcher = []
for i in range(n):
    match = input().split()
    f = int(match[0])
    s = int(match[1])
    matcher.append([f, s])

def lika(f, s, k):
    skillnad = abs(f-s)
    if skillnad <= k:
        return True
    else:
        return False


bästa_diff = -1
bästa_k = -1
for k in range(1001):
    diff = 0
    for match in matcher:
        if not lika(match[0], match[1], k):
            if match[0] > match[1]:
                diff += 1
            else:
                diff -= 1
    if diff > bästa_diff:
        bästa_diff = diff
        bästa_k = k
print(bästa_k)
```

### 100p
För 100 poäng kan vi inte gå igenom alla matcher för varje k. Istället vill vi gå igenom matcherna på så sätt att det räcker att göra det en gång. Detta kan vi åstakomma genom att gå igenom matcherna i sorterad ordning så att vi börjar på matchen med störst skillnaden mellan Friberg och Skog och slutar på den med minst. Vi använder en variabel w där vi sparar antalet fler matcher som Friberg har vunnit, samtidigt vet vi att tillhörande k:et är skillnad på nästa match. På så sätt behöver vi bara sparar k värdet då w är som störst. 

Tidskomplexitet: O(n log(n))

```python
#!/usr/bin/env python3
n = int(input())
differences = []
for i in range(n):
    f, m = [int(i) for i in input().split()]
    if f == m:
        continue
    # differences[i] = (abs(diff), -1 if Friberg == winner else 1)
    differences.append((abs(m-f), -1 if f > m else 1))
# protect against out of bounds error and makes sure that we check k=0
differences.append((0, 0))
differences.append((1e9, 0))
# sorts in decreasing order with the matches that Filip won last
# when they have the same difference this will result in only
# looking at the last game of every difference because total_wins
# will be the highest otherwise you might think that the current k is better than it is.
# ex:        (5, Friberg), (5, Skog), (4, Friberg)...
# total_wins     1     ,    0     ,    -1
# looks like k = 5 will give you 1 win but really it should be:
#            (5, Skog), (5, Friberg), (4, Skog)...
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
```

Lite kortare kod för dem som vill:

Python2 159 bytes
```python
b=(0,1e9);w=0
for c,d in sorted([b]+[(lambda f,m:(-abs(m-f),cmp(f,m)))(*map(int,raw_input().split()))for _ in'0'*input()]):
 b=min(b,(w,-c));w-=d
print b[1]
```

Python3 169 bytes
```python
b=(0,1e9);w=0
for c,d in sorted([b]+[(lambda f,m:(-abs(m-f),1 if f>m else -1))(*map(int,input().split()))for _ in'0'*int(input())]):
 b=min(b,(w,-c));w-=d
print(b[1])
```
