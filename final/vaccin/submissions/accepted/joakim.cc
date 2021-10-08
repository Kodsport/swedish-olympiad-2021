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
  int k,n;
  cin>>k>>n;
  vi v(k+1), f(n);
  rep(i,0,k) cin>>v[i+1];
  rep(i,0,k) v[i+1] += v[i];
  rep(i,0,n) {
    ll t;
    cin>>t;
    auto it = upper_bound(all(v),t);
    if(it == end(v)) cout<<-1<<endl;
    else
     cout << int(it - begin(v)) << "\n";
  }
}
