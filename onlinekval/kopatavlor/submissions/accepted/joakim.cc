#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n,k;
    cin>>n>>k;
    vi dp(k+1,1e18), ndp(k+1);
    ll ans = 1e18;
    rep(i,0,n) {
        ll x;
        cin>>x;
        dp[0] = -1;
        rep(i,1,k+1) ndp[i] = min(dp[i]+1, dp[i-1]+1+x);
        ans = min(ans, ndp[k]);
        swap(dp,ndp);
    }
    cout << ans << endl;
}
