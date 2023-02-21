#!/usr/bin/env bash

PPATH=$(realpath ..)

REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

use_solution gustav.cpp

compile gen.py

samplegroup
limits max_n=-1
sample 1
sample 2
sample 3

group g1 20
limits max_n=23
tc_manual g1
tc tiny1 gen n=15 mode="specific" # Too much identical test data otherwise
tc tiny2 gen n=23 mode="specific" 
tc tiny3 gen n=19 mode="specific"
tc tiny4 gen n=12 mode="specific"
tc tiny5 gen n=18 mode="specific"

group g2 20
include_group g1
limits max_n=200
tc_manual g2
tc small1 gen n=200
tc small2 gen n=169 
tc small3 gen n=200 mode="largeans"
tc small4 gen n=178 mode="largeans"

group g3 20
include_group g2
limits max_n=5000
tc medium1 gen n=5000
tc medium2 gen n=4598 
tc medium3 gen n=5000 mode="largeans"
tc medium4 gen n=4598 mode="largeans"

group g4 40
include_group g3
limits max_n=-1
tc_manual g3
tc_manual g4
tc_manual g5
tc large1 gen n=86399
tc large2 gen n=64800 
tc large3 gen n=86399 mode="largeans"
tc large4 gen n=64800 mode="largeans"
tc large5 gen n=86399 mode="smallans"
tc large6 gen n=64800 mode="smallans"
