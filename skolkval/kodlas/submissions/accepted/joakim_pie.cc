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
  vi v(n);
  rep(i,0,n) {
    string s;
    cin>>s;
    rep(j,0,m) if(s[j] == '.') v[i] ^= (1<<j);
    v[i] = v[i] + (v[i]<<m);
  }

  ll ans = 0;
  rep(msk,1,(1<<m)) { // inclusion/exclusion
    ll cur = 1;
    rep(i,0,n){
      ll cnt = 0;
      rep(j,0,m) if(((v[i]>>j)&msk) == msk)
        ++cnt;
      cur *= cnt;
    }
    ans += (__builtin_popcount(msk)%2 ? 1 : -1) * cur;
  }
  cout << ans << endl;
}
