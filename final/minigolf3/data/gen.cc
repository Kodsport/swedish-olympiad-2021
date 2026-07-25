#include "testlib.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<string> gen_random(int r, int c, float wall_fraction) {
  vector<string> grid(r,string(c,'.'));
  rep(x,0,r) rep(y,0,c) {
    if(rnd.next() < wall_fraction) grid[x][y] = '#';
  }
  return grid;
}

vector<string> gen_layers(int r, int c, int holes) {
  vector<string> grid(r,string(c,'.'));
  int far = rnd.next(3,15);
  rep(x,0,c) if(x%2) {
    rep(y,0,r) grid[y][x] = '#';
    rep(t,0,holes) {
      int y = rnd.wnext(r,far);
      if(x%4 == 1) y = r-1-y;
      grid[y][x] = '.';
    }
  }
  return grid;
}

void force_possible(auto& grid, pii start, pii goal) {
  // remove min number of '#' to create a path from start to goal

  int r = sz(grid);
  int c = sz(grid[0]);

  int dx[] = {-1,0,1,0};
  int dy[] = {0,1,0,-1};

  auto valid = [&](int x, int y) { return 0 <= x && x < r && 0 <= y && y < c; };

  vector<vector<pii>> dad(r,vector<pii>(c,pii(-1,-1)));
  deque<pii> q;
  q.emplace_front(start);
  dad[start.first][start.second] = pii(-2,-2);

  while(sz(q)) {
    auto [x,y] = q.front();
    q.pop_front();
    rep(d,0,4) {
      int nx = x + dx[d], ny = y + dy[d];
      if(!valid(nx,ny)) continue;
      if(dad[nx][ny] != pii(-1,-1)) continue;
      dad[nx][ny] = pii(x,y);
      if(grid[nx][ny] == '#') q.emplace_back(nx,ny);
      else q.emplace_front(nx,ny);
    }
  }

  auto [x,y] = goal;
  assert(dad[x][y] != pii(-1,-1));
  while(pii(x,y) != start) {
      if(grid[x][y] == '#') grid[x][y] = '.';
      tie(x,y) = dad[x][y];
  }
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  string type = opt("type");
  int r = opt<int>("r");
  int c = opt<int>("c");
  int k = opt<int>("k");
  assert(r*c >= 2);

  vector<string> grid;

  if(type == "empty") grid = gen_random(r,c, 0);
  if(type == "random") grid = gen_random(r,c, opt<float>("wallfrac"));
  if(type == "layers") grid = gen_layers(r,c, opt<int>("holes"));

  // put start and goal quite far apart from eachother
  int far = rnd.next(2,15);
  pii start = { rnd.wnext(r,far), rnd.wnext(c,far) };
  pii goal = { r-1-rnd.wnext(r,far), c-1-rnd.wnext(c,far) };
  while(start == goal) goal = { r-1-rnd.wnext(r,far), c-1-rnd.wnext(c,far) };
  if(type == "layers") start.second = 0, goal.second = c-1;

  grid[start.first][start.second] = 'S';
  grid[goal.first][goal.second] = 'G';

  // make sure the grid is solvable
  force_possible(grid, start, goal);

  // maybe mirror the grid
  if(rnd.next(2)) reverse(all(grid));
  if(rnd.next(2)) rep(i,0,r) reverse(all(grid));

  cout << r << " " << c << " " <<  k << endl;
  rep(i,0,r) cout << grid[i] << "\n";
}
