#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution fredrik.cpp

compile gen_random.py

max_N=200000
max_K=200000

samplegroup
limits max_N=$max_N max_K=$max_K N_even=0
sample_manual 1
sample_manual 2
sample_manual 3


group group1 9
limits max_N=10 max_K=10 N_even=0
include_group sample

tc g1-rand1 gen_random n=1 k=10
tc g1-rand2 gen_random n=4 k=1
tc g1-rand3 gen_random n=4 k=10
tc g1-rand4 gen_random n=5 k=10
tc g1-rand5 gen_random n=9 k=2
tc g1-rand6 gen_random n=9 k=5
tc g1-rand7 gen_random n=9 k=5
tc g1-rand8 gen_random n=9 k=10
tc g1-rand9 gen_random n=10 k=2
tc g1-rand10 gen_random n=10 k=5
tc g1-rand11 gen_random n=10 k=5
tc g1-rand12 gen_random n=10 k=10
tc g1-sorted1 gen_random n=10 k=2 mode=sorted
tc g1-almost1 gen_random n=10 k=5 mode=almost ans=3

group group2 11
limits max_N=20 max_K=$max_K N_even=0
include_group group1

tc g2-odd1 gen_random n=19 k=2
tc g2-odd2 gen_random n=19 k=3
tc g2-odd3 gen_random n=19 k=10
tc g2-odd4 gen_random n=19 k=20
tc g2-odd5 gen_random n=19 k=20
tc g2-odd6 gen_random n=19 k=200000
tc g2-odd7 gen_random n=19 k=200000
tc g2-even1 gen_random n=20 k=2
tc g2-even2 gen_random n=20 k=3
tc g2-even3 gen_random n=20 k=10
tc g2-even4 gen_random n=20 k=20
tc g2-even5 gen_random n=20 k=20
tc g2-even6 gen_random n=20 k=200000
tc g2-even7 gen_random n=20 k=200000
tc g2-sorted1 gen_random n=20 k=2 mode=sorted
tc g2-almost1 gen_random n=20 k=10 mode=almost ans=4


group group3 13
limits max_N=2000 max_K=$max_K N_even=0
include_group group2

tc g3-odd1 gen_random n=1999 k=2
tc g3-odd2 gen_random n=1999 k=3
tc g3-odd3 gen_random n=1999 k=20
tc g3-odd4 gen_random n=1999 k=100
tc g3-odd5 gen_random n=1999 k=200
tc g3-odd6 gen_random n=1999 k=200000
tc g3-even1 gen_random n=2000 k=2
tc g3-even2 gen_random n=2000 k=3
tc g3-even3 gen_random n=2000 k=20
tc g3-even4 gen_random n=2000 k=100
tc g3-even5 gen_random n=2000 k=200
tc g3-even6 gen_random n=2000 k=200000
tc g3-sorted1 gen_random n=2000 k=2 mode=sorted
tc g3-sorted2 gen_random n=2000 k=1000 mode=sorted
tc g3-sorted3 gen_random n=1999 k=3 mode=sorted
tc g3-almost1 gen_random n=1999 k=100 mode=almost ans=10

group group4 17
limits max_N=$max_N max_K=2 N_even=0

tc g4-rand1 gen_random n=1 k=2
tc g4-rand2 gen_random n=5 k=2
tc g4-rand3 gen_random n=10 k=2
tc g4-rand4 gen_random n=500 k=2
tc g4-rand5 gen_random n=10001 k=2
tc g4-rand6 gen_random n=199999 k=2
tc g4-rand7 gen_random n=199999 k=2
tc g4-rand8 gen_random n=200000 k=2
tc g4-rand9 gen_random n=200000 k=2
tc g4-sorted1 gen_random n=199999 k=2 mode=sorted

group group5 20
limits max_N=$max_N max_K=$max_K N_even=1

tc g5-1 gen_random n=2 k=10
tc g5-2 gen_random n=10 k=2
tc g5-3 gen_random n=10 k=5
tc g5-4 gen_random n=10 k=10
tc g5-5 gen_random n=200 k=2
tc g5-6 gen_random n=200 k=3
tc g5-7 gen_random n=200 k=200
tc g5-8 gen_random n=200 k=200000
tc g5-9 gen_random n=2000 k=2
tc g5-10 gen_random n=2000 k=3
tc g5-11 gen_random n=2000 k=200
tc g5-12 gen_random n=2000 k=200000
tc g5-13 gen_random n=200000 k=2
tc g5-14 gen_random n=200000 k=3
tc g5-15 gen_random n=200000 k=200
tc g5-16 gen_random n=200000 k=200000
tc g5-sorted1 gen_random n=200000 k=2 mode=sorted
tc g5-almost1 gen_random n=200000 k=1000 mode=almost ans=0
tc g5-almost2 gen_random n=200000 k=1000 mode=almost ans=10

group group6 30
limits max_N=$max_N max_K=$max_K N_even=0

include_group group3
include_group group4
include_group group5

tc g6-odd1 gen_random n=199999 k=2
tc g6-odd2 gen_random n=199999 k=3
tc g6-odd3 gen_random n=199999 k=20
tc g6-odd4 gen_random n=199999 k=100
tc g6-odd5 gen_random n=199999 k=200
tc g6-odd6 gen_random n=199999 k=200000
tc g6-even1 gen_random n=200000 k=2
tc g6-even2 gen_random n=200000 k=3
tc g6-even3 gen_random n=200000 k=20
tc g6-even4 gen_random n=200000 k=100
tc g6-even5 gen_random n=200000 k=200
tc g6-even6 gen_random n=200000 k=200000
tc g6-sorted1 gen_random n=200000 k=200000 mode=sorted
tc g6-almost1 gen_random n=200000 k=1000 mode=almost ans=10
tc g6-almost2 gen_random n=199999 k=10000 mode=almost ans=1000