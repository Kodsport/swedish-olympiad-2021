#!/usr/bin/env python3
# Specific patterns, for triggering possible worst-case time complexities.

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))
m = int(cmdlinearg('len'))
alphabet = int(cmdlinearg('a'))
mode = cmdlinearg('mode')

if mode == "repeating":
    rep = "abcdefghijklmnopqrstuvwxyz"[:alphabet]
    srep = m // len(rep)
    s = rep * srep
    sinv = (rep[::-1] + "z") * (srep // len(rep) + 10)
    invbase = srep * (alphabet + 1) // alphabet
    print(s)
    print(n)
    for i in range(n):
        if i in [9, 19, 29] or invbase + 3 - i <= 0:
            print(s[: len(s) - i])
        else:
            print(sinv[: invbase + 3 - i])
