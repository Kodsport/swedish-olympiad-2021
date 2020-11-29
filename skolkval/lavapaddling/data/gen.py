import random

n,k,h = list(map(int,input().split()))

d = [0]*(n-1)

ans = 0
for i in range(n-2,-1,-1):
    if random.uniform(0,1)<0.6:
        d[i] = ((ans-1)*(k-1)+h-1)//h + random.randint(0,200)
    else:
        d[i] = random.randint(0,((ans-1)*(k-1)+h-1)//h+10)
    
    ans = max(ans,(d[i]*h+ans+k-1)//k)
    assert(d[i]<1000)

assert(ans<2e17)

print(n,k,h)
print(" ".join(map(str,d)))
