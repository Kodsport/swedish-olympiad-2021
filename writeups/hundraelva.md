# Hundraelva

Problemet frågar efter det minsta antalet sedlar på formen 1, 11, 111, etc som måste användas för att betala exakt N kronor.


Idén för lösningen är att en girig strategi fungerar: *det är alltid optimalt att välja minst en sedel med största valören <= N*. (För en bevis-sketch, se nedan).

Med denna insikt är lösningen relativt enkel. Man hittar den största sedeln som är maximalt N, och så kan man dra av värdet på denna sedel från N och fortsätta på liknande sätt.

```python
n = int(input())

ans = 0
while n > 0:
    sedel = 1
    while 10*sedel+1<=n:
        sedel = 10*sedel+1
    # sedel är nu största talet <= n på formen 11...1
    n -= sedel
    ans += 1

print(ans)
```

Varför är detta snabbt nog? I svaret behövs maximalt 10 st av varje sorts sedel (om N är strikt större än 10 gånger en sedels värde använder man först en större sedel istället), och det finns bara 8 stycken sedlar som är relevanta då det är garanterade att N <= 10^9.


---

### Bevisidé för att giriga strategin fungerar.

Låt $a_1 = 1$, $a_2 = 11$, $a_3 = 111$, $a_4 = 1111$ osv.
Det gäller att $10a_i + a_j = a_{i+1} + 10 a_{j-1}$ för alla $i >= j >= 2$
och $10a_i + a_1 = a_{i+1}$ för alla $i >= 1$.
Detta betyder att om man har sedlar som summerar till minst $a_{i+1}$,
så är det aldrig sämre att byta sedlarna till att använda minst en till sedel av
valören $a_{i+1}$.

