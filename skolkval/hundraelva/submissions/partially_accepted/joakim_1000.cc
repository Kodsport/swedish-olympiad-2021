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
  ll n;
  cin>>n;
  vi v(n+1);
  rep(i,1,n+1) {
    v[i] = 1e9;
    ll k = 1;
    int nlim = 1;
    while(k <= i) {
      if (k == nlim) {
        v[i] = min(v[i], v[i-k]+1);
        nlim = 10 * k + 1;
      }
      k++;
    }
  }
  cout << v[n] << endl;
}
