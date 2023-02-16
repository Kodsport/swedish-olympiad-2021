// @EXPECTED_GRADES@ AC WA WA

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
    int n, k;
    cin>>n>>k;
    vi nut(n), par(n);
    rep(i,0,k) {
        int a;
        cin>>a;
        --a;
        nut[a] = 1;
    }
    vector<vi> g(n);
    rep(i,1,n) {
        int a, b;
        cin >> a >> b;
        --a,--b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    function<void(int,int)> dfs = [&](int x, int p) {
        par[x] = p;
        for(int y : g[x]) if(y != p) dfs(y,x);
    };
    dfs(0,-1);

    int ans = -2;
    rep(i,0,n) if(nut[i]) {
        ans += 2;
        int x = par[i];
        while(x != -1 && !nut[x]) {
            ans += 2;
            x = par[x];
        }
    }

    cout << ans << endl;
}