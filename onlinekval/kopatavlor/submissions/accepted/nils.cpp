#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;

vector<int> A;
int DP[2001][2001] = {0};
int n,k;

int main() {
    cin >> n >> k;
    rep(c1,0,n){
        int a;
        cin >> a;
        A.push_back(a);
    }
    int ans = 1000100;
    rep(c1,0,n){
        rep(c2,1,k+1){
            if(c1 == 0){
                DP[0][c2] = 1000000;
            }
            else{
                DP[c1][c2] = min(1+DP[c1-1][c2], A[c1]+1+DP[c1-1][c2-1]);
            }
            if(c2 == 1)DP[c1][c2] = min(DP[c1][c2], A[c1]);
        }
        ans = min(ans, DP[c1][k]);
    }
    cout << ans << "\n";
    return 0;
}
