def paddlar_kvar(P,K,M):
    M -= (K-1)*P
    if M<=0:
        return P
    if M<=P:
        return P-M
    return -1

N = int(input())
K = int(input())
H = int(input())

D = []
for i in range(N-1):
    D.append(H*int(input()))


#Vi vet att det inte går med 0 paddlar
l=0
#Detta tal är tillräckligt stort så att det alltid kommer gå
r=10**18

while r-l!=1:
    #Gissa mitt mellan r och l
    start_paddlar = (r+l)//2

    P = start_paddlar
    #Simulera
    for i in range(N-1):
        P = paddlar_kvar(P, K, D[i])
        if P<0:
            break

    #Ifall vi har negativt antal paddlar så
    #har vi inte kommit hela vägen fram

    if P<0:
        l = start_paddlar
    else:
        r = start_paddlar

print(r)