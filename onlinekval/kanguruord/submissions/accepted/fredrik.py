#! env /bin/python3


import bisect

s = input()
n = len(s)

b = [[] for i in range(26)]
for i,c in enumerate(s):
    b[ord(c)-ord('a')].append(i)

def find_substring_left(a):
    ind = []
    pos = 0
    for c in a:
        letter_indices = b[ord(c)-ord('a')]
        it = bisect.bisect_left(letter_indices, pos)
        if it==len(letter_indices):
            return [-1]
        pos = letter_indices[it]
        ind.append(pos)
        pos += 1
    return ind

def find_substring_right(a):
    ind = []
    pos = len(s)-1
    for c in a[::-1]:
        letter_indices = b[ord(c)-ord('a')]
        it = bisect.bisect_right(letter_indices, pos)-1
        if it==-1:
            return [-1]
        pos = letter_indices[it]
        ind.append(pos)
        pos -= 1
    return ind[::-1]

k = int(input())
ans = 0
for i in range(k):
    a = input()
    #print(find_substring_right(a))
    ans += int(find_substring_left(a)!=find_substring_right(a))

print(ans)