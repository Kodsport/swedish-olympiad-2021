#! python3
n,q = input().split()
n,q = int(n),int(q)
perday = list(map(int,input().split()))

p_to_d = []
for i,p in enumerate(perday):
    for _ in range(p):
        p_to_d.append(i)

for p in list(map(int,input().split())):
    if p<len(p_to_d):
        print(p_to_d[p]+1)
    else:
        print(-1)