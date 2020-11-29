# Stökiga känguruungar

Det finns många olika sätt att lösa det här problemet på (bl.a. med dynamisk programmering); det här lösningsförslaget tar upp två olika giriga (greedy) lösningar.

Vi kan börja med att fundera över hur vi löser delgrupper 2 och 4, där alla ungar garanterat är stökiga. Här behöver vi alltså bara kunna beräkna snabbt huruvida ett ord T är en unge till S eller inte. En enkel metod för att göra det är att gå igenom T tecken för tecken, och hitta nästa förekomsten av det tecknet i S. (Det är aldrig meningsfullt att hoppa över tecken i S, därav att algoritmen kan beskrivas som girig.) Om vi lyckas hitta alla tecken i S är T en unge, annars inte. Om vi hittar nästa förekomst i S genom att loopa får vi en tidskomplexitet på O(NM + K) -- för vardera av de N orden loopar vi potentiellt igenom hela S, som är M tecken lång, och vi går också igenom alla K tecken hos orden T. Detta klarar testgrupp 2.

För att snabba upp algoritmen måste vi göra steget “hitta positionen för nästa förekomst av tecknet X i S, med start på position I” snabbare. Ett sätt att göra detta på är att ha en förberäknad tabell över “nästa förekomst” av storlek 26·M, som kan beräknas baklänges:
```
vector<int> next(26, -1);
vector<vector<int>> nexts(M);
for (int i = M-1; i >= 0; i--) {
    next[S[i] - 'a'] = i;
    nexts[i] = next;
}
```
Genom att använda `nexts[i][T[j] - 'a'] + 1` för att hoppa framåt i S får vi ned tidskomplexiteten till O(AM + K) där A = 26 är alfabetsstorleken, vilket är tillräckligt för att klara testgrupp 4.

Ett annat sätt är att för varje tecken skapa en lista över positionerna där tecknet förekommer, och sen binärsöka bland dessa listor -- detta ger O(A+M+K log M) vilket också är tillräckligt snabbt.

För full poäng i problemet måste vi dock även kunna säga huruvida en unge är stökig, d.v.s. förekommer som subsekvens på minst två olika sätt. Det finns minst två olika sätt att göra detta på. Ett sätt baserar sig på observationen att den giriga algoritmen som beskrivits ovan kommer hitta den vänstraste möjliga placeringen av subsekvensen. Genom att reversera alla strängar och göra samma sak (och sen reversera tillbaka positionerna vi får ut) kan vi även hitta den högraste möjliga placeringen. Om dessa skiljer sig åt är ungen stökig.

Ett annat sätt är att utgå från subsekvenspositionerna vi hittar i den giriga algoritmen, och försöka byta ut varje position mot nästa förekomst av samma tecken. Om det finns en till förekomst, och den förekomsten är innan positionen för tecknet direkt efter, så är ungen stökig.

Se sl.cpp och sl2.cpp i [repot med domarlösningar/testdata](https://github.com/Kodsport/swedish-olympiad-2021-public/blob/main/onlinekval/kanguruord/submissions/accepted/) för implementationer av lösningsförslagen. (Det går att förbättra tidskomplexiteterna något och lösa problemet i O(A + M + K) om man gör det offline, d.v.s. för alla synonymer samtidigt, efter att man läst in hela indatan. Vi lämnar detta som övning åt läsaren!)
