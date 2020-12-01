# Robotdammsugaren 2

Här är några olika strategier och ungefär hur mycket poäng de får:

## Slumplösning: (20-30 poäng)
Antagligen det enklaste sättet att få hyfsat mycket poäng är att skriva ut en slumpmässig sträng av längd N (man behöver inte ens läsa in rutnätet). Utan några optimeringar ger det här ungefär 20 poäng. En optimering är att aldrig skriva ut samma tecken två gånger i rad, då får man ca 25 poäng. Sedan visar det sig vara en bra idé att växla mellan upp/ner och höger/vänster, och då får man ytterligare lite poäng. Det var ganska många som tog poäng med den här typen av lösningar.

## Girig lösning: (~50 poäng)
I den här lösningen kollar vi åt alla fyra håll och går åt det håll där det finns flest obesökta rutor. Man kan få en hel del poäng med en sån här lösning, men det finns en del fällor. En sak som kan hända är att det finns 0 rutor åt alla håll. Då måste lösningen tie-breaka på något bra sätt så att den inte fastnar och åker in i väggen resten av tiden. Det enklaste sättet är att välja ett slumpmässigt håll om flera var lika bra. Glöm heller inte att se till så att roboten aldrig åker direkt in i en närliggande vägg.

## Trädsökning: (75-90 poäng)
Det här är en generalisering av den giriga lösningen. I varje steg kollar vi alla möjliga sekvenser av D steg, och går åt det håll där den bästa lösningen fanns. Om vi undviker att åka direkt in i väggar finns det i varje position 3 (eller färre) olika håll vi kan åka åt, så antalet sekvenser vi kollar igenom blir ca $3^D$. Domarlösningen kör en sån här trädsökning för $T \le 5$ och $T = 9$, med $D=10$ för de små fallen och $D=7-9$ för de stora. Under tävlingen var det den här typen av lösningar som lyckades bäst, och det finns många fler optimeringar man kan slänga på. Både Olle Lapidus och Victor Vatn skrev t.ex. trädsökningslösningar som är bättre än domarnas.

## BFS + DP: (100+ poäng tillsammans med trädsökningen)
På testfall 7 och 10 är nedre halvan av rutnätet en guldgruva som vi vill ta oss till så fort som möjligt och sedan åka fram och tillbaka i. Trädsökningslösningen kollar inte tillräckligt djupt för att hitta ner dit (i alla fall i testfall 10), och kommer därför få väldigt lite poäng. För att hitta kortaste vägen till nedre halvan är det en bra idé att först göra en bredden-först-sökning (BFS) för att komma dit. Men BFS visar sig vara ett bra verktyg även för att hitta bra allmänna lösningar. Vi vill ju hitta en sekvens drag som går långa sträckor på få drag, och som inte korsar sig själv så mycket. Och kortaste vägar som BFSen hittar är just såna. Om man tar alla kanter i grafen som finns i kortaste vägar så bildar de en riktad acyklisk graf, och vi kan hitta den kortaste väg med flest obesökta noder med dynamisk programmering. Så domarlösningen kör flera såna här BFSer och hittar de bästa kortaste vägarna från där vi befinner oss. Det visar sig funka bra framförallt i $T=7$ och $10$, men även i de stora glesa rutnäten som $T=8$.
