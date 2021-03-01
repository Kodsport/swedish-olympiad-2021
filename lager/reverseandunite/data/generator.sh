#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

#ulimit -s unlimited

use_solution ng.cpp

compile gen_random.py
compile gen_twosides.py

MAXN=200

samplegroup
limits max_n=$MAXN max_d=$MAXN max_x=$MAXN
sample_manual 1
sample_manual 2

group group1 9
limits max_n=2 max_d=$MAXN max_x=$MAXN
tc g1-rand-1 gen_random n=2 d=2 x=$MAXN
tc g1-rand-2 gen_random n=2 d=3 x=$MAXN
tc g1-rand-3 gen_random n=2 d=10 x=$MAXN
tc g1-rand-4 gen_random n=2 d=11 x=$MAXN
tc g1-rand-5 gen_random n=2 d=100 x=$MAXN
tc g1-rand-6 gen_random n=2 d=101 x=$MAXN
tc g1-rand-7 gen_random n=2 d=$MAXN x=$MAXN
tc g1-rand-8 gen_random n=2 d=$MAXN x=2
tc g1-two-9  gen_twosides n=2 d=$MAXN x=$MAXN

group group2 9
limits max_n=$MAXN max_d=2 max_x=$MAXN
tc g2-rand-1 gen_random n=2 d=2 x=$MAXN
tc g2-rand-2 gen_random n=6 d=2 x=$MAXN
tc g2-rand-3 gen_random n=12 d=2 x=$MAXN
tc g2-rand-4 gen_random n=25 d=2 x=$MAXN
tc g2-rand-5 gen_random n=50 d=2 x=$MAXN
tc g2-rand-6 gen_random n=100 d=2 x=$MAXN
tc g2-rand-7 gen_random n=150 d=2 x=$MAXN
tc g2-rand-8 gen_random n=$MAXN d=2 x=$MAXN
tc g2-two-9  gen_twosides n=$(($MAXN*2/3)) d=2 x=$MAXN
tc g2-two-10 gen_twosides n=$(($MAXN/2)) d=2 x=$MAXN back=$(($MAXN/2-1))

group group3 14
limits max_n=$MAXN max_d=3 max_x=$MAXN
tc g3-rand-1 gen_random n=2 d=3 x=$MAXN
tc g3-rand-2 gen_random n=6 d=3 x=$MAXN
tc g3-rand-3 gen_random n=12 d=3 x=$MAXN
tc g3-rand-4 gen_random n=25 d=3 x=$MAXN
tc g3-rand-5 gen_random n=50 d=3 x=$MAXN
tc g3-rand-6 gen_random n=100 d=3 x=$MAXN
tc g3-rand-7 gen_random n=150 d=3 x=$MAXN
tc g3-rand-8 gen_random n=$MAXN d=3 x=$MAXN
tc g3-rand-9 gen_random n=50 d=3 x=$MAXN valid=0
tc g3-two-10 gen_twosides n=$(($MAXN*2/3)) d=3 x=$MAXN
tc g3-two-11 gen_twosides n=13 d=3 x=$MAXN odd=1
tc g3-two-12 gen_twosides n=51 d=3 x=$MAXN back=24 odd=1
tc g3-two-13 gen_twosides n=99 d=3 x=$MAXN odd=1

group group4 14
limits max_n=5 max_d=5 max_x=5
tc 2
tc g4-rand-1 gen_random n=2 d=4 x=5
tc g4-rand-2 gen_random n=3 d=4 x=5
tc g4-rand-3 gen_random n=4 d=4 x=5
tc g4-rand-4 gen_random n=2 d=5 x=5 valid=0
tc g4-rand-5 gen_random n=3 d=5 x=5 valid=0
tc g4-rand-6 gen_random n=4 d=5 x=5 valid=0
tc g4-rand-7 gen_random n=2 d=2 x=5
tc g4-rand-8 gen_random n=2 d=3 x=5

group group5 24
limits max_n=30 max_d=30 max_x=30
include_group group4
tc 1
tc g5-rand-1 gen_random n=7 d=2 x=30
tc g5-rand-2 gen_random n=15 d=3 x=30
tc g5-rand-3 gen_random n=15 d=13 x=30
tc g5-rand-4 gen_random n=15 d=14 x=30
tc g5-rand-5 gen_random n=20 d=27 x=30 valid=0
tc g5-rand-6 gen_random n=20 d=27 x=30
tc g5-rand-7 gen_random n=20 d=30 x=30
tc g5-rand-8 gen_random n=29 d=30 x=30
tc g5-two-9  gen_twosides n=20 d=29 x=30
tc g5-two-10 gen_twosides n=19 d=29 x=30 odd=1
tc g5-two-11 gen_twosides n=18 d=29 x=30 back=10 odd=1

group group6 30
limits max_n=$MAXN max_d=$MAXN max_x=$MAXN
include_group group1
include_group group2
include_group group3
include_group group5
tc g6-rand-1 gen_random n=100 d=5 x=$MAXN
tc g6-rand-2 gen_random n=100 d=16 x=$MAXN
tc g6-rand-3 gen_random n=100 d=17 x=$MAXN valid=0
tc g6-rand-4 gen_random n=100 d=17 x=$MAXN
tc g6-rand-5 gen_random n=100 d=77 x=$MAXN
tc g6-rand-6 gen_random n=100 d=78 x=$MAXN
tc g6-rand-7 gen_random n=100 d=$MAXN x=$MAXN
tc g6-rand-8 gen_random n=30 d=$MAXN x=$MAXN
tc g6-rand-9 gen_random n=30 d=99 x=$MAXN
tc g6-rand-10 gen_random n=150 d=$MAXN x=$MAXN
tc g6-rand-11 gen_random n=150 d=99 x=$MAXN
tc g6-rand-12 gen_random n=198 d=199 x=$MAXN
tc g6-two-13  gen_twosides n=$(($MAXN*2/3)) d=$(($MAXN-1)) x=$MAXN
tc g6-two-14  gen_twosides n=$(($MAXN*2/3)) d=$MAXN x=$MAXN
tc g6-two-15  gen_twosides n=$(($MAXN/2)) d=13 x=$MAXN back=$(($MAXN/2-1))
tc g6-two-16  gen_twosides n=99 d=49 x=$MAXN odd=1
tc g6-two-17  gen_twosides n=13 d=7 x=$MAXN odd=1
tc g6-two-18  gen_twosides n=17 d=177 x=$MAXN back=10 odd=1
