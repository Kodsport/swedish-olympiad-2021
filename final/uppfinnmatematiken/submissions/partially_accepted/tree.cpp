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
vi ts,vs;
double scorenode(ll u){
    if(ts[u]>tLeft) return -1e18;
    if(ts[u]==0) return 1e18;
    return double(vs[u])/ts[u];
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

    ll x = max(1ll,n*n/10000000);
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
            pq.emplace(scorenode(i),i);
        }
        rep(_,0,x){
            if(sz(pq)==0 || pq.top().first<0) {stop=true; break;}
            ll u = pq.top().second;
            pq.pop();
            if(done[u]) continue;
            takenode(u);
        }
    }
    sort(all(ans));
    while(tLeft<0){
        tLeft += t[ans.back()];
        ans.pop_back();
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
    cout<<ans.size()<<endl;
    trav(ai, ans) cout<<ai<<" ";
    cout<<endl;
    cerr << C << ": " << score << "\n";
    return 0;
}
