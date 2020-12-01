# Lavapaddling

Säg att du har P stycken paddar, varje paddel kan man ta K paddeltag med och det är M meter till nästa ö. Vad är det bästa sättet att använda paddlarna på för att komma till nästa ö? Eftersom du kan laga alla paddlar som inte gått sönder helt när du kommer till nästa ö är det enda som spelar roll hur många paddlar du har kvar. Därför är det optimalt att först använda alla paddlar så mycket som möjligt utan att någon går sönder, det vill säga paddla K-1 paddeltag med varje paddel. Först därefter bör man använda det sista paddeltaget på några paddlar, om det behövs. Med denna insikt kan vi skapa en funktion som givet P, K, M kan räkna ut hur många paddlar vi har kvar när vi kommer till nästa ö:

```python
def paddlar_kvar(P,K,M):
    #Paddla (K-1) tag med varje paddel
    M -= (K-1)*P

    #Har vi redan kommit fram?
    if M<=0:
        return P

    #Kan vi komma fram genom att
    #utnyttja sista paddeltaget på
    #varje paddel?
    if M<=P:
        return P-M

    #Annars omöjligt
    return -1
```


## Lösning 1: Binärsökning

Ifall vi gissar ett visst antal paddlar att börja med, så kan vi sedan använda funktionen `paddlar_kvar` för att simulera hela resan från första ön, och se hur långt vi kommer. En första tanken kan vara att testa simulera alla olika antal paddlar, från 0 och uppåt, tills vi kommer fram hela vägen till sista ön. Problemet är att, som man kan se i Körningsexempel 3, att svaret kan bli mycket stort, och vi kommer då inte hinna inom tidsgränsen.

Så istället kan vi använda följande insikt: Om simulerar med ett visst antal paddlar att börja med och vi inte kommer fram så vet vi att vi måste börja med fler paddlar. Om vi däremot kommer fram så skulle vi kunna testa att börja med färre paddlar istället. Alltså kan vi "binärsöka" efter svaret. Att binärsöka innebär att vi håller koll på det minsta talet som vi vet är tillräckligt många paddlar (kalla det för R) och det största talet som vi vet är inte tillräckligt (kalla det för L). Sedan gissar vi att vi börjar med ett antal paddlar P som är mitt mellan L och R. Vi simulerar, och om P visar sig vara tillräckligt så uppdaterar sätter vi R=P, och om P inte var tillräckligt sätter vi L=P. På så sätt halverar vi vårt intervall av möjliga värden. Vi upprepar detta tills R-L=1. Då vet vi att det är möjligt med R paddlar, men inte möjligt med R-1=L paddlar. Alltså är R det minsta antalet paddlar som behövs, och vi kan svara med det.

```python
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
```


## Lösning 2: Räkna baklänges

Det finns också en annan lösning, som kan vara lättare att koda men kanske svårare att komma på. Ifall vi vänder på problemet, och ställer oss frågan: "Om vi vill ha kvar P' paddlar när vi kommer till ö X, vad är det minsta antalet paddlar P vi behöver ha på ö X-1?". Genom att utgå från `paddlar_kvar` ovan går det att komma fram till formeln P=max(P', $\lceil$(D[X]+P')/K$\rceil$) där $\lceil$x$\rceil$ betyder x avrundat uppåt till närmsta heltal. Om man börjar på sista ön med P'=0, så kan man gå baklänges genom alla öar, och med hjälp av formeln hela tiden räkna ut vad det minsta antalet paddlar man behöver är:

```python
P = 0
for i in range(N-2,-1,-1):
    P = max(P, math.ceil((D[i]+P)/K))
print(P)
```
