#! env /bin/python3

n,b,W = list(map(int,input().split()))
bats = []
for i in range(n):
    bats.append(list(map(int,input().split())))

def test(f):
    dp = [[0]*(b+1) for _ in range(n+1)]
    for i in range(n):
        e,w,c = bats[i]
        for j in range(b+1):
            dp[i+1][j] = dp[i][j]
            if j>=c:
                dp[i+1][j] = max(dp[i][j-c]+e-f*w, dp[i+1][j])
    return dp[n][b]>W*f


l = 0
r = 1e9

for _ in range(50):
    m = (l+r)/2
    if test(m):
        l = m
    else:
        r = m
print((l+r)/2)