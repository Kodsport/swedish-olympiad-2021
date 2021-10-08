#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const pii BAD = {-inf,-inf};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int r,c,k;
  cin>>r>>c>>k;
  vector<string> grid(r);
  rep(i,0,r) cin>>grid[i];

  pii start = BAD, goal = BAD;
  rep(i,0,r) rep(j,0,c) {
    if(grid[i][j] == 'S') start = {i,j};
    if(grid[i][j] == 'G') goal = {i,j};
  }
  assert(start != BAD && goal != BAD);


  vector<vector<vector<pii>>> nxt_free(4, vector<vector<pii>>(r,vector<pii>(c,BAD)));
  function<pii(int,int,int)> nxt = [&](int d, int x, int y) {
    if(nxt_free[d][x][y] != BAD && nxt_free[d][x][y] != pii{x,y})
      nxt_free[d][x][y] = nxt(d, nxt_free[d][x][y].first, nxt_free[d][x][y].second);
    return nxt_free[d][x][y];
  };

  rep(x,0,r) rep(y,0,c) {
    if(grid[x][y] != '#') rep(d,0,4) nxt_free[d][x][y] = {x,y};
  }

  int dx[] = {-1,0,1,0};
  int dy[] = {0,1,0,-1};
  auto valid = [&](int x, int y) { return 0 <= x && x < r && 0 <= y && y < c; };

  queue<pii> q;
  vector<vi> dist(r,vi(c,inf));
  auto push_to_queue = [&](int x, int y, int D) {
    dist[x][y] = D;
    q.emplace(x,y);
    rep(d,0,4) {
      nxt_free[d][x][y] = BAD;
      int nx = x + dx[d], ny = y + dy[d];
      if(valid(nx,ny)) nxt_free[d][x][y] = {nx,ny};
    }
  };

  push_to_queue(start.first, start.second, 0);
  while(sz(q)) {
    auto [x,y] = q.front();
    q.pop();
    rep(d,0,4) {
      for(pii p = nxt(d,x,y); abs(p.first-x) + abs(p.second-y) <= k; p = nxt(d,x,y))
        push_to_queue(p.first, p.second, dist[x][y]+1);
    }
  }

  int ans = dist[goal.first][goal.second];
  assert(ans != inf);
  cout << ans << endl;
}
