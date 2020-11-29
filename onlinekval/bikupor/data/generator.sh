#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

#ulimit -s unlimited

use_solution nils.cpp

compile gen_random.py
compile gen_star.py
compile gen_doublestar.py
compile gen_path.py
compile gen_abc.py
compile gen_bipartish.py

MAXN=200000
MAXM=400000

samplegroup
limits max_n=$MAXN max_m=$MAXM max_k=$MAXN
sample 1
sample 2

group group1 12
limits max_n=$MAXN max_m=$MAXM max_k=1
tc g1-rand-1 gen_random n=10 m=10 k=1
tc g1-rand-2 gen_random n=$MAXN m=$MAXM k=1
tc g1-star-3 gen_star n=2 mid=2 k=1
tc g1-star-4 gen_star n=$MAXN mid=1 k=1
tc g1-star-5 gen_star n=$MAXN mid=$MAXN k=1
tc g1-star-6 gen_star n=$MAXN mid=73 k=1
tc g1-star-7 gen_star n=$MAXN mid=$(($MAXN-1)) k=1

group group2 15
limits max_n=15 max_m=$MAXM max_k=$MAXN
tc 1
tc 2
tc g2-rand-3 gen_random n=15 m=30 k=2
tc g2-rand-4 gen_random n=15 m=20 k=5
tc g2-rand-5 gen_random n=15 m=15 k=14
tc g2-rand-6 gen_random n=15 m=50 k=1
tc g2-star-7 gen_star n=2 mid=2 k=1
tc g2-star-8 gen_star n=15 mid=15 k=1
tc g2-star-9 gen_star n=15 mid=1 k=13
tc g2-doublestar-10 gen_doublestar n=14 mid=1 k=7
tc g2-path-11 gen_path n=15 k=8 b=4
tc g2-path-12 gen_path n=15 k=9 b=3
tc g2-bipart-13 gen_bipartish n=15 m=20 k=7 b=4 same=0
tc g2-bipart-14 gen_bipartish n=15 m=25 k=7 b=6 same=0
tc g2-star-15 gen_star n=15 mid=10 k=5

group group3 25
limits max_n=2000 max_m=4000 max_k=$MAXN
include_group group2

tc g3-rand-1 gen_random n=2000 m=4000 k=10
tc g3-rand-2 gen_random n=2000 m=4000 k=40
tc g3-rand-3 gen_random n=2000 m=4000 k=200
tc g3-rand-4 gen_random n=2000 m=4000 k=1000
tc g3-rand-5 gen_random n=2000 m=2100 k=1972
tc g3-doublestar-6 gen_doublestar n=2000 mid=1 k=1000
tc g3-doublestar-7 gen_doublestar n=2000 mid=3 k=1000
tc g3-doublestar-8 gen_doublestar n=2000 mid=1 k=1003
tc g3-path-9 gen_path n=2000 k=1800 b=40
tc g3-path-10 gen_path n=2000 k=1600 b=100
tc g3-abc-11 gen_abc n=2000 k=1998
tc g3-bipart-12 gen_bipartish n=2000 m=4000 k=1000 b=3 same=0
tc g3-bipart-13 gen_bipartish n=2000 m=4000 k=1000 b=7 same=0
tc g3-bipart-14 gen_bipartish n=2000 m=4000 k=1000 b=10 same=0
tc g3-bipart-15 gen_bipartish n=2000 m=4000 k=1000 b=200 same=1
tc g3-bipart-16 gen_bipartish n=2000 m=3000 k=1000 b=500 same=1
tc g3-star-17 gen_star n=2000 mid=1000 k=1000

group group4 13
limits max_n=$MAXN max_m=$MAXM max_k=15
include_group group2
include_group group1

tc g4-rand-1 gen_random n=$MAXN m=$MAXM k=15
tc g4-rand-2 gen_random n=$MAXN m=$MAXM k=5
tc g4-rand-3 gen_random n=$MAXN m=$MAXM k=1
tc g4-star-4 gen_star n=$MAXN mid=$MAXN k=15
tc g4-star-5 gen_star n=$MAXN mid=$(($MAXN-14)) k=15
tc g4-star-6 gen_star n=$MAXN mid=$(($MAXN-15)) k=15
tc g4-doublestar-7 gen_doublestar n=$MAXN mid=1 k=15
tc g4-bipart-8 gen_bipartish n=$MAXN m=$MAXM k=15 b=2 same=0
tc g4-bipart-9 gen_bipartish n=$MAXN m=$MAXM k=15 b=3 same=0
tc g4-bipart-10 gen_bipartish n=$MAXN m=$MAXM k=15 b=5 same=0
tc g4-bipart-11 gen_bipartish n=$MAXN m=$MAXM k=15 b=5 same=1
tc g4-bipart-12 gen_bipartish n=$MAXN m=$MAXM k=15 b=13 same=0

group group5 35
limits max_n=$MAXN max_m=$MAXM max_k=$MAXN
include_group group3
include_group group4

tc g5-rand-1 gen_random n=$MAXN m=$MAXM k=$(($MAXN-1))
tc g5-rand-2 gen_random n=$MAXN m=$MAXM k=$(($MAXN/2))
tc g5-rand-3 gen_random n=$MAXN m=$MAXM k=$(($MAXN/3))
tc g5-rand-4 gen_random n=$MAXN m=$MAXM k=$(($MAXN/10))
tc g5-star-5 gen_star n=$MAXN mid=1 k=$(($MAXN-2))
tc g5-doublestar-6 gen_doublestar n=$MAXN mid=1 k=$(($MAXN/2))
tc g5-doublestar-7 gen_doublestar n=$MAXN mid=3 k=$(($MAXN/2))
tc g5-doublestar-8 gen_doublestar n=$MAXN mid=1 k=$(($MAXN/2+3))
tc g5-path-9 gen_path n=$MAXN k=$(($MAXN/2)) b=300
tc g5-path-10 gen_path n=$MAXN k=$(($MAXN-10000)) b=1000
tc g5-abc-11 gen_abc n=$MAXN k=$(($MAXN-2))
tc g5-bipart-12 gen_bipartish n=$MAXN m=$MAXM k=$(($MAXN/2)) b=3 same=0
tc g5-bipart-13 gen_bipartish n=$MAXN m=$MAXM k=$(($MAXN/2)) b=10 same=0
tc g5-bipart-14 gen_bipartish n=$MAXN m=$MAXM k=$(($MAXN/2)) b=15 same=0
tc g5-bipart-15 gen_bipartish n=$MAXN m=$MAXM k=$(($MAXN/2)) b=30 same=0
tc g5-bipart-16 gen_bipartish n=$MAXN m=$MAXM k=$(($MAXN/2)) b=50 same=0
tc g5-bipart-17 gen_bipartish n=$MAXN m=$MAXM k=$(($MAXN/2)) b=100 same=1
tc g5-bipart-18 gen_bipartish n=$MAXN m=$MAXM k=$(($MAXN/2)) b=5000 same=1
tc g5-bipart-19 gen_bipartish n=$MAXN m=$MAXM k=$(($MAXN/2)) b=$(($MAXN/3)) same=1
tc g5-bipart-20 gen_bipartish n=$MAXN m=$MAXM k=$(($MAXN/5)) b=500 same=1