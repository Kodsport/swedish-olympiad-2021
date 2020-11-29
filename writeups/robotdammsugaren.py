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
