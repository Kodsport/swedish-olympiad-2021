// @EXPECTED_GRADES@ TLE TLE AC TLE TLE

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
  int r,c,k;
  cin>>r>>c>>k;
  int x0, y0;
  int x1, y1;
  vector<string> grid;
  rep(i,0,r) {
    string row;
    cin>>row;
    rep(j,0,c) {
      if(row[j] == 'S') x0 = i, y0 = j;
      if(row[j] == 'G') x1 = i, y1 = j;
    }
    grid.emplace_back(row);
  }

  int dx[] = {-1,0,1,0};
  int dy[] = {0,1,0,-1};
  auto valid = [&](int x, int y) { return 0 <= x && x < r && 0 <= y && y < c; };

  const int inf = 1e9;

  vector<vi> dist(r,vi(c,inf));
  queue<pii> q;
  dist[x0][y0] = 0;
  q.emplace(x0,y0);

  while(sz(q)) {
    auto [x,y] = q.front();
    q.pop();
    rep(d,0,4) {
      rep(i,1,k+1) {
        int nx = x + i*dx[d], ny = y + i*dy[d];
        if(!valid(nx,ny)) break;
        if(grid[nx][ny] == '#') break;
        if(dist[nx][ny] == inf) {
          dist[nx][ny] = dist[x][y] + 1;
          if(nx == x1 && ny == y1) goto DONE;
          q.emplace(nx,ny);
        }
      }
    }
  }
DONE:;

  cout << dist[x1][y1] << endl;
}
