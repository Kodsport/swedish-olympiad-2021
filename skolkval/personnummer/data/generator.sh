#!/usr/bin/env bash

PPATH=$(realpath ..)

REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

use_solution nils.py

compile gen_rand.py

samplegroup
sample 1
sample 2
sample 3

group g1 50 # No plus
limits noplus=1
tc_manual g1
tc_manual g2
tc_manual g4
tc noplus1 gen_rand symbol="-"
tc noplus2 gen_rand symbol="-"
tc noplus3 gen_rand symbol="-"
tc noplus4 gen_rand symbol="-"

group g2 50
include_group g1
tc_manual g3
tc_manual g5
tc full1 gen_rand symbol="+"
tc full2 gen_rand symbol="+"
tc full3 gen_rand symbol="+"
tc full4 gen_rand symbol="+"