#!/usr/bin/env python3
n , k =[int(i) for i in input().split()]
if k == 1:
    print(min([int(i) for i in input().split()]))
elif k == 2:
    l = [int(i) for i in input().split()]
    mn = 1e9
    for i in range(len(l)-1):
        for j in range(i+1, len(l)):
            mn = min(mn , l[i]+(j-i)+l[j])
    print(mn)
