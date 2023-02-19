#!/usr/bin/python3

n = int(input())
ans = 0
while n>0:
    v = 1
    while v*10+1<=n:
        v = 10*v+1
    n-=v
    ans+=1 

print(ans)