#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
ll C,n,T;
vi v,t;
vector<vi> a;

vector<vi> e;

vi ans;

vi ss;
vi tr;
vi trin;

ll dfs(ll u){
    trin[u] = sz(tr);
    tr.push_back(u);
    ss[u] = 1;
    trav(ei,e[u]) ss[u] += dfs(ei);
    return ss[u];
}

vector<vi> mem;

ll dp(ll u, ll tLeft){
    if(tLeft<0) return -1e18;
    if(u>=n) return 0;
    if(mem[u][tLeft]!=-1) return mem[u][tLeft];

    return mem[u][tLeft] = max(v[u]+dp(tr[trin[u]+1],tLeft-t[u]), dp(tr[trin[u]+ss[u]],tLeft));
}

void getans(ll u, ll tLeft){
    if(u>=n) return;
    if(v[u]+dp(tr[trin[u]+1],tLeft-t[u]) > dp(tr[trin[u]+ss[u]],tLeft)){
        ans.push_back(u);
        getans(tr[trin[u]+1],tLeft-t[u]);
    } else {
        getans(tr[trin[u]+ss[u]],tLeft);
    }
}

void solve(){
    ss.resize(n);
    trin.resize(n);
    dfs(0);
    tr.push_back(n);
    mem.assign(n,vi(T+1,-1));
    getans(0,T);
}

int main() {

    cin >> C >> n>>T;
    v.resize(n);
    t.resize(n);
    a.resize(n);
	rep(i,0,n){
        int k;
        cin >> t[i]>>v[i]>>k;
        a[i].resize(k);
        rep(j,0,k) cin>>a[i][j];
    }

    e.resize(n);
    rep(i,0,n){
        trav(ai,a[i]) e[ai].push_back(i);
    }

    if(C==7 || C==8)
        solve();
    sort(all(ans));
    cout<<ans.size()<<endl;
    trav(ai, ans) cout<<ai<<" ";
    cout<<endl;
    cerr << C << ": " << 0 << "\n";
    return 0;
}
