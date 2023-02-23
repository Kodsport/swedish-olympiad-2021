#!/usr/bin/python3
from util import *

n = int(cmdlinearg("n"))
mode = cmdlinearg("mode", "max")

x = 10**9
if mode == "min":
    x = -10**9

print(n)
for i in range(n):
    a = x
    b = x
    c = n
    print(a, b, c)
