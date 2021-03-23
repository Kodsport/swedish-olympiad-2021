#!/usr/bin/python3
from util import *

n = int(cmdlinearg("n"))
clo = int(cmdlinearg("clo", 1))
chi = int(cmdlinearg("chi", n))
cdiv = int(cmdlinearg("cdiv", 1))
rand = int(cmdlinearg("rand", 0))
chirand = int(cmdlinearg("chirand", chi))

r = random.randint(-9*10**8, 9*10**8)

res = []
for i in range(rand):
    a = random.randint(-10**9, 10**9)
    b = random.randint(-10**9, 10**9)
    c = random.randint(1, chirand)
    res.append((a, b, c))

for i in range(n - rand):
    c = random.randint((clo + cdiv-1) // cdiv, chi // cdiv) * cdiv
    k = random.randint(-2*10**5, -1)
    a = r - k
    b = k * c + random.randint(-100, 100)
    res.append((a, b, c))

random.shuffle(res)

print(n)
for (a, b, c) in res:
    print(a, b, c)
