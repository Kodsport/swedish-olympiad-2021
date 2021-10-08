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

double recscore(ll u, ll tLeft, ll ti,ll vi, ll depth){
    double best;
    if(ti==0) best = 1e18;
    else best = double(vi)/ti;
    if(depth>=1) return best;

    trav(ai,a[u]){
        if(ti+t[ai]<tLeft)
            best = max(best,recscore(ai,tLeft,ti+t[ai],vi+v[ai],depth+1));
    }
    return best;
}

double scorenode(ll u, ll tLeft){
    return recscore(u,tLeft,t[u],v[u],0);
}

void solveGreedy(){
    priority_queue<pair<double,ll>> pq;
    rep(i,0,n){
        if(indeg[i]==0)
            pq.emplace(scorenode(i,T), i);
    }
    vector<bool> done(n);
    ll totT = 0;
    while(pq.size()){
        ll i = pq.top().second;
        pq.pop();
        if(done[i]) continue;
        done[i] = true;
        if(t[i]+totT>T) continue;
        totT += t[i];
        score += v[i];
        ans.push_back(i);

        trav(oi,outed[i]){
            indeg[oi]--;
            if(indeg[oi]==0)
                pq.emplace(scorenode(oi,T-totT), oi);
        }
    }
}

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

void solveTopdown(){
    done.resize(n);
    tLeft = T;

    while(true){
        pair<double,ll> best = {-1e18,-1};
        rep(i,0,n) if(!done[i]) best = max(best,{scorenode(i),i});
        if(best.first<0) break;
        takenode(best.second);
    }
}


vi ts,vs;
double scorenodeTree(ll u){
    if(ts[u]>tLeft) return -1e18;
    if(ts[u]==0) return 1e18;
    return double(vs[u])/ts[u];
}
void takenodeTree(ll u){
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
void solveTree(){
    done.resize(n);
    tLeft = T;

    ll x = max(1ll,n*n/100000000);
    bool stop = false;
    while(!stop){
        priority_queue<pair<double,ll>> pq;
        ts.assign(n,0);
        vs.assign(n,0);
        pq = priority_queue<pair<double,ll>>();
        rep(i,0,n) {
            if(done[i]) continue;
            ts[i] += t[i];
            vs[i] += v[i];
            trav(ai,a[i]) {
                ts[i] += ts[ai];
                vs[i] += vs[ai];
            }
            pq.emplace(scorenodeTree(i),i);
        }
        rep(_,0,x){
            if(sz(pq)==0 || pq.top().first<0) {stop=true; break;}
            ll u = pq.top().second;
            pq.pop();
            if(done[u]) continue;
            takenodeTree(u);
        }
    }
    sort(all(ans));
    while(tLeft<0){
        tLeft += t[ans.back()];
        ans.pop_back();
    }
}


vi ss;
vi tr;
vi trin;

ll dfs(ll u){
    trin[u] = sz(tr);
    tr.push_back(u);
    ss[u] = 1;
    trav(ei,outed[u]) ss[u] += dfs(ei);
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

void solveTreedp(){
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

    outed.resize(n);
    indeg.resize(n);
    rep(i,0,n){
        trav(ai,a[i]) outed[ai].push_back(i);
        indeg[i] = sz(a[i]);
    }

    if(C==1) solveTopdown();
    if(C==2) solveTopdown();
    if(C==3) solveTopdown();
    if(C==4) solveTopdown();
    if(C==5) solveTree();
    if(C==6) solveGreedy();
    if(C==7) solveTreedp();
    if(C==8) solveTopdown();
    if(C==9) solveTree();
    if(C==10) solveTree();

    cout<<ans.size()<<endl;
    sort(all(ans));
    trav(ai, ans) cout<<ai<<" ";
    cout<<endl;
    cerr << C << ": " << score << "\n";
    return 0;
}
