#!/usr/bin/python3
from util import *

n = int(cmdlinearg("n"))
chi = int(cmdlinearg("chi", n))
ahi = int(cmdlinearg("ahi", 10**9))
bmode = cmdlinearg("bmode", "any")

blo = 0 if bmode == "pos" else -10**9
bhi = 0 if bmode == "neg" else 10**9

print(n)
for i in range(n):
    a = random.randint(-ahi, ahi)
    b = random.randint(blo, bhi)
    c = random.randint(1, chi)
    print(a, b, c)
