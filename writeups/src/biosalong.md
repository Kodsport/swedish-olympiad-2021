# Biosalong

## 60 poäng
En lösning man skulle kunna tänka sig är att loopa igenom alla möjligheter för Axels plats, loopa igenom alla möjligheter för Beatrices plats, och ta det kortaste avstånder man hittar. Det skulle se ut ungefär såhär i python:

```python
n = int(input())
s = input()

shortest = 100000000000
for i in range(n):
    for j in range(n):
        # Axel och Beatrice kan
        # inte sitta på samma plats
        if i==j:
            continue
        
        # Ifall båda platserna är lediga
        if s[i]=='.' and s[j]=='.':
            # Uppdatera hittils kortaste
            shortest = min(shortest, abs(i-j)-1)
print(shortest)
```

Skickar man in detta ser man dock att det bara ger 60 poäng, och att man får "Time Limit Exceeded" på den stora testfallsgruppen. Om vi funderar på hur många gånger koden inuti den inre for-loopen körs så förstår vi varför. För varje gång den yttre forloopen körs så körs den inre koden $N$ gånger, och eftersom den yttre forloopen körs $N$ gånger så kommer den inre koden köras $N\cdot N$ gånger. (man kan då säga att programmet har tidskomplexitet $O(N^2)$). Om $N=1000000$ kommer den inre koden köras $10^{12}$ gånger, vilket är mycket mer än vad vi hinner på en sekund. I python hinner man ca $10^7$ operationer på en sekund.


## 100 poäng
Så för 100 poäng måste vi få bort en av looparna. Det kan vi göra genom att inse att om vi går igenom alla platser vänster till höger så räcker det att kolla avståndet till den senaste lediga platsen man har sätt, eftersom den kommer alltid vara den närsmta åt vänster.

```python
n = int(input())
s = input()

shortest = 100000000000
last_free_pos = -100000000000
for i in range(n):
    if s[i]=='.':
        shortest = min(shortest, i-last_free_pos-1)
        last_free_pos = i
print(shortest)
```