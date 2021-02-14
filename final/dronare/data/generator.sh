#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution joakim.cc opt

compile gen_random.py

MAXN=100000
MAXW=1000

samplegroup
limits maxn=$MAXN maxw=$MAXW sameprice=0
sample 1

group group1 10
limits maxn=20 maxw=$MAXW sameprice=0
tc 1
tc n20-rand1 gen_random n=1 b=4 g=1
tc n20-rand2 gen_random n=7 b=97 g=1
tc n20-rand3 gen_random n=15 b=10 g=1
tc n20-rand4 gen_random n=19 b=245 g=1
tc n20-rand5 gen_random n=19 b=344 g=1
tc n20-rand6 gen_random n=19 b=900 g=1
tc n20-rand7 gen_random n=20 b=1000 g=1
tc n20-rand8 gen_random n=20 b=10000 g=1

tc n20-rand9 gen_random n=20 b=10000 g=5
tc n20-rand10 gen_random n=20 b=5 g=1 minC=1
tc n20-rand11 gen_random n=20 b=20 g=1 minC=3
tc n20-rand12 gen_random n=20 b=50 g=1 minC=1 maxC=4
tc n20-rand13 gen_random n=20 b=10000 g=1 minC=1 maxC=3000
tc n20-rand14 gen_random n=20 b=10000 g=1 minC=1 maxC=3000
tc n20-rand15 gen_random n=20 b=10000 g=1 minC=1 maxC=3000
tc n20-rand16 gen_random n=20 b=10000 g=1 minC=1 maxC=3000
tc n20-rand17 gen_random n=20 b=10000 g=1 minC=1 maxC=3000
tc n20-rand18 gen_random n=20 b=10000 g=1 minC=1 maxC=3000
tc n20-rand19 gen_random n=20 b=10000 g=1 minC=1 maxC=3000
tc n20-maxans gen_random n=20 b=10000 g=1 maxW=0 minE=1000 maxC=10
tc n20-minans gen_random n=20 b=10000 g=1 maxE=0 minW=1000 maxC=10

group group2 20
limits maxn=$MAXN maxw=0 sameprice=0

tc wi0-rand1 gen_random n=50 b=1000 g=2
tc wi0-rand2 gen_random n=20 b=10000 g=2
tc wi0-rand3 gen_random n=80 b=20 g=2
tc wi0-rand4 gen_random n=80 b=20 g=2
tc wi0-rand5 gen_random n=100 b=10 g=2
tc wi0-rand6 gen_random n=100 b=10 g=2
tc wi0-rand7 gen_random n=150 b=10 g=2
tc wi0-rand8 gen_random n=150 b=10 g=2
tc wi0-rand9 gen_random n=5 b=200 g=2
tc wi0-rand10 gen_random n=5 b=200 g=2
tc wi0-rand11 gen_random n=3 b=300 g=2
tc wi0-rand12 gen_random n=500 b=400 g=2
tc wi0-rand13 gen_random n=1000 b=100 g=2
tc wi0-rand14 gen_random n=1000 b=200 g=2
tc wi0-rand15 gen_random n=100000 b=1 g=2
tc wi0-rand16 gen_random n=1 b=100000 g=2

tc wi0-rand17 gen_random n=20 b=5 g=2 minC=1
tc wi0-rand18 gen_random n=20 b=20 g=2 minC=3
tc wi0-rand19 gen_random n=20 b=50 g=2 minC=1 maxC=4
tc wi0-maxans gen_random n=100000 b=1 g=2 maxW=0 minE=1000 maxC=0
tc wi0-minans gen_random n=100000 b=1 g=2 maxE=0 minW=1000 maxC=0

group group3 20
limits maxn=$MAXN maxw=$MAXW sameprice=1

tc cs-rand12 gen_random n=1 b=4 g=3
tc cs-rand11 gen_random n=10 b=20 g=3
tc cs-rand1 gen_random n=200 b=1000 g=3
tc cs-rand2 gen_random n=200 b=1000 g=3
tc cs-rand3 gen_random n=500 b=400 g=3
tc cs-rand4 gen_random n=500 b=400 g=3
tc cs-rand5 gen_random n=10000 b=20 g=3
tc cs-rand6 gen_random n=10000 b=20 g=3
tc cs-rand7 gen_random n=20 b=10000 g=3
tc cs-rand8 gen_random n=20 b=10000 g=3
tc cs-rand9 gen_random n=1 b=100000 g=3
tc cs-rand10 gen_random n=100000 b=1 g=3
tc cs-maxans gen_random n=100000 b=1 g=3 maxW=0 minE=1000 maxC=0
tc cs-minans gen_random n=100000 b=1 g=3 maxE=0 minW=1000 maxC=0

group group4 50
limits maxn=$MAXN maxw=$MAXW sameprice=0
include_group group1
include_group group2
include_group group3
tc full-rand1 gen_random n=200 b=1000 g=4
tc full-rand2 gen_random n=200 b=1000 g=4
tc full-rand3 gen_random n=500 b=400 g=4
tc full-rand4 gen_random n=500 b=400 g=4
tc full-rand5 gen_random n=10000 b=20 g=4
tc full-rand6 gen_random n=10000 b=20 g=4
tc full-rand7 gen_random n=20 b=10000 g=4
tc full-rand8 gen_random n=20 b=10000 g=4
tc full-rand9 gen_random n=1 b=100000 g=4
tc full-rand10 gen_random n=100000 b=1 g=4

tc full-rand11 gen_random n=10000 b=20 g=5
tc full-rand12 gen_random n=20 b=10000 g=5
tc full-rand13 gen_random n=20 b=10000 g=5
tc full-rand14 gen_random n=1 b=100000 g=5
tc full-rand15 gen_random n=100000 b=1 g=5

tc full-many  gen_random n=2000 b=100 g=4 minE=123 maxE=921 minW=123 maxW=921 minC=0 maxC=2
