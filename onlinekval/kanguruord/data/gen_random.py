#!/usr/bin/env python3
# Random strings over a given alphabet, with a mode for producing search
# strings that are either valid or near to being valid, and modes for padding
# the base string so that it becomes longer but preserves answers.

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
su = int(cmdlinearg('sum'))
messy = int(cmdlinearg('messy', 0))
alphabet = int(cmdlinearg('a'))
modes = cmdlinearg('mode').split(",")
pad = cmdlinearg('pad', '')
if pad:
    pad, realm = pad.split(",")
    realm = int(realm)
    assert pad in ["stretch", "random"]
    if pad == "random":
        assert alphabet < 26

for x in modes:
    assert x in ["uniform", "valid", "invalid"]

assert 1 <= alphabet <= 26

# Partition 'su' into n blocks, each of length >= 1
things = [True] * (n - 1) + [False] * (su - n)
random.shuffle(things)
things.append(True)
indices = [i for i, x in enumerate(things) if x]
lens = [y - x for x, y in zip([-1] + indices, indices)]
assert sum(lens) == su

def random_word(le):
    assert le >= 0
    return ''.join(chr(97 + random.randrange(alphabet)) for _ in range(le))

if pad:
    basehay = random_word(realm)
    hay = [None] * m
    if pad == "random":
        indices = sorted(random.sample(range(m), realm))
        for i, ind in enumerate(indices):
            hay[ind] = basehay[i]
        for i in range(m):
            if hay[i] is None:
                hay[i] = chr(97 + random.randrange(alphabet, 26))
    else:
        indices = [0] + sorted(random.sample(range(1, m), realm - 1))
        for i, ind in enumerate(indices):
            hay[ind] = basehay[i]
        for i in range(m):
            if hay[i] is None:
                hay[i] = hay[i - 1]
    hay = "".join(hay)
else:
    hay = random_word(m)

if "valid" in modes or "invalid" in modes or messy:
    jump = [None] * (m + 1)
    jump[-1] = [-1] * 26
    for i in range(m - 1, -1, -1):
        jump[i] = jump[i+1][:]
        o = ord(hay[i]) - 97
        assert o >= 0
        jump[i][o] = i

    def is_unique(s):
        assert s, "empty strings not allowed"
        at = 0
        prevo = -1
        for c in s:
            o = ord(c) - 97
            assert o >= 0
            at2 = jump[at][o]
            if at2 == -1:
                return False
            if prevo != -1 and jump[at][prevo] != -1 and jump[at][prevo] < at2:
                return False
            at = at2 + 1
            prevo = o
        if jump[at][prevo] != -1:
            return False
        return True

    def random_smart(le, valid):
        at = 0
        indices = []
        last = None
        for j in range(le):
            c = random.randrange(alphabet)
            at = jump[at][c]
            if at == -1:
                if not valid:
                    last = c
                break
            indices.append(at)
            at += 1
        indices_set = set(indices)
        target_indices = min(m * 9 // 10, le - (1 if last is not None else 0))
        while len(indices) < target_indices:
            x = random.randrange(m)
            if x not in indices_set:
                indices_set.add(x)
                indices.append(x)
        indices.sort()
        values = [hay[i] for i in indices]
        if last is not None:
            values.append(chr(97 + last))
        return ''.join(values) + random_word(le - len(values))

output = []
word_set = {hay}

for i in range(n):
    smode = random.choice(modes)
    le = lens[i]
    if smode == 'uniform':
        s = random_word(le)
    else:
        s = random_smart(le, smode == 'valid')
    if s not in word_set:
        word_set.add(s)
        if not messy or not is_unique(s):
            output.append(s)

print(hay)
print(len(output))
for s in output:
    print(s)
