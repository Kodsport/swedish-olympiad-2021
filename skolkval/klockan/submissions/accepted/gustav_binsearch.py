e = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]

def energy(p):
    seconds = p%60
    p//=60
    minutes = p%60
    p//=60
    hours = p
    return(e[seconds//10] + e[seconds%10] +
           e[minutes//10] + e[minutes%10] +
           e[hours // 10] + e[hours % 10])

psum = [0]
for i in range(24*60*60):
    psum.append(psum[-1] + energy(i))

n = int(input())
ans = 0
for a in range(24*60*60):
    lo = a
    hi = 24*60*60
    while(lo+1 < hi):
        med = (lo+hi)//2
        s = psum[med+1] - psum[a]
        if(s <= n): lo = med
        else: hi = med
    if(psum[lo+1]-psum[a] == n): ans+=1

print(ans)
