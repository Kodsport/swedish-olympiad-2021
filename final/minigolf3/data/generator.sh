#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution joakim.cc

compile gen.cc

samplegroup
sample 1
sample 2
sample 3

group group1 8 # empty grid
limits empty=1
tc 1
tc g1-tiny-1    gen -type=empty -r=2       -c=1      -k=10
tc g1-tiny-2    gen -type=empty -r=1       -c=2      -k=1
tc g1-tiny-3    gen -type=empty -r=2       -c=2      -k=2
tc g1-small-1   gen -type=empty -r=10      -c=20     -k=3
tc g1-small-2   gen -type=empty -r=20      -c=10     -k=10
tc g1-medium-1  gen -type=empty -r=2       -c=1000   -k=101
tc g1-medium-2  gen -type=empty -r=2       -c=1000   -k=1000
tc g1-medium-3  gen -type=empty -r=99      -c=99     -k=1
tc g1-large-1   gen -type=empty -r=1000000 -c=1      -k=2
tc g1-large-2   gen -type=empty -r=2       -c=500000 -k=5
tc g1-large-3   gen -type=empty -r=10      -c=100000 -k=7
tc g1-large-4   gen -type=empty -r=10      -c=100000 -k=70000
tc g1-large-5   gen -type=empty -r=100     -c=10000  -k=30
tc g1-large-6   gen -type=empty -r=100     -c=10000  -k=30000
tc g1-large-7   gen -type=empty -r=1000    -c=1000   -k=55
tc g1-large-8   gen -type=empty -r=1000    -c=1000   -k=9999
tc g1-large-9   gen -type=empty -r=10000   -c=100    -k=24
tc g1-large-10  gen -type=empty -r=2       -c=500000 -k=100000

group group2 18 # r = 2
limits max_r=2 min_r=2
tc 1
tc 2
tc g1-tiny-1
tc g1-tiny-3
tc g1-medium-1
tc g1-medium-2
tc g1-large-2
tc g1-large-10
tc g2-tiny-1    gen -type=random -r=2 -c=3      -k=2      -wallfrac=0.2
tc g2-tiny-2    gen -type=random -r=2 -c=3      -k=2      -wallfrac=0.25
tc g2-tiny-3    gen -type=random -r=2 -c=3      -k=8      -wallfrac=0.7
tc g2-small-1   gen -type=random -r=2 -c=17     -k=4      -wallfrac=0.1
tc g2-small-2   gen -type=random -r=2 -c=18     -k=1      -wallfrac=0.15
tc g2-small-3   gen -type=random -r=2 -c=19     -k=19     -wallfrac=0.2
tc g2-large-1   gen -type=random -r=2 -c=500000 -k=40000  -wallfrac=0.02
tc g2-large-2   gen -type=random -r=2 -c=500000 -k=40000  -wallfrac=0.2
tc g2-large-3   gen -type=random -r=2 -c=499999 -k=500000 -wallfrac=0.1
tc g2-large-4   gen -type=random -r=2 -c=499999 -k=50000  -wallfrac=0.2
tc g2-large-5   gen -type=random -r=2 -c=499999 -k=5000   -wallfrac=0.3
tc g2-large-6   gen -type=random -r=2 -c=499999 -k=500    -wallfrac=0.05
tc g2-large-7   gen -type=random -r=2 -c=499999 -k=50     -wallfrac=0.1
tc g2-large-8   gen -type=random -r=2 -c=499999 -k=5      -wallfrac=0.2
tc g2-large-9   gen -type=random -r=2 -c=499999 -k=1      -wallfrac=0.1
tc g2-large-10  gen -type=random -r=2 -c=499999 -k=50000  -wallfrac=0.001
tc g2-layers-1  gen -type=layers -r=2 -c=500000 -k=1      -holes=1
tc g2-layers-2  gen -type=layers -r=2 -c=500000 -k=5      -holes=1
tc g2-layers-3  gen -type=layers -r=2 -c=500000 -k=500    -holes=2
tc g2-layers-4  gen -type=layers -r=2 -c=500000 -k=500000 -holes=1

