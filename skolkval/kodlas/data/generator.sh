#!/usr/bin/env bash

PPATH=$(realpath ..)

REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

use_solution joakim.cc

samplegroup
sample_manual 1
sample_manual 2
sample_manual 3
sample_manual 4

group g1 20
limits max_n=5 max_m=5 max_dots_per_row=3
tc_manual g1

group g2 20
limits max_n=5 max_m=5 max_dots_per_row=3
tc_manual g2

group g3 20
limits max_n=10 max_m=8 max_dots_per_row=3
tc_manual g3

group g4 20
limits max_n=12 max_m=12
tc_manual g4

group g5 20
limits max_n=12 max_m=12
tc_manual g5
