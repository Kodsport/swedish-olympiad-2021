#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution sl.cpp

compile gen_random.py
compile gen_binpack.py
compile gen_max.py

maxn=4000

samplegroup
limits n=15 b=+-
sample 1
sample 2
sample 3

group group1 10
limits n=15 b=+-
include_group sample

tc g1-big gen_random n=15
tc g1-n1 gen_random n=1

# lots of small cases for correctness testing
tc g1-n3-1 gen_random n=3
tc g1-n4-1 gen_random n=4
tc g1-n4-2 gen_random n=4
tc g1-n4-3 gen_random n=4
tc g1-n4-4 gen_random n=4
tc g1-n4-5 gen_random n=4
tc g1-n4-6 gen_random n=4
tc g1-n4-7 gen_random n=4
tc g1-n5-1 gen_random n=5
tc g1-n5-2 gen_random n=5
tc g1-n5-3 gen_random n=5
tc g1-n5-4 gen_random n=5
tc g1-n5-5 gen_random n=5 chi=3
tc g1-n5-6 gen_random n=5 chi=3
tc g1-n5-7 gen_random n=5 chi=3
tc g1-n6 gen_random n=6
tc g1-n7 gen_random n=7 chi=4
tc g1-n8 gen_random n=8 chi=3
tc g1-n9 gen_random n=9 chi=4
tc g1-n10 gen_random n=10 chi=3
tc g1-n11 gen_random n=11 chi=4
tc g1-n12 gen_random n=12 chi=3
tc g1-n13 gen_random n=13 chi=4
tc g1-n14 gen_random n=14 chi=3

# some more structured cases
tc g1-n15-2 gen_random n=15
tc g1-n15-3 gen_random n=15
tc g1-neg gen_random n=15 bmode=neg
tc g1-pos gen_random n=15 bmode=pos
tc g1-bp-1 gen_binpack n=15
tc g1-bp-2 gen_binpack n=14 cdiv=3
tc g1-bp-3 gen_binpack n=14 rand=5 chi=3

group group2 15
limits n=200 b=+-
include_group group1

tc g2-rand gen_random n=200
tc g2-neg gen_random n=200 chi=5 bmode=neg
tc g2-pos-1 gen_random n=200 chi=5 bmode=pos
tc g2-pos-2 gen_random n=200 chi=40 bmode=pos
tc g2-pos-3 gen_random n=200 chi=40 ahi=5 bmode=pos
tc g2-bp-1 gen_binpack n=200
tc g2-bp-2 gen_binpack n=200 cdiv=7
tc g2-bp-3 gen_binpack n=200 cdiv=7 chi=30
tc g2-bp-4 gen_binpack n=200 cdiv=7 chi=30 rand=10 chirand=5

group group3 15
limits n=$maxn b=+

tc 1
tc g1-pos
tc g2-pos-1
tc g2-pos-2
tc g2-pos-3
tc g3-pos-1 gen_random n=$maxn bmode=pos
tc g3-pos-2 gen_random n=$maxn chi=5 bmode=pos
tc g3-pos-3 gen_random n=$maxn chi=40 bmode=pos
tc g3-pos-4 gen_random n=$maxn chi=40 ahi=5 bmode=pos
tc g3-max-1 gen_max n=$maxn

group group4 23
limits n=$maxn b=-

tc 2
tc g1-neg
tc g2-neg
tc g2-bp-1
tc g2-bp-2
tc g2-bp-3
tc g4-rand-1 gen_random n=$maxn bmode=neg
tc g4-rand-2 gen_random n=$maxn chi=5 bmode=neg
tc g4-bp-1 gen_binpack n=$maxn
tc g4-bp-2 gen_binpack n=$maxn cdiv=7
tc g4-bp-3 gen_binpack n=$maxn cdiv=7 chi=30
tc g4-min-1 gen_max n=$maxn mode=min

group group5 37
limits n=$maxn b=+-

include_group group2
include_group group3
include_group group4

tc g5-1 gen_random n=$maxn
tc g5-bp-1 gen_binpack n=$maxn rand=2
tc g5-bp-2 gen_binpack n=$maxn cdiv=7 rand=10 chirand=5
tc g5-bp-3 gen_binpack n=$maxn cdiv=31 chi=200 rand=8 chirand=8
tc g5-bp-4 gen_binpack n=$maxn chi=20 rand=30
