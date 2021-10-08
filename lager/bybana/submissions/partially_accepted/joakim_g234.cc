// @EXPECTED_GRADES@ TLE AC AC AC TLE

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
  vector<vi> lines(l);
  vector<vector<pii>> in_lines(n);

  rep(line,0,l) {
    int m;
    cin >> m;
    auto &v = lines[line];
    v.resize(m);
    rep(i,0,m) {
      cin >> v[i];
      --v[i];
      in_lines[v[i]].emplace_back(line, i);
    }
  }

  vector<ll> dist(n, 1e18);
  priority_queue<pair<ll,int> > pq;
  dist[0] = 0;
  pq.emplace(0,0);
  while(!pq.empty()) {
    auto [d,x] = pq.top();
    if(x == n-1) break;
    d = -d;
    pq.pop();
    if(d > dist[x]) continue;
    for(auto [line,pos] : in_lines[x]) {
      auto& v = lines[line];
      rep(i,0,sz(v)) {
        int y = v[i];
        int w = sz(v) - abs(i-pos)-1;
        if(dist[y] > d + w) {
          dist[y] = d + w;
          pq.emplace(-dist[y], y);
        }
      }
    }
  }

  cout << dist[n-1] << endl;
}
