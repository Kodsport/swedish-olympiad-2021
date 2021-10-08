// @EXPECTED_GRADES@ WA WA WA AC WA

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
  const int INDEP = 4;

  vector<vector<vi>> dist(5, vector<vi>(r,vi(c,inf)));
  deque<tuple<int,int,int>> q;
  dist[INDEP][x0][y0] = 0;
  q.emplace_front(INDEP,x0,y0);

  while(sz(q)) {
    auto [dir,x,y] = q.front();
    q.pop_front();
    if(dir == INDEP) {
      if(x == x1 && y == y1) goto DONE;
      rep(d,0,4) {
        if(dist[d][x][y] == inf) {
          dist[d][x][y] = dist[dir][x][y] + 1;
          q.emplace_back(d,x,y);
        }
      }
    }
    else {
      if(dist[INDEP][x][y] > dist[dir][x][y]) {
        dist[INDEP][x][y] = dist[dir][x][y];
        q.emplace_front(INDEP,x,y);
      }
      int nx = x + dx[dir], ny = y + dy[dir];
      if(valid(nx,ny) && grid[nx][ny] != '#') {
        if(dist[dir][nx][ny] > dist[dir][x][y]) {
          dist[dir][nx][ny] = dist[dir][x][y];
          q.emplace_front(dir,nx,ny);
        }
      }
    }
  }
DONE:;

     cout << dist[INDEP][x1][y1] << endl;
}
