#!/usr/bin/env bash

PPATH=$(realpath ..)

REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

use_solution leopold.cpp

compile gen_rand.py

samplegroup
sample 1
sample 2
sample 3

group g1 40
limits noeq=1
tc 1
tc 3
tc_manual g1
tc_manual g2
tc_manual g3
tc_manual g4
tc noeq1 gen_rand noeq=1 hi=500
tc noeq2 gen_rand noeq=1 hi=50
tc noeq3 gen_rand noeq=1 hi=20


group g2 60
include_group g1
limits noeq=0
tc 2
tc_manual g5
tc full1 gen_rand hi=1000
tc full2 gen_rand hi=999
tc full3 gen_rand hi=696
tc full4 gen_rand hi=420