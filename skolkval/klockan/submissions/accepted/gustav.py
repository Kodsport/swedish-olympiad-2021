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
a = 0
b = -1
s = 0
ans = 0
while(b < 24*60*60):
    if(s == n): ans+=1
    if(s <= n):
        b += 1
        s += energy(b)
    else:
        s -= energy(a)
        a += 1
print(ans)
