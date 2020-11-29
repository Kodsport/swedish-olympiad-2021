#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void answer(vi ans) {
    assert(sz(ans));
    cout << sz(ans) << endl;
    for(int i : ans) cout << i+1 << " ";
    cout << endl;
    exit(0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n,m,k;
    cin>>n>>m>>k;
    vector<vi> g(n);
    rep(i,0,m) {
        int x,y;
        cin>>x>>y;
        --x,--y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<vi> comps(n);
    vi cmp_idx(n);
    vi degs(n,0); // number of "large" neighbors to this comp
    vi bad_siz(n,0); // number of "large" inside this comp
    rep(i,0,n) {
        comps[i] = {i};
        cmp_idx[i] = i;
    }

    set<pii> pq; // {bad_siz, id}
    auto rem = [&](int x) {
        x = cmp_idx[x];
        pq.erase(pii(bad_siz[x], x));
    };
    auto add = [&](int x) {
        x = cmp_idx[x];
        if(degs[x] == 0) pq.emplace(bad_siz[x], x);
    };

    auto join = [&](int x, int y) { // union find
        x = cmp_idx[x], y = cmp_idx[y];
        if(x == y) return;
        if(sz(comps[x]) < sz(comps[y])) swap(x,y);
        degs[x] += degs[y];
        bad_siz[x] += bad_siz[y];
        for(auto z : comps[y]) {
            cmp_idx[z] = x;
            comps[x].push_back(y);
        }
    };

    rep(i,0,n) add(i);
    for(int x = n; x--;) {
        rem(x); for(auto y : g[x]) rem(y);

        // make x "large"
        ++bad_siz[cmp_idx[x]];
        for(auto y : g[x]) ++degs[cmp_idx[y]];
        for(auto y : g[x]) if(y > x) {
            join(x,y);
            degs[cmp_idx[y]] -= 2;
        }

        add(x); for(auto y : g[x]) add(y);

        auto [siz,id] = *pq.begin();
        if(siz <= n-k-x) // ok if at most n-k-x "large" elements
            answer(comps[id]);
    }

    cout << -1 << endl;
}
