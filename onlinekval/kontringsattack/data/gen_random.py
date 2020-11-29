#!/usr/bin/env python3
# Entirely random grid, with # occurring with probability 'box_ratio'.

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
maxscore = int(cmdlinearg('max_score'))


print(n)
print("\n".join([str(random.randint(0,maxscore))+' '+str(random.randint(0,maxscore)) for i in range(n)]))
