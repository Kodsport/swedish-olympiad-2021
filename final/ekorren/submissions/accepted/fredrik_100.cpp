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

ll rec(ll v, ll l){
    ll ans = 0;
    trav(u,e[v]){
        if(u==l) continue;
        ans += rec(u,v);
    }
    if(ans==0 && !nut[v]) return 0;
    return ans+2;
}

vector<bool> seen;
void dfs(ll v){
    if(seen[v]) return;
    seen[v] = true;
    trav(u,e[v]) dfs(u);
}

int main(){
    cin.sync_with_stdio(false);
    ll n,k; cin>>n>>k;
    nut.resize(n);
    e.resize(n);
    seen.resize(n);
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
    /*dfs(0);
    rep(i,0,n) {
        if(!seen[i]) {
            cout<<i<<": ";
            trav(u,e[i]) cout<<u<<" ";
            cout<<endl;
        }
    }*/
    cout<<rec(0,-1)-2<<endl;
}

