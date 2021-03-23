#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution alligator_as_n2.cpp

samplegroup
sample 1
sample 2
sample 3

group group1 30
tc 1
tc 2
tc 3
tc_manual ../manual_tests/01.in
tc_manual ../manual_tests/02.in
tc_manual ../manual_tests/03.in
tc_manual ../manual_tests/04.in
tc_manual ../manual_tests/05.in
tc_manual ../manual_tests/06.in
tc_manual ../manual_tests/07.in
tc_manual ../manual_tests/08.in
tc_manual ../manual_tests/09.in
tc_manual ../manual_tests/10.in
tc_manual ../manual_tests/11.in
tc_manual ../manual_tests/12.in
tc_manual ../manual_tests/13.in
tc_manual ../manual_tests/14.in
tc_manual ../manual_tests/15.in
tc_manual ../manual_tests/16.in
tc_manual ../manual_tests/17.in
tc_manual ../manual_tests/18.in
tc_manual ../manual_tests/19.in
tc_manual ../manual_tests/20.in
tc_manual ../manual_tests/21.in

group group2 30
include_group group1
tc_manual ../manual_tests/22.in
tc_manual ../manual_tests/23.in
tc_manual ../manual_tests/24.in
tc_manual ../manual_tests/25.in
tc_manual ../manual_tests/26.in
tc_manual ../manual_tests/27.in
tc_manual ../manual_tests/28.in
tc_manual ../manual_tests/29.in
tc_manual ../manual_tests/30.in
tc_manual ../manual_tests/31.in
tc_manual ../manual_tests/32.in
tc_manual ../manual_tests/33.in
tc_manual ../manual_tests/34.in
tc_manual ../manual_tests/35.in
tc_manual ../manual_tests/36.in

group group3 40
include_group group2
tc_manual ../manual_tests/37.in
tc_manual ../manual_tests/38.in
tc_manual ../manual_tests/39.in
tc_manual ../manual_tests/40.in
tc_manual ../manual_tests/41.in
tc_manual ../manual_tests/42.in
tc_manual ../manual_tests/43.in
tc_manual ../manual_tests/44.in
tc_manual ../manual_tests/45.in
tc_manual ../manual_tests/46.in
tc_manual ../manual_tests/47.in
tc_manual ../manual_tests/48.in
tc_manual ../manual_tests/49.in
tc_manual ../manual_tests/50.in
tc_manual ../manual_tests/51.in