#! /usr/env python3
import random
random.seed(0)
n,q = list(map(int,input().split()))
v = 0

def ask(x,y,z):
    global q,v
    if q==1:
        answer(v)
    q -= 1
    print("? {} {} {}".format(x+1,y+1,z+1))
    return int(input())-1

def answer(x):
    print("! {}".format(x+1))
    exit()

def sortline(nodes, s):
    if len(nodes) <= 1:
        return nodes
    random.shuffle(nodes)
    p = nodes[0]
    l = []
    r = []
    for ni in nodes[1:]:
        if ask(s,ni,p)==ni:
            l.append(ni)
        else:
            r.append(ni)
    return sortline(l,s) + [p] + sortline(r,s)

nodes = list(range(1,n))

while len(nodes)>0:
    random.shuffle(nodes)
    p = nodes[0]
    subtree = [p]
    line = set([p])
    linesizes = {}
    linesizes[p] = 1
    nonsubtree = []
    for ni in nodes[1:]:
        a = ask(v,p,ni)
        if a!=v:
            subtree.append(ni)
            line.add(a)
            linesizes.setdefault(a,0)
            linesizes[a] += 1
        else:
            nonsubtree.append(ni)

    if len(subtree)<=n/2:
        nodes = nonsubtree
    else:
        line = sortline(list(line),v)
        si = 0
        for li in line[::-1]:
            si += linesizes[li]
            if si>n/2:
                v = li
                break
        nodes = subtree
        if v in nodes:
            nodes.remove(v)

answer(v)
    