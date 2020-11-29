#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution leopold.py

compile gen_random.py

samplegroup
limits max_n=-1 max_score=-1
sample 1
sample 2
sample 3

group group1 15
limits max_n=100 max_score=30
include_group sample
tc_manual manual_1
tc_manual manual_2
tc g1-small-1 gen_random n=1 max_score=10
tc g1-small-2 gen_random n=1 max_score=10
tc g1-small-3 gen_random n=2 max_score=10
tc g1-small-4 gen_random n=2 max_score=10
tc g1-small-5 gen_random n=5 max_score=10
tc g1-small-6 gen_random n=5 max_score=10
tc g1-small-7 gen_random n=1 max_score=0
tc g1-small-8 gen_random n=2 max_score=0
tc g1-small-9 gen_random n=3 max_score=1
tc g1-rand-1 gen_random n=100 max_score=30
tc g1-rand-2 gen_random n=100 max_score=30
tc g1-rand-3 gen_random n=100 max_score=30
tc g1-rand-4 gen_random n=100 max_score=30
tc g1-rand-5 gen_random n=100 max_score=30
tc g1-rand-7 gen_random n=100 max_score=2

group group2 35
limits max_n=1000 max_score=1000
include_group group1
tc_manual manual_medium_ans
tc g2-small-1 gen_random n=10 max_score=1000
tc g2-small-2 gen_random n=10 max_score=1000
tc g2-rand-1 gen_random n=1000 max_score=1000
tc g2-rand-2 gen_random n=1000 max_score=1000
tc g2-rand-3 gen_random n=1000 max_score=1000
tc g2-rand-4 gen_random n=1000 max_score=1000
tc g2-rand-5 gen_random n=1000 max_score=1000

group group3 50
limits max_n=100000 max_score=1000000
include_group group2
tc_manual manual_large_ans
tc g3-rand-1 gen_random n=100000 max_score=1000000
tc g3-rand-2 gen_random n=100000 max_score=1000000
tc g3-rand-3 gen_random n=100000 max_score=1000000
tc g3-rand-4 gen_random n=100000 max_score=1000000
tc g3-rand-5 gen_random n=100000 max_score=1000000
