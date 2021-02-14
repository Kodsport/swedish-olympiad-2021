#!/usr/bin/env bash

PPATH=$(realpath ..)
REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

use_solution fredrik.cpp

compile gen.py


samplegroup
limits c=0
sample_manual 1

testcase() {
	NAME=$(printf "%02d" $1)
	group group$NAME 10
	limits c=$1
	tc "case$NAME" "${@:2}" tc=$1
}

testcase 1 gen N=500 T=5000 K=3
testcase 2 gen N=500 T=5000 K=30
testcase 3 gen N=500 T=50000 K=3
testcase 4 gen N=500 T=50000 K=30
testcase 5 gen N=100000 T=10000000 K=3
testcase 6 gen N=100000 T=10000000 K=30
testcase 7 gen N=300 T=30000 K=-1 mode=downtree
testcase 8 gen N=300 T=30000 K=-1 mode=uptree
testcase 9 gen N=100000 T=10000000 K=-1 mode=downtree
testcase 10 gen N=100000 T=10000000 K=-1 mode=uptree


# Clamp final scores to 100
echo 'grading: custom' >> testdata.yaml
echo 'grading: default' >> secret/testdata.yaml
echo 'grading: default' >> sample/testdata.yaml
