from collections import deque

seen = []
components = []

def bfs(s,e):
    global seen
    components.append([])
    q = deque()
    q.append(s)
    while len(q)>0:
        v = q.pop()        
        if seen[v]:
            continue
        seen[v] = True
        components[-1].append(v)
        for u in e[v]:
            if not seen[u]:
                q.append(u)
    return 

def make_solvable(n,lines):
    global seen
    seen = [False]*n

    e = [[] for _ in range(n)]
    for l in lines:
        for a,b in zip(l[:-1],l[1:]):
            e[a].append(b)
            e[b].append(a)

    for v in [0]+[n-1]+list(range(1,n-1)):
        if not seen[v]:
            bfs(v, e)
    
    if len(components)==1:
        return lines
    
    components[1],components[-1] = components[-1],components[1]
    components[-1] = components[-1][::-1]
    extralines = []
    for i in range(len(components)-1):
        extralines.append([components[i][-1],components[i+1][0]])
    return extralines + lines