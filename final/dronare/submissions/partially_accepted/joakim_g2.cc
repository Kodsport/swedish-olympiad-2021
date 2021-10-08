// @EXPECTED_GRADES@ WA AC WA WA

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool smax(auto &a, auto&& b) { return (a < b) ? (a = b, 1) : 0; } 

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n,B,W;
  cin>>n>>B>>W;
  vi e(n), w(n), c(n);
  rep(i,0,n) cin>>e[i]>>w[i]>>c[i];

  vector<ll> dp(2*B+10,-1e18);
  dp[0] = 0;
  rep(i,0,n)
    for(int x = B; x >= 0; --x)
      smax(dp[x+c[i]], dp[x] + e[i]);
  ll ans = *max_element(begin(dp), begin(dp)+B+1);

  cout << setprecision(14) << fixed;
  cout << ans * (long double)(1) / W << endl;
}

