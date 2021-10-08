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
  int n, l;
  cin >> n >> l;
  vector<vector<pair<int,ll>>> g(n);
  auto ae = [&](int a, int b, ll cost) {
    g[a].emplace_back(b, cost);
    g[b].emplace_back(a, cost);
  };
  rep(_,0,l) {
    int m;
    cin >> m;
    vi v(m);
    rep(i,0,m) {
      cin >> v[i];
      --v[i];
    }
    rep(i,0,m) {
      ae(v[i],v[0],m-i-1);
      ae(v[i],v[m-1],i);
    }
  }

  vector<ll> dist(n, 1e18);
  priority_queue<pair<ll,int> > pq;
  dist[0] = 0;
  pq.emplace(0,0);
  while(!pq.empty()) {
    auto [d,x] = pq.top();
    d = -d;
    pq.pop();
    if(d > dist[x]) continue;
    for(auto [y,w] : g[x]) {
      if(dist[y] > d + w) {
        dist[y] = d + w;
        pq.emplace(-dist[y], y);
      }
    }
  }

  assert(dist[n-1] != 1e18);
  cout << dist[n-1] << endl;
}
