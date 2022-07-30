#!/usr/bin/env bash

PPATH=$(realpath ..)
. gen.sh

ulimit -s unlimited

use_solution joakim.cc

compile gen.cc

Q=500000

samplegroup
limits line=0 q=$Q maxn=5
sample 1

group group1 10 # small line
limits line=1 q=$Q maxn=99
tc g1-2  gen -n=3  -q=$Q -type=bamboo
tc g1-3  gen -n=5  -q=$Q -type=bamboo -labeling=none
tc g1-4  gen -n=5  -q=$Q -type=bamboo -labeling=reverse
tc g1-5  gen -n=5  -q=$Q -type=bamboo -labeling=shuffled
tc g1-6  gen -n=5  -q=$Q -type=bamboo -labeling=alternate
tc g1-7  gen -n=9  -q=$Q -type=bamboo -labeling=none
tc g1-8  gen -n=9  -q=$Q -type=bamboo -labeling=reverse
tc g1-9  gen -n=9  -q=$Q -type=bamboo -labeling=shuffled
tc g1-10 gen -n=9  -q=$Q -type=bamboo -labeling=alternate
tc g1-11 gen -n=89 -q=$Q -type=bamboo -labeling=none
tc g1-12 gen -n=89 -q=$Q -type=bamboo -labeling=reverse
tc g1-13 gen -n=89 -q=$Q -type=bamboo -labeling=shuffled
tc g1-14 gen -n=89 -q=$Q -type=bamboo -labeling=alternate
tc g1-15 gen -n=99 -q=$Q -type=bamboo -labeling=none
tc g1-16 gen -n=99 -q=$Q -type=bamboo -labeling=reverse
tc g1-17 gen -n=99 -q=$Q -type=bamboo -labeling=shuffled
tc g1-18 gen -n=99 -q=$Q -type=bamboo -labeling=alternate
tc g1-19 gen -n=97 -q=$Q -type=bamboo
tc g1-20 gen -n=95 -q=$Q -type=bamboo
tc g1-21 gen -n=31 -q=$Q -type=bamboo

group group2 12 # medium line
include_group group1
limits line=1 q=$Q maxn=999
tc g2-1  gen -n=999 -q=$Q -type=bamboo -labeling=none
tc g2-2  gen -n=999 -q=$Q -type=bamboo -labeling=reverse
tc g2-3  gen -n=999 -q=$Q -type=bamboo -labeling=shuffled
tc g2-4  gen -n=999 -q=$Q -type=bamboo -labeling=alternate
tc g2-5  gen -n=997 -q=$Q -type=bamboo
tc g2-6  gen -n=995 -q=$Q -type=bamboo
tc g2-7  gen -n=899 -q=$Q -type=bamboo
tc g2-8  gen -n=799 -q=$Q -type=bamboo
tc g2-9  gen -n=699 -q=$Q -type=bamboo
tc g2-10 gen -n=599 -q=$Q -type=bamboo

group group3 21 # large line
include_group group2
limits line=1 q=$Q maxn=24999
tc g3-1  gen -n=24999 -q=$Q -type=bamboo -labeling=none
tc g3-2  gen -n=24999 -q=$Q -type=bamboo -labeling=reverse
tc g3-3  gen -n=24999 -q=$Q -type=bamboo -labeling=shuffled
tc g3-4  gen -n=24999 -q=$Q -type=bamboo -labeling=alternate
tc g3-5  gen -n=24997 -q=$Q -type=bamboo
tc g3-6  gen -n=24995 -q=$Q -type=bamboo
tc g3-7  gen -n=18999 -q=$Q -type=bamboo
tc g3-8  gen -n=17999 -q=$Q -type=bamboo
tc g3-9  gen -n=16999 -q=$Q -type=bamboo
tc g3-10 gen -n=15999 -q=$Q -type=bamboo

group group4 14 # small tree
limits line=0 q=$Q maxn=99
include_group group1
tc 1
tc g4-1  gen -n=3  -q=$Q -type=random
tc g4-2  gen -n=5  -q=$Q -type=random
tc g4-3  gen -n=7  -q=$Q -type=random
tc g4-4  gen -n=9  -q=$Q -type=random
tc g4-5  gen -n=11 -q=$Q -type=random
tc g4-6  gen -n=99 -q=$Q -type=random
tc g4-7  gen -n=99 -q=$Q -type=prim        -elong=0
tc g4-8  gen -n=99 -q=$Q -type=prim        -elong=2
tc g4-9  gen -n=99 -q=$Q -type=prim        -elong=-2
tc g4-10 gen -n=99 -q=$Q -type=kruskal
tc g4-11 gen -n=99 -q=$Q -type=star
tc g4-12 gen -n=99 -q=$Q -type=caterpillar
tc g4-13 gen -n=99 -q=$Q -type=binary
tc g4-14 gen -n=99 -q=$Q -type=broom
tc g4-15 gen -n=99 -q=$Q -type=dumbbell


group group5 15 # medium tree
limits line=0 q=$Q maxn=999
include_group group2
include_group group4
tc g5-1  gen -n=999 -q=$Q -type=random
tc g5-2  gen -n=999 -q=$Q -type=prim        -elong=0
tc g5-3  gen -n=999 -q=$Q -type=prim        -elong=2
tc g5-4  gen -n=999 -q=$Q -type=prim        -elong=-2
tc g5-5  gen -n=999 -q=$Q -type=kruskal
tc g5-6  gen -n=999 -q=$Q -type=star
tc g5-7  gen -n=999 -q=$Q -type=caterpillar
tc g5-8  gen -n=999 -q=$Q -type=binary
tc g5-9  gen -n=999 -q=$Q -type=broom
tc g5-10 gen -n=999 -q=$Q -type=dumbbell

group group6 28 # large tree
limits line=0 q=$Q maxn=24999
include_group group3
include_group group5
tc g6-1  gen -n=24999 -q=$Q -type=random
tc g6-2  gen -n=24999 -q=$Q -type=prim        -elong=0
tc g6-3  gen -n=24999 -q=$Q -type=prim        -elong=2
tc g6-4  gen -n=24999 -q=$Q -type=prim        -elong=-2
tc g6-5  gen -n=24999 -q=$Q -type=kruskal
tc g6-6  gen -n=24999 -q=$Q -type=star
tc g6-7  gen -n=24999 -q=$Q -type=caterpillar
tc g6-8  gen -n=24999 -q=$Q -type=binary
tc g6-9  gen -n=24999 -q=$Q -type=broom
tc g6-10 gen -n=24999 -q=$Q -type=dumbbell
