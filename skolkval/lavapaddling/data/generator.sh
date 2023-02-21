#!/usr/bin/env bash

PPATH=$(realpath ..)

REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

use_solution fe_100.cpp

compile gen.py


samplegroup
sample 1
sample 2
sample 3

group group1 20
limits max_k=1 max_h=100
tc_manual g1
tc fixedk1 gen n=15 k=1 h=90
tc fixedk2 gen n=20 k=1 h=100
tc fixedk3 gen n=10 k=1 h=30
tc fixedk4 gen n=17 k=1 h=57

group group2 40
limits max_h=1
tc_manual g2
tc fixedh1 gen n=15 k=10 h=1
tc fixedh2 gen n=20 k=12 h=1
tc fixedh3 gen n=10 k=8  h=1
tc fixedh4 gen n=17 k=4  h=1

group group3 40
include_group group1
include_group group2
include_group sample
tc_manual g3
tc full1 gen n=20 k=13  h=954321098 seed=32874 # If larger, will cause int overflow
tc full2 gen n=13 k=14 h=424843857
tc full3 gen n=10 k=8 h=2348234832
tc full4 gen n=14 k=15 h=2373285935