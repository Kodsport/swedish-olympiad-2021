#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution fredrik.cpp

compile gen_random.py

max_N=100000
max_L=100000
max_M=100000
max_sum_M=300000

samplegroup
limits max_N=$max_N max_L=$max_L max_M=$max_M max_sum_M=$max_sum_M
sample_manual 1
sample_manual 2


group group1 10
limits max_N=100 max_L=$max_L max_M=$max_M max_sum_M=200
include_group sample

tc g1-rand1 gen_random n=10 l=7 maxm=6 s=30
tc g1-rand2 gen_random n=100 l=50 maxm=100 s=100
tc g1-rand3 gen_random n=100 l=30 maxm=100 s=100
tc g1-rand4 gen_random n=100 l=20 maxm=100 s=100
tc g1-rand5 gen_random n=100 l=10 maxm=100 s=100
tc g1-rand6 gen_random n=100 l=5 maxm=100 s=100
tc g1-rand7 gen_random n=100 l=4 maxm=100 s=100
tc g1-rand8 gen_random n=100 l=3 maxm=100 s=100
tc g1-rand9 gen_random n=100 l=2 maxm=100 s=100
tc g1-long1 gen_random n=100 l=50 maxm=100 s=100 mode=long
tc g1-long2 gen_random n=100 l=20 maxm=100 s=100 mode=long
tc g1-long3 gen_random n=100 l=5 maxm=100 s=100 mode=long
tc g1-long4 gen_random n=100 l=3 maxm=100 s=100 mode=long
tc g1-pairs1 gen_random n=100 l=20 maxm=100 s=100 mode=pairs
tc g1-pairs2 gen_random n=100 l=5 maxm=100 s=100 mode=pairs
tc g1-pairs3 gen_random n=100 l=3 maxm=100 s=100 mode=pairs

group group2 10
limits max_N=2000 max_L=$max_L max_M=$max_M max_sum_M=4000
include_group group1

tc g2-rand1 gen_random n=2000 l=1000 maxm=1000 s=1000
tc g2-rand2 gen_random n=1800 l=300 maxm=1000 s=1000
tc g2-rand3 gen_random n=2000 l=200 maxm=1000 s=1000
tc g2-rand4 gen_random n=1500 l=100 maxm=1000 s=1000
tc g2-rand5 gen_random n=2000 l=50 maxm=1000 s=1000
tc g2-rand6 gen_random n=1000 l=30 maxm=1000 s=1000
tc g2-rand7 gen_random n=1000 l=10 maxm=1000 s=1000
tc g2-long1 gen_random n=2000 l=1000 maxm=1000 s=1000 mode=long
tc g2-long2 gen_random n=2000 l=200 maxm=1000 s=1000 mode=long
tc g2-long3 gen_random n=1500 l=100 maxm=1000 s=1000 mode=long
tc g2-long4 gen_random n=1000 l=30 maxm=1000 s=1000 mode=long
tc g2-pairs1 gen_random n=2000 l=200 maxm=1000 s=1000 mode=pairs
tc g2-pairs2 gen_random n=1500 l=100 maxm=1000 s=1000 mode=pairs
tc g2-pairs3 gen_random n=1000 l=30 maxm=1000 s=1000 mode=pairs


group group3 10
limits max_N=$max_N max_L=$max_L max_M=100 max_sum_M=30000
include_group group1

tc g3-rand1 gen_random n=12000 l=12000 maxm=100 s=30000
tc g3-rand2 gen_random n=10000 l=10000 maxm=100 s=30000
tc g3-rand3 gen_random n=7000 l=5000 maxm=100 s=30000
tc g3-rand4 gen_random n=7000 l=5000 maxm=100 s=30000
tc g3-rand5 gen_random n=7000 l=2000 maxm=100 s=30000
tc g3-rand6 gen_random n=7000 l=1000 maxm=100 s=30000
tc g3-long1 gen_random n=10000 l=10000 maxm=100 s=30000 mode=long
tc g3-long2 gen_random n=7000 l=5000 maxm=100 s=30000 mode=long
tc g3-long3 gen_random n=7000 l=2000 maxm=100 s=30000 mode=long
tc g3-long4 gen_random n=7000 l=1000 maxm=100 s=30000 mode=long
tc g3-pairs1 gen_random n=10000 l=10000 maxm=100 s=30000 mode=pairs
tc g3-pairs2 gen_random n=7000 l=5000 maxm=100 s=30000 mode=pairs
tc g3-pairs3 gen_random n=7000 l=2000 maxm=100 s=30000 mode=pairs
tc g3-pairs4 gen_random n=7000 l=1000 maxm=100 s=30000 mode=pairs


group group4 15
limits max_N=$max_N max_L=1 max_M=$max_M max_sum_M=$max_sum_M

tc g4-1 gen_random n=2 l=1 maxm=2 s=2
tc g4-2 gen_random n=10 l=1 maxm=30 s=30
tc g4-3 gen_random n=100000 l=1 maxm=$max_M s=$max_M
tc g4-4 gen_random n=100000 l=1 maxm=$max_M s=$max_M
tc g4-5 gen_random n=100000 l=1 maxm=$max_M s=$max_M
tc g4-6 gen_random n=100000 l=1 maxm=$max_M s=$max_M

group group5 55
limits max_N=$max_N max_L=$max_L max_M=$max_M max_sum_M=$max_sum_M
include_group group1
include_group group2
include_group group3
include_group group4

tc g5-rand1 gen_random n=80000 l=10000 maxm=$max_M s=$max_sum_M
tc g5-rand2 gen_random n=20000 l=3000 maxm=$max_M s=$max_sum_M
tc g5-rand3 gen_random n=80000 l=2000 maxm=$max_M s=250000
tc g5-rand4 gen_random n=20000 l=1000 maxm=$max_M s=$max_sum_M
tc g5-rand5 gen_random n=80000 l=500 maxm=$max_M s=250000
tc g5-rand6 gen_random n=20000 l=300 maxm=$max_M s=$max_sum_M
tc g5-rand7 gen_random n=80000 l=100 maxm=$max_M s=250000
tc g5-long1 gen_random n=80000 l=10000 maxm=$max_M s=$max_sum_M mode=long
tc g5-long2 gen_random n=20000 l=3000 maxm=$max_M s=$max_sum_M mode=long
tc g5-long3 gen_random n=80000 l=2000 maxm=$max_M s=250000 mode=long
tc g5-long4 gen_random n=20000 l=1000 maxm=$max_M s=$max_sum_M mode=long
tc g5-long5 gen_random n=80000 l=500 maxm=$max_M s=250000 mode=long
tc g5-long6 gen_random n=20000 l=300 maxm=$max_M s=$max_sum_M mode=long
tc g5-long7 gen_random n=80000 l=100 maxm=$max_M s=250000 mode=long
tc g5-pairs1 gen_random n=80000 l=10000 maxm=$max_M s=$max_sum_M mode=pairs
tc g5-pairs2 gen_random n=20000 l=3000 maxm=$max_M s=$max_sum_M mode=pairs
tc g5-pairs3 gen_random n=80000 l=500 maxm=$max_M s=250000 mode=pairs
tc g5-pairs4 gen_random n=20000 l=300 maxm=$max_M s=$max_sum_M mode=pairs