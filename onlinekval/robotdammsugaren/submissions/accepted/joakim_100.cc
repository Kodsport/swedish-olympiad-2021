#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n,m,q;
    string commands;
    cin >> n >> m >> q >> commands;
    assert(sz(commands) == q);
    vector<string> v(n);
    rep(i,0,n) {
        cin>>v[i];
        assert(sz(v[i]) == m);
    }

    pii pos = {-1,-1};
    rep(i,0,n) rep(j,0,m)
        if(v[i][j] == 'O') {
            assert(pos == pii(-1,-1));
            v[i][j] = '.';
            pos = {i,j};
        }
    assert(pos != pii(-1,-1));


    map<char,int> dx = {{'v',1}, {'^',-1}}, dy = {{'>',1}, {'<',-1}};
    auto valid = [&](int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; };

    set<pii> used;
    map<tuple<int,int,char>,pii> nxt;
    function<pii(int,int,char)> go = [&](int x, int y, char dir) {
        used.emplace(x,y);
        if(nxt.count({x,y,dir})) return nxt[{x,y,dir}];
        int nx = x + dx[dir], ny = y + dy[dir];
        assert(valid(nx,ny));
        return nxt[{x,y,dir}] = (v[nx][ny] == '#' ? pii{x,y} : go(nx,ny,dir));
    };

    for(char dir : commands) pos = go(pos.first, pos.second, dir);

    cout << sz(used) << endl;
}
