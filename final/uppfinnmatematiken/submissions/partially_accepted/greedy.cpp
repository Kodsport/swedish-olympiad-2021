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

vi ans;
ll score = 0;

void solve(){
    vector<vi> outed(n);
    vi indeg(n);
    rep(i,0,n){
        trav(ai,a[i]) outed[ai].push_back(i);
        indeg[i] = sz(a[i]);
    }
    priority_queue<pair<double,ll>> pq;
    rep(i,0,n){
        if(indeg[i]==0)
            pq.emplace(double(v[i])/double(t[i]), i);
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
                pq.emplace(double(v[oi])/double(t[oi]), oi);
        }
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
    solve();
    cout<<ans.size()<<endl;
    trav(ai, ans) cout<<ai<<" ";
    cout<<endl;
    cerr << C << ": " << score << "\n";
    return 0;
}
