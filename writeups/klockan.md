# Klockan

## n <= 23
För testfallet där n <= 23 kan tjuven inte ha varit inne i huset i mer än en sekund (även om klockan skulle vara 11:11:11 två gånger i rad krävs minst 24 energienheter för att klockan ska vara igång i två sekunder). Vi kan gå igenom varje sekund under dygnet och räkna hur många av dem som drar exakt n energienheter.

## n <= 200
För testfallet med n <= 200 kan vi gå igenom varje sekund under dygnet och testa om klockan kan ha startat på den sekunden. Som exempel kan vi säga att n=166 och vi vill kolla om klockan kan ha startat 20:00:00. Vi börjar med att räkna ut att klockan drar 35 energienheter klockan 20:00:00. Det är för lite, så vi adderar på nästa sekund, 20:00:01, och får totalt 66 energienheter. Det är fortfarande för lite, så vi fortsätter med att addera på fler sekunder. När vi kommit fram till 20:00:04 är summan uppe i 167, vilket är mer än 166, så vi kan dra slutsatsen att klockan inte kan ha startat 20:00:00.

Sedan testar vi om 20:00:01 är en giltig starttid. Vi adderar på fler sekunder på samma sätt som innan tills vi kommit fram till 20:00:05. Då är summan precis 166 och vi kan dra slutsatsen att tjuven kan ha brutit sig in 20:00:01. Vi testar på samma sätt alla starttider mellan 00:00:00 och 23:59:59 och räknar hur många som funkar.

## Alla testfall
För att lösa alla testfall behöver vi göra lösningen snabbare. Det kan vi göra genom att inse att när vi går vidare till att kolla om 20:00:01 funkar som starttid kan vi behålla summan som vi räknade ut mellan 20:00:00 och 20:00:04, men subtrahera bort energin som 20:00:00 drar, för att direkt få summan mellan 20:00:01 och 20:00:04. Vi ser då att summan är för liten och adderar på 20:00:05. Då blir summan precis 166 och vi noterar att 20:00:01 är en giltig starttid. Sedan kan vi gå vidare till att testa om 20:00:02 är en giltig starttid genom att subtrahera bort 20:00:01 och fortsätta likadant.

Den här lösningen använder två pekare (two-pointer technique) eftersom man kan säga att vi har två pekare som pekar ut starten och slutet av tidsintervallet som vi har summan för. Om intervallet drar för mycket energi stegar vi fram startpekaren en sekund (och minskar summan), och om det drar för lite energi stegar vi fram slutpekaren (och ökar summan).


```python
# digit innehåller hur mycket energi varje siffra drar per sekund. Exempelvis är digit[7]=3 eftersom en sjua består av tre tända segment.
digit = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]

# beräknar hur mycket energi som används för att visa ett visst klockslag, t sekunder efter 00:00:00.
def energy(t):

    # timtalet, minuttalet och sekundtalet som visas på klockans display.
    seconds = t%60
    minutes = t//60%60
    hours = t//3600

    # för varje tal visas tiotalet som en siffra och entalet som en siffra.
    return(digit[hours // 10] + digit[hours % 10] +
           digit[minutes//10] + digit[minutes%10] +
           digit[seconds//10] + digit[seconds%10])



n = int(input())

ans = 0 #antalet möjliga starttider som hittats

i = 0 # intervallets starttid (mätt i sekunder efter 00:00:00)
j = 0 # intervallets sluttid (också mätt i sekunder efter 00:00:00)
s = energy(0) # summan av hur mycket energi som går åt under tidsintervallet mellan i och j.

while(j < 24*60*60):
    if(s == n): 
        ans+=1

    # om summan är för liten stegar vi fram intervallets slut
    if(s < n):
        j += 1
        s += energy(j)
    # annars stegar vi fram intervallets start
    else:
        s -= energy(i)
        i += 1

print(ans)
```
