#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution fredrik_100.cpp

compile gen_random.py

samplegroup
limits max_n=20 line=0
sample_manual 1
sample_manual 2

group group1 20
limits max_n=100000 line=1

tc g1-1 gen_random n=1 k=1 mode=line shuffle_nodes=false
tc g1-2 gen_random n=2 k=1  mode=line shuffle_nodes=false
tc g1-3 gen_random n=100 k=10  mode=line shuffle_nodes=false
tc g1-4 gen_random n=100000 k=1  mode=line shuffle_nodes=false
tc g1-5 gen_random n=100000 k=10  mode=line shuffle_nodes=false
tc g1-6 gen_random n=100000 k=20000  mode=line shuffle_nodes=false
tc g1-7 gen_random n=100000 k=100000  mode=line shuffle_nodes=false

group group2 40
limits max_n=1000 line=0
include_group sample

tc g1-1
tc g1-2
tc g1-3
tc g2-1 gen_random n=10 k=3 mode=random
tc g2-2 gen_random n=1000 k=10 mode=shallow
tc g2-3 gen_random n=1000 k=500 mode=shallow
tc g2-4 gen_random n=1000 k=10 mode=deep
tc g2-5 gen_random n=1000 k=500 mode=deep
tc g2-6 gen_random n=1000 k=10 mode=deeper
tc g2-7 gen_random n=1000 k=500 mode=deeper
tc g2-8 gen_random n=1000 k=10 mode=degtwo
tc g2-9 gen_random n=1000 k=500 mode=degtwo
tc g2-10 gen_random n=1000 k=10 mode=star
tc g2-11 gen_random n=1000 k=500 mode=star

group group3 40
limits max_n=100000 line=0
include_group sample
include_group group1
include_group group2

tc g3-shallow1 gen_random n=100000 k=1000 mode=shallow fill_leaves=true
tc g3-shallow2 gen_random n=100000 k=10000 mode=shallow fill_leaves=true
tc g3-deep1 gen_random n=100000 k=1000 mode=deep fill_leaves=true
tc g3-deep2 gen_random n=100000 k=10000 mode=deep
tc g3-degtwo1 gen_random n=100000 k=1000 mode=degtwo fill_leaves=true
tc g3-degtwo2 gen_random n=100000 k=10000 mode=degtwo 
tc g3-star1 gen_random n=100000 k=1000 mode=star fill_leaves=true
tc g3-star2 gen_random n=100000 k=99999 mode=star fill_leaves=true
tc g3-starline1 gen_random n=100000 k=30000 mode=starline fill_leaves=true shuffle_nodes=false
tc g3-starline2 gen_random n=100000 k=40000 mode=starline fill_leaves=true shuffle_nodes=true
tc g3-deeper1 gen_random n=100000 k=1000 mode=deeper fill_leaves=true
tc g3-deeper2 gen_random n=100000 k=10000 mode=deeper fill_leaves=true
tc g3-deeper3 gen_random n=100000 k=30000 mode=deeper fill_leaves=true
