#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution sl2.cpp

compile gen_random.py
compile gen_pattern.py

samplegroup
limits n=10 sum=100 len=100 allmessy=0
sample 1
sample 2

group group1 20
limits n=100 sum=100 len=100 allmessy=0
include_group sample
tc g1-small-1 gen_random len=15 sum=100 n=20 a=3 mode=uniform
tc g1-small-2 gen_random len=15 sum=100 n=20 a=3 mode=uniform
tc g1-small-3 gen_random len=15 sum=100 n=20 a=3 mode=uniform
tc g1-small-4 gen_random len=15 sum=100 n=20 a=4 mode=uniform
tc g1-small-5 gen_random len=15 sum=100 n=20 a=4 mode=uniform
tc g1-rand-1 gen_random len=100 sum=100 n=10 a=26 mode=uniform
tc g1-rand-2 gen_random len=100 sum=100 n=10 a=26 mode=valid,invalid
tc g1-manysmall gen_random len=100 sum=100 n=100 a=26 mode=uniform
tc g1-aaa gen_random len=50 sum=100 n=1 a=1 mode=uniform

group group2 20
limits n=1000 sum=500000 len=1000 allmessy=1
tc 1
tc g2-rand-1 gen_random len=1000 sum=500000 n=1000 a=26 mode=uniform messy=1
tc g2-rand-2 gen_random len=1000 sum=500000 n=1000 a=26 mode=valid,invalid messy=1
tc g2-rand-3 gen_random len=1000 sum=100000 n=1000 a=26 mode=valid,invalid messy=1
tc g2-manysmall gen_random len=1000 sum=5000 n=1000 a=26 mode=uniform messy=1
tc g2-manysmall2 gen_random len=1000 sum=50000 n=1000 a=26 mode=uniform messy=1

group group3 20
limits n=1000 sum=500000 len=1000 allmessy=0
include_group group1
include_group group2
tc g3-small-1 gen_random len=20 sum=10000 n=2000 a=3 mode=uniform seed=123
tc g3-small-2 gen_random len=25 sum=10000 n=1700 a=4 mode=uniform seed=124
tc g3-rand-1 gen_random len=1000 sum=500000 n=1000 a=26 mode=uniform
tc g3-rand-2 gen_random len=1000 sum=500000 n=1000 a=26 mode=valid,invalid
tc g3-rand-3 gen_random len=1000 sum=100000 n=1000 a=26 mode=valid,invalid
tc g3-manysmall gen_random len=1000 sum=5000 n=1000 a=26 mode=uniform
tc g3-manysmall2 gen_random len=1000 sum=50000 n=1000 a=26 mode=uniform
tc g3-pattern gen_pattern len=1000 n=500 a=26 mode=repeating

group group4 20
limits n=100000 sum=500000 len=100000 allmessy=1
include_group group2
tc g4-rand-pad1 gen_random len=100000 sum=500000 n=100000 a=22 mode=valid,invalid pad=random,100 messy=1
tc g4-long gen_random len=100000 sum=500000 n=10 a=26 mode=uniform messy=1
tc g4-rand-1 gen_random len=100000 sum=500000 n=800 a=26 mode=uniform messy=1
tc g4-rand-2 gen_random len=100000 sum=500000 n=800 a=26 mode=valid,invalid messy=1
tc g4-aaa gen_random len=100000 sum=500000 n=10 a=1 mode=uniform messy=1
tc g4-aaa2 gen_random len=100000 sum=500000 n=1 a=1 mode=uniform messy=1
tc g4-ab gen_random len=100000 sum=500000 n=10 a=2 mode=uniform messy=1
tc g4-manysmall gen_random len=100000 sum=500000 n=100000 a=26 mode=uniform messy=1
tc g4-rand-pad2 gen_random len=100000 sum=500000 n=100000 a=26 mode=valid,invalid pad=stretch,100 messy=1

group group5 20
limits n=100000 sum=500000 len=100000 allmessy=0
include_group group3
include_group group4
tc g5-small gen_random len=20 sum=400000 n=100000 a=3 mode=uniform
tc g5-rand-pad1 gen_random len=100000 sum=500000 n=100000 a=20 mode=uniform pad=random,60
tc g5-rand-pad2 gen_random len=100000 sum=500000 n=100000 a=22 mode=valid,invalid pad=random,60
tc g5-pattern gen_pattern len=100000 n=50 a=26 mode=repeating
tc g5-long gen_random len=100000 sum=500000 n=10 a=26 mode=uniform
tc g5-rand-1 gen_random len=100000 sum=500000 n=800 a=26 mode=uniform
tc g5-rand-2 gen_random len=100000 sum=500000 n=800 a=26 mode=valid,invalid
tc g5-manysmall gen_random len=100000 sum=500000 n=100000 a=26 mode=uniform
tc g5-rand-pad3 gen_random len=100000 sum=500000 n=100000 a=26 mode=valid,invalid pad=stretch,100
