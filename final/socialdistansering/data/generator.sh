#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution eae.cpp opt

compile gen_random.py

MAXN=1000000000
MAXK=1000000000000
MAXM=100000

samplegroup
limits maxn=$MAXN maxm=$MAXM maxk=$MAXK
sample 1
sample 2
sample 3

group group1 11
limits maxn=1000000 maxm=0 maxk=$MAXK
tc 3
tc m0-rand1 gen_random n=2 m=0 k=12
tc m0-rand2 gen_random n=7 m=0 k=14
tc m0-rand3 gen_random n=15 m=0 k=15
tc m0-rand4 gen_random n=19 m=0 k=94
tc m0-rand5 gen_random n=19 m=0 k=95
tc m0-rand6 gen_random n=19 m=0 k=96
tc m0-rand7 gen_random n=10 m=0 k=$MAXK
tc m0-rand8 gen_random n=1000000 m=0 k=$MAXK
tc m0-rand9 gen_random n=2 m=0 k=$MAXK

group group2 10
limits maxn=$MAXN maxm=$MAXM maxk=$MAXK maxnkm=1000000
tc m0-rand1
tc m0-rand2
tc m0-rand3
tc m0-rand4
tc m0-rand5
tc m0-rand6
tc 1
tc 2
tc nkm-rand1 gen_random n=20 m=80 k=500
tc nkm-rand2 gen_random n=20 m=80 k=500
tc nkm-rand3 gen_random n=80 m=20 k=500
tc nkm-rand4 gen_random n=80 m=20 k=500
tc nkm-rand5 gen_random n=100 m=10 k=200
tc nkm-rand6 gen_random n=100 m=10 k=200
tc nkm-rand7 gen_random n=150 m=10 k=200
tc nkm-rand8 gen_random n=150 m=10 k=200
tc nkm-rand9 gen_random n=5 m=200 k=1000
tc nkm-rand10 gen_random n=5 m=200 k=1000
tc nkm-rand11 gen_random n=3 m=300 k=1000
tc nkm-rand12 gen_random n=3 m=300 k=1000
tc nkm-rand13 gen_random n=3 m=10 k=30000
tc nkm-rand14 gen_random n=5 m=10 k=20000
tc nkm-rand15 gen_random n=5 m=10 k=20000 blockedStart=1
tc nkm-rand16 gen_random n=5 m=20 k=10000 blockedEnd=1
tc nkm-rand17 gen_random n=6 m=10 k=15000 blockedStart=1 blockedEnd=1
tc nkm-rand18 gen_random n=7 m=10 k=14000 blockedStart=1 blockedEnd=1
tc_manual ../manual_tests/manual-1.in
tc_manual ../manual_tests/manual-2.in

group group3 15
limits maxn=1000 maxm=1000 maxk=2000
tc m0-rand1
tc m0-rand2
tc m0-rand3
tc m0-rand4
tc m0-rand5
tc m0-rand6
tc 1
tc 2
tc nkm-rand1
tc nkm-rand2
tc nkm-rand3
tc nkm-rand4
tc nkm-rand5
tc nkm-rand6
tc nkm-rand7
tc nkm-rand8
tc nkm-rand9
tc nkm-rand10
tc nkm-rand11
tc nkm-rand12
tc nk-rand1 gen_random n=400 m=300 k=1000
tc nk-rand2 gen_random n=400 m=300 k=1000
tc nk-rand3 gen_random n=800 m=23 k=2000
tc nk-rand4 gen_random n=15 m=500 k=1900
tc nk-rand5 gen_random n=15 m=500 k=1900
tc nk-rand6 gen_random n=20 m=500 k=2000
tc nk-rand7 gen_random n=20 m=500 k=2000
tc nk-rand8 gen_random n=50 m=800 k=2000
tc nk-rand9 gen_random n=50 m=800 k=2000
tc nk-rand10 gen_random n=100 m=800 k=2000

group group4 19
limits maxn=1000000 maxm=$MAXM maxk=$MAXK maxnm=10000000
include_group group1
include_group group2
tc nm-rand1 gen_random n=5000 m=2000 k=$MAXK
tc nm-rand2 gen_random n=5000 m=2000 k=$MAXK
tc nm-rand3 gen_random n=5000 m=2000 k=$MAXK
tc nm-rand4 gen_random n=2000 m=5000 k=$MAXK
tc nm-rand5 gen_random n=2000 m=5000 k=$MAXK
tc nm-rand6 gen_random n=2000 m=5000 k=$MAXK
tc nm-rand7 gen_random n=1000000 m=10 k=$MAXK
tc nm-rand8 gen_random n=1000000 m=10 k=$MAXK
tc nm-rand9 gen_random n=1000000 m=10 k=$MAXK
tc nm-rand10 gen_random n=2 m=$MAXM k=$MAXK
tc nm-rand11 gen_random n=2 m=$MAXM k=$MAXK
tc nm-rand12 gen_random n=10 m=$MAXM k=$MAXK
tc nm-rand13 gen_random n=10 m=$MAXM k=$MAXK
tc nm-rand14 gen_random n=100 m=$MAXM k=$MAXK
tc nm-rand15 gen_random n=100 m=$MAXM k=$MAXK

group group5 21
limits maxn=1000000 maxm=$MAXM maxk=$MAXK
include_group group4
include_group group3
tc n-rand1 gen_random n=999999 m=50000 k=10000000
tc n-rand2 gen_random n=1000000 m=80012 k=100000000
tc n-rand3 gen_random n=999999 m=100000 k=100000011
tc n-rand4 gen_random n=999999 m=100000 k=$MAXK
tc n-rand5 gen_random n=999999 m=100000 k=$MAXK
tc n-rand6 gen_random n=1000000 m=100000 k=$MAXK
tc n-rand7 gen_random n=1000000 m=100000 k=$MAXK
tc n-rand8 gen_random n=1000000 m=100000 k=$MAXK

group group6 24
limits maxn=$MAXN maxm=$MAXM maxk=$MAXK
include_group group5
tc full-rand1  gen_random n=10000001 m=100000 k=$MAXK
tc full-rand2  gen_random n=10000001 m=100000 k=$MAXK
tc full-rand3  gen_random n=10000999 m=100000 k=$MAXK
tc full-rand4  gen_random n=10000999 m=100000 k=$MAXK
tc full-rand5  gen_random n=10000000 m=100000 k=$MAXK
tc full-rand6  gen_random n=30000000 m=100000 k=$MAXK
tc full-rand7  gen_random n=7000000 m=50000 k=$MAXK
tc full-rand8  gen_random n=5000000 m=50000 k=$MAXK
tc full-rand9  gen_random n=50000000 m=50000 k=$MAXK
tc full-rand10 gen_random n=50000000 m=100000 k=$MAXK
tc full-rand11 gen_random n=300000000 m=100000 k=$MAXK
tc full-rand12 gen_random n=500000000 m=100000 k=$MAXK
tc full-rand13 gen_random n=800000000 m=5 k=$MAXK
tc full-rand14 gen_random n=1000000000 m=0 k=$MAXK
tc full-rand15 gen_random n=1000000000 m=3 k=$MAXK
tc full-rand16 gen_random n=1000000000 m=100000 k=$MAXK
tc full-rand17 gen_random n=1000000000 m=100000 k=$MAXK
tc full-rand18 gen_random n=1000000000 m=100000 k=$MAXK
tc full-rand19 gen_random n=1000000000 m=100000 k=$MAXK
