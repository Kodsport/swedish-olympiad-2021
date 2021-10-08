#!/usr/bin/python3
#@EXPECTED_GRADES@ AC WA WA WA WA WA
n, m, k = map(int, input().split())
print((k - 1) // (n - 1))
