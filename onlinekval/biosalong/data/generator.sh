#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution fredrik_100.cpp

compile gen_random.py
compile gen_fixed.py

samplegroup
limits max_n=20
sample 1
sample 2
sample 3
sample 4

group group1 60
limits max_n=1000
include_group sample

tc g1-rand-1 gen_fixed ".#######."
tc g1-rand-2 gen_random n=2 free_ratio=1.0
tc g1-rand-3 gen_random n=5 free_ratio=0.7
tc g1-rand-4 gen_random n=10 free_ratio=0.4
tc g1-rand-5 gen_random n=100 free_ratio=0.1
tc g1-rand-6 gen_random n=1000 free_ratio=0.5
tc g1-rand-7 gen_random n=1000 free_ratio=0.2
tc g1-rand-8 gen_random n=1000 free_ratio=0.1
tc g1-rand-9 gen_random n=1000 free_ratio=0.05
tc g1-rand-10 gen_random n=1000 free_ratio=0.02
tc g1-rand-11 gen_random n=1000 free_ratio=0.01
tc g1-rand-12 gen_random n=1000 free_ratio=0.005
tc g1-rand-13 gen_random n=1000 free_ratio=0.001

group group2 40
limits max_n=1000000
include_group group1

tc g2-rand-1 gen_random n=1000000 free_ratio=0.5
tc g2-rand-2 gen_random n=1000000 free_ratio=0.2
tc g2-rand-3 gen_random n=1000000 free_ratio=0.1
tc g2-rand-4 gen_random n=1000000 free_ratio=0.05
tc g2-rand-5 gen_random n=1000000 free_ratio=0.02
tc g2-rand-6 gen_random n=1000000 free_ratio=0.01
tc g2-rand-7 gen_random n=1000000 free_ratio=0.005
tc g2-rand-8 gen_random n=1000000 free_ratio=0.001
tc g2-rand-9 gen_random n=1000000 free_ratio=0.0001
tc g2-rand-10 gen_random n=1000000 free_ratio=0.00001
tc g2-rand-11 gen_random n=1000000 free_ratio=0.000001

