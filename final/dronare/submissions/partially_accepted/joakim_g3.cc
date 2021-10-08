// @EXPECTED_GRADES@ WA WA AC WA

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
  ll n,B,W;
  cin>>n>>B>>W;
  vi e(n), w(n), c(n);
  rep(i,0,n) cin>>e[i]>>w[i]>>c[i];

  vi idx(n);
  iota(all(idx),0);

  double lo = 0, hi = 1e15;
  rep(_,0,100) {
      double q = (lo+hi)/2;
      sort(all(idx), [&](int a, int b) { return e[a]-q*w[a] > e[b]-q*w[b]; });
      ll ww = W, ee = 0, cc = 0;
      for(int i : idx) if(cc + c[i] <= B && e[i]-q*w[i] > 0) {
          ww += w[i];
          ee += e[i];
          cc += c[i];
      }
      if(ee >= q * ww) lo = q;
      else hi = q;
  }

  cout << setprecision(14) << fixed;
  cout << lo << endl;
}

