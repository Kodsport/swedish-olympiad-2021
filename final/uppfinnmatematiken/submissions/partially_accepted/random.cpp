#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef vector<ll> vi;

ll C,n,T;
vi v,t;
vector<vi> a;

vi ans;
ll score = 0;

void solve(){
    vector<bool> done(n);
    ll totT = 0;
    rep(i,0,100000){
        ll j = rand()%n;
        if(done[j]) continue;
        bool ready = true;
        trav(ai,a[j]) ready &= done[ai];
        if(!ready) continue;
        if(totT+t[j]>T) continue;
        totT += t[j];
        score += v[j];
        ans.push_back(j);
        done[j] = true;
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
