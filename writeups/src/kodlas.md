# Kodlås

För delpoängen där det gäller att N,M <= 5 räcker det med att prova alla N^M möjligheter, för en lösning som kör i O(N^M * NM) tid.

För nästa delpoäng (där det finns maximalt tre hål i varje skiva) kan man göra en liknande lösning, fast man kan undvika de flesta möjligheter ("pruning"). Idén är att om efter man har fixerat de första t raderna inser att inga kolumner kan vara öppna finns det ingen poäng med att prova alla resterande möjligheter för de sista N-t raderna.

För full poäng behöver man göra något lite smartare. Vi presenterar här två olika full-poängs-lösningar.


## Dynamisk programmering

Vi kan tänka oss att vi gör en rekursiv lösning där vi går igenom raderna i ordning och provar varje inställning av skivorna.
Vi kan också hålla reda på vilken delmängd C av kolumnerna som har hål i sig i all skivor vi ställt in än så länge.

Så vår funktion ser ut ungefär:

```python
# f(r, C) beräknar antalet sätt att ställa in skivorna r, r+1, ... N
# så att minst en kolumn är öppen, givet att skivorna 1,2,...,r-1 är
# inställda på ett sådant sätt att exakt kolumnerna i C är öppna.
f(r, C):
    ans = 0
    För varje inställning av skivan på rad r:
        räkna ut vad nya mängden öppna columner K är
        ans += f(r+1, K)
    return ans
```

Denna funktion går utmärkt att använda dynamisk programmering (memoization) på.
Istället för att räkna ut f(r,C) flera gånger för samma r och C så kan man spara svaren.
Totalt finns det maximalt N * 2^M olika inputs vi kommer anropa functionen med (det finns exakt 2^M delmängder av {1,2,...,M}), så vi behöver bara köra for-loopen i funktionen O(N 2^M) gånger.

Totala tidskomplexiteten blir O(N * M * 2^M).

## Alternativ lösning: Inklusion-Exklusion.

Betrakta följande (felaktiga) lösningsidé:

> För varje kolumn, beräkna hur många inställningar av skivorna som leder till att denna kolumn är öppen (kan enkelt göras med att räkna ut detta för varje skiva för sig och multiplicera talen). Sedan summerar vi svaren för de olika kolumnerna.

Det som går fel är att vi kan råka dubbelräkna inställningar av skivorna som leder till att minst två kolumner är öppna. För att fixa detta kan man tänka sig att man provar alla par av kolumner, och räknar ut hur många gånger som båda dessa kolumner är öppna (igen, detta är bara lösa för skivorna separat och multiplicera), och subtraherar det från svaret.
Tyvärr fungerar inte detta heller nu har man råkat räkna bort de inställningar där minst tre olika kolumner är öppna för många gånger.
Detta kan igen fixas med att man nu för varje tre-tupel av kolumner räknar ut svaret, men då har vi dubbelräknat fyr-tupler osv osv.

Med [Principen om Inklusion/Exklusion](https://sv.wikipedia.org/wiki/Principen_om_inklusion/exklusion) kan detta formaliserats. För en delmängd kolumner C, låt f(C) beteckna antalet inställningar av skivorna som gör att alla kolumner i C bara har hål i sig.
För ett givet C kan man beräkna f(C) i O(NM) tid (för varje skiva räkna ut antalet sätt som den kan ställas in på så att det är hål i kolumnerna C, och multiplicera dessa tal).

Inklusions/Exklusions-principen säger nu att svaret är summan av odd(C) * f(C) över alla
2^M delmängder C; där odd(C) = 1 om C har ett udda antal kolumner, och -1 annars.

Totala tidskomplexiteten blir O(N * M * 2^M).

## Implementationstips
I båda lösningarna vill man kunna behandla delmängder av kolumnerna.
En sådan delmängd C kan representeras av en bitmask (tänk en sträng av 0or och 1or) där den t:e siffran är 1 om och endast om kolumn t finns i C. Då M är ganska litet här kan man representera en bitmask med en integer i de flesta programmeringsspråk, genom att tänka sig integern i binära talsystemet. Då kan man använda bitwise-operatorer så som `&`, `<<` etc för att förenkla vissa operationer.


```python
# Dynamisk programmering i python
n, m = [int(i) for i in input().split()]

def dp(i, op):
    if i == n:
        return 1 if op > 0 else 0
    if mem[i][op] != -1:
        return mem[i][op]
    res = 0
    for j in codes[i]:
        res += dp(i+1, op&j)
    mem[i][op] = res
    return res

mem = [[-1 for _ in range(1<<m)] for _ in range(n)]
codes = []
for i in range(n):
    rotation = [0 for i in range(m)]
    cur = input()
    for i in range(m):
        for j in range(m):
            rotation[j]+=((cur[i] == '.')<<((i+j)%m))
    codes.append(rotation)

print(dp(0, (1<<m)-1))
```

```c++
// Inklusion/Exklusion i c++
int main() {
  int n, m;
  cin >> n >> m;
  std::vector<int> v(n);
  for(int i = 0; i < n; ++i) {
    std::string s;
    cin>>s;
    for(int j = 0; i < m; ++i)
      if(s[j] == '.')
        v[i] ^= (1<<j);
    v[i] = v[i] + (v[i]<<m);
  }

  long long ans = 0;
  for(int msk = 0; msk < (1<<m); ++msk)
    long long ans_for_C = 1;
    for(int i = 0; i < n; ++i) {
      long long disk = 0;
      for(int j = 0; i < m; ++i)
        if(((v[i]>>j)&msk) == msk)
          ++disk;
      ans_for_C *= cnt;
    }
    long long odd_C = (__builtin_popcount(msk)%2 ? 1 : -1)
    ans += odd_C * ans_for_C;
  }
  std::cout << ans << std::endl;
}
```
