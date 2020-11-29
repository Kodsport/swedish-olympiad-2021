#!/usr/bin/env python3
import heapq

class Pqueue:
    def __init__(self, k):
        self.q = []
        self.tot = k-1
        self.k = k
        self.mn = 1e9
    def add(self, val):
        if len(self.q) < k:
            heapq.heappush(self.q, val*-1)
            self.tot+=val
            if len(self.q) == k: 
                self.mn = min(self.mn, self.tot)
        else:
            self.tot+=1
            top = heapq.heappop(self.q)*-1
            if self.tot + val - top <= self.tot:
                self.tot += val - top
                self.mn = min(self.mn, self.tot)
                heapq.heappush(self.q, val*-1)
            else:
                heapq.heappush(self.q, top*-1)



n, k = [int(i) for i in input().split()]
l = [int(i) for i in input().split()]
mn = 1e9
n = len(l)
for start in range(n-k+1):
    curl = Pqueue(k)
    for j in range(start, n):
        curl.add(l[j])
    mn = min(mn, curl.mn)
print(mn)
