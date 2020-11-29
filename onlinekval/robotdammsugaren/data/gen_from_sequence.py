#!/usr/bin/env python3
# Generate a random sequence, and then place blocks to get
# min_length squares travelled per command if possible

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
min_length = float(cmdlinearg('min_length'))

grid = [ ['.' for _ in range(c)] for _ in range(r) ]

grid[0] = ["#"]*c
grid[-1] = ["#"]*c
for i in range(r):
    grid[i][0] = "#"
    grid[i][-1] = "#"

ri = random.randint(1,r-2)
ci = random.randint(1,c-2)

grid[ri][ci] = "O"

sequence = [[(0,1),(0,-1),(1,0),(-1,0)][random.randint(0,3)] for i in range(n)]
sequence_str = ""

for dr,dc in sequence:
    max_length = 0
    while grid[(max_length+1)*dr+ri][(max_length+1)*dc+ci] != '#':
        max_length += 1
    
    command_length = -1
    if max_length>min_length:
        while True:
            command_length = random.randint(min_length,max_length)
            if grid[(command_length+1)*dr+ri][(command_length+1)*dc+ci] != 'O':
                break
    else:
        command_length = max(0,max_length-random.randint(1,3))
    if grid[(command_length+1)*dr+ri][(command_length+1)*dc+ci] != 'O':
        grid[(command_length+1)*dr+ri][(command_length+1)*dc+ci] = '#'

    ri += command_length*dr
    ci += command_length*dc

    sequence_str += {
        "(0, 1)": ">",
        "(0, -1)": "<",
        "(1, 0)": "v",
        "(-1, 0)": "^",
    }[str((dr,dc))]

print(r, c, n)
print(sequence_str)
for row in grid:
    print(''.join(row))