group group3 22 # r,c,k <= 100
include_group sample
limits max_r=100 max_c=100 max_k=100
tc g1-tiny-1
tc g1-tiny-3
tc g2-tiny-1
tc g2-tiny-2
tc g2-tiny-3
tc g2-small-1
tc g2-small-2
tc g2-small-3
tc g3-medium-1 gen -type=random -r=100 -c=100 -k=100 -wallfrac=0.2
tc g3-medium-2 gen -type=random -r=100 -c=100 -k=100 -wallfrac=0.7
tc g3-medium-3 gen -type=random -r=100 -c=100 -k=19  -wallfrac=0.2
tc g3-medium-4 gen -type=random -r=100 -c=100 -k=2   -wallfrac=0.02
tc g3-medium-5 gen -type=random -r=100 -c=100 -k=50  -wallfrac=0.1
tc g3-layers-1 gen -type=layers -r=100 -c=100 -k=1   -holes=1
tc g3-layers-2 gen -type=layers -r=100 -c=100 -k=30  -holes=2
tc g3-layers-3 gen -type=layers -r=100 -c=100 -k=30  -holes=7


group group4 25 # k = infty
limits k_infty=1
tc g1-tiny-1
tc g1-tiny-3
tc g1-medium-2
tc g1-large-6
tc g1-large-8
tc g2-tiny-3
tc g2-large-3
tc g2-small-3
tc g2-layers-4
tc g3-medium-1
tc g3-medium-2
tc g4-large-1  gen -type=random -r=10    -c=100000 -k=1000000 -wallfrac=0.1
tc g4-large-2  gen -type=random -r=10    -c=100000 -k=1000000 -wallfrac=0.2
tc g4-large-3  gen -type=random -r=100   -c=10000  -k=1000000 -wallfrac=0.3
tc g4-large-4  gen -type=random -r=100   -c=10000  -k=1000000 -wallfrac=0.2
tc g4-large-5  gen -type=random -r=1000  -c=1000   -k=1000000 -wallfrac=0.15
tc g4-large-6  gen -type=random -r=1000  -c=1000   -k=1000000 -wallfrac=0.02
tc g4-large-7  gen -type=random -r=10000 -c=100    -k=1000000 -wallfrac=0.7
tc g4-layers-1 gen -type=layers -r=10    -c=100000 -k=1000000 -holes=1
tc g4-layers-2 gen -type=layers -r=10    -c=100000 -k=1000000 -holes=2
tc g4-layers-3 gen -type=layers -r=100   -c=10000  -k=1000000 -holes=1
tc g4-layers-4 gen -type=layers -r=100   -c=10000  -k=1000000 -holes=3
tc g4-layers-5 gen -type=layers -r=1000  -c=1000   -k=1000000 -holes=2
tc g4-layers-6 gen -type=layers -r=1000  -c=1000   -k=1000000 -holes=1
tc g4-layers-7 gen -type=layers -r=10000 -c=100    -k=1000000 -holes=15



group group5 27
include_group sample
include_group group1
include_group group2
include_group group3
include_group group4
tc g5-large-1  gen -type=random -r=10    -c=100000  -k=100000 -wallfrac=0.1
tc g5-large-2  gen -type=random -r=10    -c=100000  -k=10000 -wallfrac=0.2
tc g5-large-3  gen -type=random -r=100   -c=10000   -k=100000 -wallfrac=0.3
tc g5-large-4  gen -type=random -r=100   -c=10000   -k=400000 -wallfrac=0.2
tc g5-large-5  gen -type=random -r=1000  -c=1000    -k=500000 -wallfrac=0.15
tc g5-large-6  gen -type=random -r=1000  -c=1000    -k=100000 -wallfrac=0.02
tc g5-large-7  gen -type=random -r=10000 -c=100     -k=10000 -wallfrac=0.7
tc g5-layers-1 gen -type=layers -r=10    -c=100000 -k=100000 -holes=1
tc g5-layers-2 gen -type=layers -r=10    -c=100000 -k=10000 -holes=2
tc g5-layers-3 gen -type=layers -r=100   -c=10000  -k=20000 -holes=1
tc g5-layers-4 gen -type=layers -r=100   -c=10000  -k=800000 -holes=3
tc g5-layers-5 gen -type=layers -r=1000  -c=1000   -k=70000 -holes=2
tc g5-layers-6 gen -type=layers -r=1000  -c=1000   -k=900000 -holes=1
tc g5-layers-7 gen -type=layers -r=10000 -c=100    -k=900000 -holes=15
tc g5-layers-8 gen -type=layers -r=1000  -c=1000   -k=1 -holes=1

