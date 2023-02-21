#!/usr/bin/env bash

PPATH=$(realpath ..)

REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

use_solution joakim.cc

compile gen.py

samplegroup
sample_manual 1
sample_manual 2
sample_manual 3
sample_manual 4

group g1 40
limits max_n=5 max_m=5
tc 1
tc 2
tc 3
tc 4
tc_manual g1
tc_manual g2
tc_manual inc_exc_killer
tc_manual inc_exc_killer2
tc small1 gen n=4 m=2
tc small2 gen n=1 m=5
tc small3 gen n=4 m=4 max_dots=2
tc small4 gen n=4 m=4 max_dots=1

group g2 20
limits max_n=8 max_m=10 max_dots_per_row=3
tc_manual g3
tc_manual inc_exc_killer3
tc medium1 gen n=8 m=8  max_dots=3
tc medium2 gen n=1 m=5  max_dots=3
tc medium3 gen n=8 m=9  max_dots=2
tc medium4 gen n=8 m=10 max_dots=1

group g3 40
include_group g1
include_group g2
limits max_n=12 max_m=12
tc_manual g4
tc_manual g5
tc large1 gen n=12 m=9 
tc large2 gen n=11 m=11
tc large3 gen n=10 m=10
tc large4 gen n=9  m=12