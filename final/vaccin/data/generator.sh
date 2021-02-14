#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution leopold_100.py

compile gen_random.py

samplegroup
limits max_n=-1 max_k=-1
sample 1
sample 2
sample 3

group group1 50
limits max_n=100 max_k=1
include_group sample
tc g1-rand-1 gen_random n=100 k=1
tc g1-rand-2 gen_random n=100 k=1
tc g1-rand-3 gen_random n=100 k=1
tc g1-rand-4 gen_random n=100 k=1
tc g1-rand-5 gen_random n=100 k=1
tc g1-rand-7 gen_random n=100 k=1

group group2 50
limits max_n=100000 max_k=100000
tc g2-rand-1 gen_random n=100000 k=100000
tc g2-rand-2 gen_random n=100000 k=100000
tc g2-rand-3 gen_random n=100000 k=100000
tc g2-rand-4 gen_random n=100000 k=100000
tc g2-rand-5 gen_random n=100000 k=100000
tc g2-rand-7 gen_random n=100000 k=100000
