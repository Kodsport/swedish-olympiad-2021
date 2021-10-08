// @EXPECTED_GRADES@ TLE AC TLE

#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define trav(a,c) for(auto a: c)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

vector<bool> nut;
vector<vi> e;
vi p;

void rec(ll v, ll l){
    p[v] = l;
    trav(u,e[v]){
        if(u==l) continue;
        rec(u,v);
    }
}


int main(){
    cin.sync_with_stdio(false);
    ll n,k; cin>>n>>k;
    nut.resize(n);
    e.resize(n);
    p.resize(n);
    rep(i,0,k){
        ll v;
        cin>>v;
        nut[v-1] = true;
    }
    rep(i,0,n-1){
        ll a,b;
        cin>>a>>b;
        e[a-1].push_back(b-1);
        e[b-1].push_back(a-1);
    }
    rec(0,0);
    vector<bool> c(n);
    rep(i,0,n){
        if(nut[i]){
            ll v =i;
            while(v!=0){
                c[v] = true;
                v = p[v];
            }
        }
    }
    c[0]=false;
    ll ans = 0;
    rep(i,0,n) ans += 2*c[i];
    cout<<ans<<endl;
}

