// @EXPECTED_GRADES@ AC TLE TLE TLE

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n,B,W;
  cin>>n>>B>>W;
  vi e(n), w(n), c(n);
  rep(i,0,n) cin>>e[i]>>w[i]>>c[i];

  long double ans = 0;
  ll up = (n <= 60 ? 1LL<<n : 1e18);
  rep(msk,0,up) {
    ll ee = 0, ww = W, cc = 0;
    rep(i,0,n) if(msk>>i&1) {
      ee += e[i];
      ww += w[i];
      cc += c[i];
    }
    if(cc <= B)
      ans = max(ans, ee * (long double)(1) / ww);
  }

  cout << setprecision(14) << fixed;
  cout << ans << endl;
}
