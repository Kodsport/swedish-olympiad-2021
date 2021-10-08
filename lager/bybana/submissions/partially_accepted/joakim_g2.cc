// @EXPECTED_GRADES@ RTE AC TLE TLE RTE

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool smin(auto &a, auto&& b) { return (b < a) ? (a = b, 1) : 0; } 

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, l;
  cin >> n >> l;
  vector<vi> dist(n, vi(n,1e9));

  rep(line,0,l) {
    int m;
    cin >> m;
    vi v(m);
    rep(i,0,m) {
      cin >> v[i];
      --v[i];
    }
    rep(i,0,n) rep(j,i+1,m) {
      smin(dist[v[i]][v[j]], i + m - j - 1);
      smin(dist[v[j]][v[i]], i + m - j - 1);
    }
  }
  rep(k,0,n) rep(i,0,n) rep(j,0,n)
    smin(dist[i][j], dist[i][k] + dist[k][j]);

  cout << dist[0][n-1] << endl;
}
