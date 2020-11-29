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
  ll n, m;
  cin >> n >> m;
  vector<string> v(n);
  rep(i,0,n) {
    cin>>v[i];
    assert(sz(v[i]) == m);
  }
  vi dp(1<<m,0);
  dp[(1<<m)-1] = 1;
  rep(i,0,n) {
    vi ndp(1<<m,0);
    rep(shift,0,m) {
      int msk = 0;
      rep(j,0,m)
        msk ^= ((v[i][(j+shift)%m] == '.') << j);
      rep(msk2,0,(1<<m))
        ndp[msk&msk2] += dp[msk2];
    }
    swap(dp,ndp);
  }
  ll ans = 0;
  rep(msk,1,(1<<m)) ans += dp[msk];
  cout << ans << endl;
}
