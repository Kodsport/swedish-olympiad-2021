#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

struct LCA {
    int T = 0;
    vi time, path, ret, depth;
    RMQ<int> rmq;

    LCA(vector<vi>& C) : time(sz(C)), depth(sz(C)), rmq((dfs(C,0,-1), ret)) {}
    void dfs(vector<vi>& C, int v, int par) {
        time[v] = T++;
        for (int y : C[v]) if (y != par) {
            depth[y] = depth[v]+1;
            path.push_back(v), ret.push_back(time[v]);
            dfs(C, y, v);
        }
    }

    int lca(int a, int b) {
        if (a == b) return a;
        tie(a, b) = minmax(time[a], time[b]);
        return path[rmq.query(a, b)];
    }
    int dist(int a, int b){
        return depth[a] + depth[b] - 2*depth[lca(a,b)];
    }
};

int main(int argc, char **argv) {
    init_io(argc, argv);

    int n, q;
    judge_in >> n >> q;
    judge_message("n = %d, q = %d\n", n, q);

    vector<vi> g(n);
    rep(i,1,n) {
        int x, y;
        judge_in >> x >> y;
        --x, --y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    LCA lca(g);

    if(n%2 != 1) judge_error("N = %d is not odd", n);

    int ANS = -1;
    vi siz(n);
    function<void(int,int)> dfs = [&](int x, int p) {
        siz[x] = 1;
        int mx = 0;
        for(int y : g[x]) if(y != p) {
            dfs(y,x);
            siz[x] += siz[y];
            mx = max(mx, siz[y]);
        }
        mx = max(mx, n-siz[x]);
        if(2*mx <= n) {
            if(ANS != -1) judge_error("Multiple centroids (should never happen)\n");
            ANS = x;
        }
    };
    dfs(0,-1);
    if(ANS == -1) judge_error("Failed to find centroid (should never happen)\n");
    judge_message("Found centroid = %d\n", ANS+1);

    int query_count = 0;
    auto get_vertex = [&](){
        int a;
        if (!(author_out >> a))
            wrong_answer("[Query %d]: Could not read integer\n", query_count);
        if(a < 1 || a > n) 
            wrong_answer("[Query %d]: Integer %d not in range\n", query_count, a);
        return a-1;
    };

    auto process_query = [&](){
        int a = get_vertex();
        int b = get_vertex();
        int c = get_vertex();
        if(a == b || b == c || c == a)
            wrong_answer("[Query %d]: Numbers in query not distinct: %d %d %d\n", query_count, a+1, b+1, c+1);

        pii best = {1e9, -1};
        for(int x : {a, b, c, lca.lca(a,b), lca.lca(b,c), lca.lca(c,a)}) {
            int d = lca.dist(a,x) + lca.dist(b,x) + lca.dist(c,x);
            best = min(best, pii(d,x));
        }
        //judge_message("? %d %d %d -> %d\n", a+1, b+1, c+1, best.second+1);
        cout << best.second+1 << endl;
    };

    auto validate_answer = [&](){
        int x = get_vertex();
        if(x != ANS) wrong_answer("Got answer = %d, expected = %d\n", x+1, ANS+1);

        string trash;
        if (author_out >> trash) wrong_answer("Trailing output\n");

        judge_message("AC in %d queries\n", query_count);
        accept(); // Yay!
    };

    /////////// INTERACTION STARTS HERE /////////////

    cout << n << " " << q << endl;

    for(query_count = 1; query_count <= q; ++query_count) {
        char c;
        if (!(author_out >> c))
            wrong_answer("[Query %d]: Could not read query\n", query_count);
        if(c == '?') process_query();
        else if(c == '!') validate_answer();
        else {
            wrong_answer("[Query %d]: Got \'%c\', expected \'?\' or \'!\'\n", query_count, c);
        }
    }

    wrong_answer("Too many queries\n");
}
