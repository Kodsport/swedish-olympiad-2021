# Äpplen och päron

Här gäller det bara att göra det som står i beskrivningen: läs in antalet äpplen och pären, multiplicera med kostnaden, jämför svaren. Lösning i python:
```python
A = int(input())
P = int(input())
price_A = A*7
price_P = P*13

if price_A > price_P:
  print("Axel")
elif price_A < price_P:
  print("Petra")
elif price_A == price_P:
  print("lika") 
```