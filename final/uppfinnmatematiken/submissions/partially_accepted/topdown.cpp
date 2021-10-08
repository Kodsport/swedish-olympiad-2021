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

vector<vi> outed;
vi indeg;

vi ans;
ll score = 0;

ll tLeft;
vector<bool> done;

double scorenode(ll u){
    queue<ll> q;
    q.push(u);
    vector<bool> seen(n);
    double ts = 0;
    double vs = 0;
    while(sz(q)){
        ll u = q.front();
        q.pop();
        if(seen[u]||done[u]) continue;
        seen[u] = true;
        ts += t[u];
        vs += v[u];
        trav(ai,a[u]) q.emplace(ai);
    }
    if(ts>tLeft) return -1e18;
    if(ts==0) return 1e18;
    return vs/ts;
}

void takenode(ll u){
    queue<ll> q;
    q.push(u);
    vi tmpans;
    while(sz(q)){
        ll u = q.front();
        q.pop();
        if(done[u]) continue;
        done[u] = true;
        tLeft -= t[u];
        score += v[u];
        tmpans.push_back(u);
        trav(ai,a[u]) q.emplace(ai);
    }
    reverse(all(tmpans));
    trav(ai,tmpans) ans.push_back(ai);
}

void solve(){
    done.resize(n);
    tLeft = T;

    while(true){
        pair<double,ll> best = {-1e18,-1};
        rep(i,0,n) if(!done[i]) best = max(best,{scorenode(i),i});
        if(best.first<0) break;
        takenode(best.second);
    }
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

    outed.resize(n);
    indeg.resize(n);
    rep(i,0,n){
        trav(ai,a[i]) outed[ai].push_back(i);
        indeg[i] = sz(a[i]);
    }


    solve();
    sort(all(ans));
    cout<<ans.size()<<endl;
    trav(ai, ans) cout<<ai<<" ";
    cout<<endl;
    cerr << C << ": " << score << "\n";
    return 0;
}
