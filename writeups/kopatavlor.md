# Köpa tavlor

Det första man bör inse för att lösa den här uppgiften är att vi kan anta att Mona bara går vänster till höger eller höger till vänster. Om den vänstraste tavlan Mona köper är tavla $l$ och den högraste är tavla $r$ så måste Mona använda minst $r-s$ sekunder bara för att gå från $l$ till $R$ (eller $R$ till $l$). Men om hon ända ska gå så mycket kan vi lika gärna säga att hon börjar sin tavelhandel på tavla $l$, går bara åt höger, och slutar på tavla $r$. 

## Lösning 1: Memoisering/dynamisk programmering

När vi står vid en tavla har vi två val: antingen kan vi köpa tavlan och gå åt höger till nästa tavla, eller går vi ett steg åt höger utan att köpa tavlan. Om vi definerar en funktion som tar in vilken position vi är på just nu och hur många tavlor vi har kvar att köpa kan vi rekursivt räkna ut vad den kortaste tiden är genom att testa dessa två möjligheter och välja den bästa:

```python
#t[i] är hur lång tid det tar köpa i:te tavlan

def shortest_time(nuvarande_position, antal_tavlor_kvar):
    if antal_tavlor_kvar == 0:
        return 0
    if nuvarande_position == n:
        #Vi har kommit till slutet men inte köpt alla tavlor,
        #returnera stort tal för att indikera "omöjligt".
        return 1e9

    #Köp inte tavlan, gå ett steg åt höger
    tid1 =  1 + shortest_time(antal_tavlor_kvar+1, antal_tavlor_kvar)

    #Köp tavlan, gå ett steg åt höger
    tid2 =  1 + t[nuvarande_position] + shortest_time(antal_tavlor_kvar+1, antal_tavlor_kvar-1)

    return min(tid1,tid2)
```

Den här lösningen fungerar men stöter på ett problem: varje gång man anropar `shortest_time` anropas `shortest_time` på nytt två gånger. Dessa två nya anrop kommer vardera anropa två nya, o.s.v tills man kommer till ett av basfallen `antal_tavlor_kvar == 0` eller `nuvarande_position == n`. Det kommer göras exponentiellt många anrop till `shortest_time`, och man får Time Limit Exceeded för allt utom de allra minsta testfallen.

Hur löser vi detta? Jo, vi inser att `shortest_time` bara tar in två argument, och om vi anropar `shortest_time` flera gånger med samma argument så ska svaret bli det samma. Därför kan vi spara svaret efter att vi kört funktionen, och sedan om vi stöter på exakt samma argument igen så kan vi kolla upp vårt sparade svar utan att behöva köra funktionen igen. Detta kallas för memoisering, och gör att vi bara göra ett riktigt anrop till `shortest_time` för varje möjligt värde på argumenten. `nuvarande_position` kan max ha 2000 värden, och `antal_tavlor_kvar` kan max ha 2000 värden. Alltså behöver vi köra funktionen max $2000\cdot 2000 gånger, vilket vi gott och väl hinner inom time limit. Tidskomplexiteten är $O(Nk)

```python
#!/usr/bin/env python3
import sys
sys.setrecursionlimit(150000)
mem = [[-1 for _ in range(2001)] for _ in range(2001)]

n,k = [int(i) for i in input().split()]
l = [int(i) for i in input().split()]

def shortest_time(nuvarande_position, antal_tavlor_kvar):
    if antal_tavlor_kvar == 0:
        return 0
    global mem, k, l, n
    if nuvarande_position == n:
        return 1e9

    #Ifall vi redan har kört med de här argumenten
    if mem[nuvarande_position][antal_tavlor_kvar] != -1:
        return mem[nuvarande_position][antal_tavlor_kvar]

    tid1 = 1 + shortest_time(antal_tavlor_kvar+1, antal_tavlor_kvar)
    tid2 = 1 + t[nuvarande_position] + shortest_time(antal_tavlor_kvar+1, antal_tavlor_kvar-1)
    mem[nuvarande_position][antal_tavlor_kvar] = min(tid1,tid2)
    return mem[nuvarande_position][antal_tavlor_kvar]

#Testa alla ställen att starta på och ta det bästa
print(min([dp(i, k)-1 for i in range(n)]))
```

## Lösning 2: Iterera + prioritetskö
Det går också att lösa den här uppgiften utan rekursion eller dynamisk programmering. Ifall vi vet både $l$ och $r$, dvs vilken tavla Mona börjar och slutar på, så kan vi relativt enkelt räkna ut hur lång tid det tar. Insikten är att Mona alltid vill köpa de k tavlorna mellan $l$ och $r$ som går snabbast att köpa. Tiden det tar är alltså $r-l+(\textrm{summan av de k minsta talen bland }t_l,t_{l+1},...,t_r)$. Denna summa kan vi räkna ut på $O((r-l)log(r-l))$ tid genom att lägga talen i en lista, sortera listan och summera de $k$ första talen. Detta ger en $O(N^3log(N))$-lösning. 

Vi kan också vara lite smartare. Om vi fixerar $l$ och sedan itererar över alla möjligheter för $r$, så ändras den här listan av tavlor mellan $l$ och $r$ så mycket i varje steg. Närmare bestämt vill vi kunna lägga till en ny tavla, och sedan snabbt kunna hitta summan av de $k$ snabbaste tavlorna. Detta går att åstakomma med en prioritetskö, vilket är en datastruktur där man snabbt kan lägga in tal, snabbt få reda på vad det största talet är och snabbt plocka bort det största talet. När vi ökar $r$ kan vi lägga in $t_r$ i vår prioritetskö, och sedan ta bort de största talen från prioritetskön tills den innehåller exakt $k$ element. Om vi håller koll på nuvarande summan av alla element i prioritetskön genom att addera när vi lägger in saker och subtrahera när vi tar bort, så kan vi snabbt få den summan vi vill ha, summan av de $k$ snabbaste tavlorna.

Detta ger en $O(N^2log(N))$-lösning

```python
#!/usr/bin/env python3
import heapq

class Pqueue:
    def __init__(self, k):
        self.q = []
        self.tot = k-1
        self.k = k
        self.mn = 1e9
    def add(self, val):
        if len(self.q) < k:
            heapq.heappush(self.q, val*-1)
            self.tot+=val
            if len(self.q) == k: 
                self.mn = min(self.mn, self.tot)
        else:
            self.tot+=1
            top = heapq.heappop(self.q)*-1
            if self.tot + val - top <= self.tot:
                self.tot += val - top
                self.mn = min(self.mn, self.tot)
                heapq.heappush(self.q, val*-1)
            else:
                heapq.heappush(self.q, top*-1)


n, k = [int(i) for i in input().split()]
l = [int(i) for i in input().split()]
mn = 1e9
n = len(l)
for start in range(n-k+1):
    curl = Pqueue(k)
    for j in range(start, n):
        curl.add(l[j])
    mn = min(mn, curl.mn)
print(mn)
```
