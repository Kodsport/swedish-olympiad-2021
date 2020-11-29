#!/usr/bin/env python3
s = input()
year = 1900 + int(s[0]+s[1])
if year < 1920:
    year += 100
if s[6] == '+':
    year -= 100
print(str(year) + s[2:6] + s[7:])
