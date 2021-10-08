#!env /bin/python3
from collections import deque

h,w,p = list(map(int,input().split()))

g = [input() for i in range(h)]

start = None
end = None
for i in range(h):
    for j in range(w):
        if g[i][j] == 'S':
            start = (i,j)
        if g[i][j] == 'G':
            end = (i,j)

dist = [[1e18]*w for _ in range(h)]

q = deque()
q.append((0,start))

while len(q)>0:
    d,(r,c) = q.popleft()
    if end==(r,c):
        print(d)
        exit()
    
    for dr,dc in [[0,1],[0,-1],[1,0],[-1,0]]:
        for i in range(1,p+1):
            r1 = r+dr*i
            c1 = c+dc*i
            if r1<0 or c1<0 or r1>=h or c1>=w or g[r1][c1]=='#' or dist[r1][c1]<=d:
                break
            if dist[r1][c1]==d+1:
                continue
            dist[r1][c1] = d+1
            q.append((d+1,(r1,c1)))

