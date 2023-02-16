#!/usr/bin/env python3

A, P = [int(i) for i in input().split()]
price_A = A*7
price_P = P*13

if price_A > price_P:
  print("Axel")
else:
  print("Petra")

