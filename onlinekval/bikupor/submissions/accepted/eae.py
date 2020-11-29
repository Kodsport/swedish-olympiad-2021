#!/bin/python3
from heapq import *
N, M, K = map(int, input().split())
adj = [[] for i in range(N)]
for i in range(M):
	a, b = map(int, input().split())
	adj[min(a, b) - 1].append(max(a, b) - 1)

for i in range(N - K):
	if max(adj[i], default=0) < N - K:
		print("1\n" + str(i + 1))
		exit(0)

ufParent = [-1] * N
def ufRoot(n):
	root = n
	while ufParent[root] != -1:
		root = ufParent[root]
	while ufParent[n] != -1:
		ufParent[n], n = root, ufParent[n]
	return root

compSize = [1] * N
compsPq = []
for n in range(N - 1, -1, -1):
	for nei in adj[n]:
		neiRoot, selfRoot = ufRoot(nei), ufRoot(n)
		if selfRoot != neiRoot:
			ufParent[selfRoot] = neiRoot
			compSize[neiRoot] += compSize[selfRoot]
			compSize[selfRoot] = 0
			heappush(compsPq, (compSize[neiRoot], neiRoot))
	if compSize[n] == 1:
		heappush(compsPq, (compSize[n], n))
	while compSize[compsPq[0][1]] != compsPq[0][0]:
		heappop(compsPq)
	minCompSize, minCompRoot = compsPq[0]
	remCompsSize = N - n - minCompSize
	if remCompsSize >= K:
		print(minCompSize)
		for i in range(N):
			if ufRoot(i) == minCompRoot:
				print(i + 1, end=" ")
		print()
		exit(0)
print(-1)
