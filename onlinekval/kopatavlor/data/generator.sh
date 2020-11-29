#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution fredrik_dp.cpp

compile gen_random.py
compile gen_far.py

samplegroup
limits max_n=-1 k=-1
sample 1
sample 2
sample 3

group group1 7
limits max_n=-1 k=1
tc g1-rand-1 gen_random n=1 k=1 max_t=1000
tc g1-rand-2 gen_random n=3 k=1 max_t=1000
tc g1-rand-3 gen_random n=30 k=1 max_t=1000
tc g1-rand-4 gen_random n=300 k=1 max_t=1000
tc g1-rand-5 gen_random n=2000 k=1 max_t=1000
tc g1-rand-6 gen_random n=2000 k=1 max_t=1000

group group2 10
limits max_n=-1 k=2

tc 1
tc g2-rand-1 gen_random n=2 k=2 max_t=10
tc g2-rand-2 gen_random n=3 k=2 max_t=10
tc g2-rand-3 gen_random n=30 k=2 max_t=10
tc g2-rand-4 gen_random n=300 k=2 max_t=10
tc g2-rand-5 gen_random n=2000 k=2 max_t=10
tc g2-rand-6 gen_random n=2000 k=2 max_t=100
tc g2-rand-7 gen_random n=2000 k=2 max_t=1000
tc g2-rand-8 gen_random n=2000 k=2 max_t=1000
tc g2-far-1 gen_far n=5 k=2
tc g2-far-2 gen_far n=10 k=2
tc g2-far-3 gen_far n=100 k=2
tc g2-far-4 gen_far n=1000 k=2
tc g2-far-5 gen_far n=2000 k=2


group group3 30
limits max_n=200 k=-1

tc 2
tc 3
tc g3-rand-1 gen_random n=1 k=1 max_t=10
tc g3-rand-2 gen_random n=3 k=2 max_t=10
tc g3-rand-3 gen_random n=30 k=10 max_t=10
tc g3-rand-4 gen_random n=30 k=20 max_t=10
tc g3-rand-5 gen_random n=200 k=10 max_t=10
tc g3-rand-6 gen_random n=200 k=50 max_t=10
tc g3-rand-7 gen_random n=200 k=120 max_t=10
tc g3-rand-8 gen_random n=200 k=30 max_t=100
tc g3-rand-9 gen_random n=200 k=70 max_t=100
tc g3-rand-10 gen_random n=200 k=5 max_t=1000
tc g3-rand-11 gen_random n=200 k=42 max_t=1000
tc g3-rand-12 gen_random n=200 k=200 max_t=1000
tc g3-far-1 gen_far n=5 k=3
tc g3-far-2 gen_far n=5 k=3
tc g3-far-3 gen_far n=10 k=5
tc g3-far-4 gen_far n=10 k=8
tc g3-far-5 gen_far n=100 k=2
tc g3-far-6 gen_far n=100 k=3
tc g3-far-7 gen_far n=200 k=8
tc g3-far-8 gen_far n=200 k=30

group group4 53
limits max_n=-1 k=-1

include_group group1
include_group group2
include_group group3

tc g4-rand-1 gen_random n=2000 k=10 max_t=10
tc g4-rand-2 gen_random n=2000 k=100 max_t=10
tc g4-rand-3 gen_random n=2000 k=500 max_t=10
tc g4-rand-4 gen_random n=2000 k=1200 max_t=10
tc g4-rand-5 gen_random n=2000 k=20 max_t=100
tc g4-rand-6 gen_random n=2000 k=300 max_t=100
tc g4-rand-7 gen_random n=2000 k=700 max_t=100
tc g4-rand-8 gen_random n=2000 k=5 max_t=1000
tc g4-rand-9 gen_random n=2000 k=50 max_t=1000
tc g4-rand-10 gen_random n=2000 k=420 max_t=1000
tc g4-far-1 gen_far n=2000 k=3
tc g4-far-2 gen_far n=2000 k=10
tc g4-far-3 gen_far n=2000 k=100
tc g4-far-4 gen_far n=2000 k=1000
tc g4-far-5 gen_far n=2000 k=2000
