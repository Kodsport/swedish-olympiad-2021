#! env /bin/python3
import heapq

n,l = list(map(int,input().split()))
lines = [list(map(lambda x: int(x)-1,input().split()[1:])) for _ in range(l)]

e = [[] for _ in range(n)]
for li in lines:
    m = len(li)
    for i in range(m):
        e[li[0]].append((li[i],m-i-1))
        e[li[i]].append((li[0],m-i-1))
        e[li[-1]].append((li[i],i))
        e[li[i]].append((li[-1],i))

q = []
heapq.heappush(q, (0,0))
dist = [1e18]*n
while len(q)>0:
    d,v = heapq.heappop(q)
    if d >= dist[v]:
        continue
    dist[v] = d
    for u,du in e[v]:
        if du+d < dist[u]:
            heapq.heappush(q, ((du+d),u))

print(dist[n-1])