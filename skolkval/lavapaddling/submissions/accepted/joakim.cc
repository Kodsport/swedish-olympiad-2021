#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


template<class I>
I binary_search(I a, I b, auto&& f) {
  assert(a < b);
  while(a + 1 < b) {
    I q = a + (b - a)/2;
    (f(q) ? b : a) = q;
  }
  return b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n,k,h;
  cin>>n>>k>>h;
  vector<ll> d(n-1);
  rep(i,0,n-1) {
    cin>>d[i];
    d[i] *= h;
  }

  ll ans = binary_search<ll>(0,1e16,[&](ll q){
    rep(i,0,n-1) {
      ll free = (k-1) * q;
      ll need = d[i] - free;
      if(q < need) return false;
      if(need > 0) q -= need;
    }
    return true;
  });

  cout << ans << endl;
}
