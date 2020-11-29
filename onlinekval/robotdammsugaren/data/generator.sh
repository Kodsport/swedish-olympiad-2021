#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution fredrik_100.cpp

compile gen_random.py
compile gen_from_sequence.py
compile poster.py

samplegroup
limits max_r=-1 max_rcn=-1
sample 1
sample 2
sample 3
sample 4

group group1 20
limits max_r=-1 max_rcn=-1
tc poster poster

group group2 20
limits max_r=3 max_rcn=-1

tc 3

tc g2-rand-1 gen_random r=3 c=3 n=1 box_ratio=0.0
tc g2-rand-2 gen_random r=3 c=100 n=100 box_ratio=0.06 available_commands="^v"
tc g2-rand-3 gen_random r=3 c=100 n=100 box_ratio=0.10 available_commands="<^v"
tc g2-rand-4 gen_random r=3 c=100 n=100 box_ratio=0.03 available_commands=">^v"
tc g2-rand-5 gen_random r=3 c=100 n=100 box_ratio=0.0 available_commands="<>^v"
tc g2-rand-6 gen_random r=3 c=1333 n=1987 box_ratio=0.05 available_commands="^v"
tc g2-rand-7 gen_random r=3 c=1993 n=1543 box_ratio=0.01 available_commands="<^v"
tc g2-rand-8 gen_random r=3 c=1023 n=1644 box_ratio=0.02 available_commands=">^v"
tc g2-rand-9 gen_random r=3 c=2000 n=2000 box_ratio=0.03 available_commands="<>^v"


group group3 30
limits max_r=-1 max_rcn=1000

include_group group1

tc 1
tc 2

tc g3-rand-1 gen_random r=10 c=10 n=1 box_ratio=0.03
tc g3-rand-2 gen_random r=10 c=10 n=5 box_ratio=0.03
tc g3-rand-3 gen_random r=10 c=10 n=10 box_ratio=0.0
tc g3-rand-4 gen_random r=10 c=10 n=10 box_ratio=0.3
tc g3-rand-5 gen_random r=10 c=10 n=10 box_ratio=1.0
tc g3-rand-6 gen_random r=30 c=5 n=5 box_ratio=0.01
tc g3-rand-7 gen_random r=10 c=50 n=2 box_ratio=0.05
tc g3-rand-8 gen_random r=40 c=3 n=7 box_ratio=0.03
tc g3-rand-9 gen_random r=300 c=3 n=1 box_ratio=0.01
tc g3-rand-10 gen_random r=3 c=3 n=100 box_ratio=0.01

tc g3-seq-1 gen_from_sequence r=10 c=10 n=5 min_length=5
tc g3-seq-2 gen_from_sequence r=10 c=10 n=10 min_length=7
tc g3-seq-3 gen_from_sequence r=30 c=5 n=5 min_length=20
tc g3-seq-4 gen_from_sequence r=10 c=50 n=2 min_length=30
tc g3-seq-5 gen_from_sequence r=40 c=3 n=7 min_length=30

#group group4 10
#limits max_r=-1 max_rcn=1000000

#include_group group3

#tc g4-rand-1 gen_random r=100 c=100 n=100 box_ratio=0.03
#tc g4-rand-2 gen_random r=1000 c=10 n=100 box_ratio=0.1
#tc g4-rand-3 gen_random r=50 c=2000 n=10 box_ratio=0.03
#tc g4-rand-4 gen_random r=3 c=2000 n=100 box_ratio=0.06
#tc g4-rand-5 gen_random r=30 c=30 n=1000 box_ratio=0.01

#tc g4-seq-1 gen_from_sequence r=100 c=100 n=100 min_length=80
#tc g4-seq-2 gen_from_sequence r=1000 c=10 n=100 min_length=700
#tc g4-seq-3 gen_from_sequence r=50 c=2000 n=10 min_length=1990
#tc g4-seq-4 gen_from_sequence r=4 c=2000 n=100 min_length=1001
#tc g4-seq-5 gen_from_sequence r=30 c=30 n=1000 min_length=35


group group4 30
limits max_r=-1 max_rcn=-1

include_group group3
include_group group2

tc 4

tc g4-rand-1 gen_random r=2000 c=2000 n=2000 box_ratio=0.03
tc g4-rand-2 gen_random r=2000 c=1500 n=2000 box_ratio=0.1
tc g4-rand-3 gen_random r=2000 c=2000 n=10 box_ratio=0.03
tc g4-rand-4 gen_random r=5 c=2000 n=2000 box_ratio=0.06
tc g4-rand-5 gen_random r=1999 c=1997 n=2000 box_ratio=0.01

tc g4-seq-1 gen_from_sequence r=2000 c=2000 n=2000 min_length=1960
tc g4-seq-2 gen_from_sequence r=2000 c=1500 n=2000 min_length=1300
tc g4-seq-3 gen_from_sequence r=2000 c=2000 n=10 min_length=1990
tc g4-seq-4 gen_from_sequence r=3 c=2000 n=2000 min_length=1500
tc g4-seq-5 gen_from_sequence r=1999 c=1997 n=2000 min_length=1000
