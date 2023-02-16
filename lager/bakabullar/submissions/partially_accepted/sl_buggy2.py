#!/usr/bin/env python3
import sys

n, d = map(int, input().split())
xs = list(map(int, input().split()))
xs.sort()

out = []

if d % 2 == 0:
    def swap(l):
        out.append(l)
        for i in range(len(xs)):
            x = xs[i]
            if l <= x < l+d:
                xs[i] = l+d-1 - (x - l)

    end_x = 0
    for i in range(n):
        end_x += 1
        target_x = end_x + d-1
        x = xs.pop(0)
        swap(x)
        x += d-1
        while x > target_x:
            if x - (d-1) >= target_x:
                x -= d-1
                swap(x)
            else:
                swap(x - d//2)
                x -= 1
        swap(end_x)
else:
    lis = [
        [x for x in xs if x % 2 == 0],
        [x for x in xs if x % 2 == 1]
    ]
    if len(lis[0]) < len(lis[1]):
        lis[0],lis[1] = lis[1],lis[0]
    if len(lis[0]) - len(lis[1]) > 1:
        print(-1)
        sys.exit(0)

    def swap(l):
        out.append(l)
        for parity in range(2):
            xs = lis[parity]
            for i in range(len(xs)):
                x = xs[i]
                if l <= x < l+d:
                    xs[i] = l+d-1 - (x - l)

    end_x = 1 - (lis[0][0] & 1)
    for i in range(n):
        end_x += 1
        target_x = end_x + d-1
        x = lis[i % 2].pop(0)
        swap(x)
        x += d-1
        while x > target_x:
            if x - (d-1) >= target_x:
                x -= d-1
                swap(x)
            else:
                swap(x - (d+1)//2)
                x -= 2
        swap(end_x)


print(len(out))
for x in out:
    print(x)
