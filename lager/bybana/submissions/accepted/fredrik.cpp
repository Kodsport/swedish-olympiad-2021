#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(ll i = a; i<ll(b);i++)
#define rrep(i,a,b) for(ll i = b-1; i>=ll(a);i--)
#define trav(x,s) for(auto &x: s)
#define all(v) v.begin(),v.end()
#define sz(v) ll(v.size())

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main(){
    ll n,l;
    cin>>n>>l;
    vector<vector<pii>> e(n);
    rep(i,0,l){
        ll m;
        cin>>m;
        vi li(m);
        rep(i,0,m) {
            cin>>li[i];
            --li[i];
        }
        rep(i,0,m){
            e[li[0]].emplace_back(li[i],m-i-1);
            e[li[i]].emplace_back(li[0],m-i-1);
            e[li.back()].emplace_back(li[i],i);
            e[li[i]].emplace_back(li.back(),i);
        }
    }

    set<tuple<ll,ll,ll>> q;
    q.emplace(0,0,0);
    vi dist(n,1e18);
    vi count(n,-1);
    while(q.size()){
        auto [d,v,c] = *q.begin();
        q.erase(q.begin());
        if(dist[v]<=d) continue;
        dist[v] = d;
        count[v] = c;
        trav(u,e[v]){
            q.emplace(u.second+d,u.first,c+1);
        }
    }
    cerr<<count[n-1]<<" / "<<l<<endl;
    cout<<dist[n-1]<<endl;
}