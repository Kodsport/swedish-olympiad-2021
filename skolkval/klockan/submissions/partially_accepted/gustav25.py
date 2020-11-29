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

n = int(input())
ans = 0
for a in xrange(24*60*60):
    if(energy(a) == n): ans+=1
print(ans)
