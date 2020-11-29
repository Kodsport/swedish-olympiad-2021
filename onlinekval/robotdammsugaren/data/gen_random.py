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
r = int(cmdlinearg('r'))
c = int(cmdlinearg('c'))
n = int(cmdlinearg('n'))
box_ratio = float(cmdlinearg('box_ratio'))
available_commands = cmdlinearg('available_commands','<>v^')

grid = [
    [('#' if random.uniform(0,1) < box_ratio else '.') for _ in range(c)]
    for _ in range(r)
]

grid[0] = ["#"]*c
grid[-1] = ["#"]*c
for i in range(r):
    grid[i][0] = "#"
    grid[i][-1] = "#"

grid[random.randint(1,r-2)][random.randint(1,c-2)] = "O"

print(r, c, n)

sequence = [available_commands[random.randint(0,len(available_commands)-1)] for i in range(n)]
print("".join(sequence))

for row in grid:
    print(''.join(row))
