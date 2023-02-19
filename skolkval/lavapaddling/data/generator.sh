#!/usr/bin/env bash

PPATH=$(realpath ..)

REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

use_solution fe_100.cpp

samplegroup
sample 1
sample 2
sample 3

group g1 20
limits max_k=1 maxh=100
tc_manual g1

group g2 40
include_group g1
limits max_k=1
tc_manual g2

group g3 40
include_group g2
include_group samplegroup
tc_manual g3
