# Robotdammsugaren

Detta är ett rent simuleringsproblem.

Vi vill hålla koll på vår nuvarande position, och sedan exekvera varje kommando ett i taget. När vi exekverar ett kommando stegar vi vår nuvarande position i riktningen kommandot specifierar, tills nästa position är en låda. Medans vi stegar markerar vi också i vår karta att vi städat den rutan. I slutet kan vi sedan räkna i kartan hur många rutor vi städat.

I c++ går det bra att läsa in och spara kartan som strängar, som man uppdaterar medans man rör sig.
En detalj man måste tänka på i python dock är att strängar är "immutable", det vill säga man kan inte ändra på dem. Därför behöver vi omvandla strängarna till listor när vi läser in kartan.

```python
r,c,n = list(map(int,input().split()))
kommandon = input()

karta = []
pos_c = -1
pos_r = -1

for i in range(r):
    rad = list(input())
    for j in range(c):
        if rad[j]=='O':
            pos_r = i
            pos_c = j

            #Städa startrutan
            rad[j] = ' '

    karta.append(rad)

for k in kommandon:
    riktning_c = 0
    riktning_r = 0
    if k=='v':
        riktning_r = 1
    if k=='^':
        riktning_r = -1
    if k=='>':
        riktning_c = 1
    if k=='<':
        riktning_c = -1

    while True:
        next_c = pos_c + riktning_c
        next_r = pos_r + riktning_r

        if karta[next_r][next_c] == '#':
            break

        pos_c = next_c
        pos_r = next_r
        
        #Städa rutan
        karta[pos_r][pos_c] = ' '

#Räkna städade rutor
ans = 0
for i in range(r):
    for j in range(c):
        if karta[i][j]==' ':
            ans+=1
print(ans)
```