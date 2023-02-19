#!/usr/bin/env bash

PPATH=$(realpath ..)

REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

use_solution joakim.cc

compile gen.py

samplegroup
sample 1
sample 2
sample 3

group g1 20
limits max_n=1000
tc_manual g1
tc 1
tc small_rand1 gen n=120
tc small_rand2 gen n=562
tc small_rand3 gen n=981
tc small_largeans4 gen n=1000 mode="largeans"
tc small_largeans5 gen n=1000 mode="largeans"
tc small_largeans6 gen n=1000 mode="largeans"
tc small_largeans7 gen n=1000 mode="largeans"

group g2 40
include_group g1
limits max_n=1000000
tc_manual g2
tc 2
tc medium_largeans1 gen n=1000000 mode="largeans"
tc medium_largeans2 gen n=1000000 mode="largeans"
tc medium_largeans3 gen n=1000000 mode="largeans"
tc medium_largeans4 gen n=1000000 mode="largeans"

group g3 40
include_group g2
tc 3
tc_manual g3
tc_manual g4
tc_manual g5
tc large_largeans1 gen n=1000000000 mode="largeans"
tc large_largeans2 gen n=1000000000 mode="largeans"
tc large_largeans3 gen n=1000000000 mode="largeans"
tc large_largeans4 gen n=1000000000 mode="largeans"

