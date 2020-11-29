#!/usr/bin/env bash

PPATH=$(realpath ..)

REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

use_solution gustav.cpp

samplegroup
limits max_n=-1
sample 1
sample 2
sample 3

group g1 20
limits max_n=23
tc_manual g1

group g2 20
limits max_n=200
tc_manual g2

group g3 20
limits max_n=-1
tc_manual g3

group g4 20
limits max_n=-1
tc_manual g4

group g5 20
limits max_n=-1
tc_manual g5

