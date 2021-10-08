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
    ll n,m;
    cin>>n>>m;

    vector<set<ll>> rows(n);
    vector<set<ll>> cols(m);
    vector<string> g(n);
    rep(i,0,n){
        cin>>g[i];
        rep(j,0,m){
            if(g[i][j]!='.'){
                rows[i].insert(j);
                cols[j].insert(i);
            }
        }
    }

    queue<pii> q;
    rep(i,0,n) q.emplace(i,0);
    rep(i,0,m) q.emplace(i,1);
    ll ans = 0;
    while(q.size()){
        ll i,t;
        tie(i,t) = q.front();
        q.pop();
        vector<pii> toRemove;
        if(t==0){ //row
            while(rows[i].size()>0&&g[i][*rows[i].begin()]=='W'){
                toRemove.emplace_back(i,*rows[i].begin());
                rows[i].erase(rows[i].begin());
            }
            while(rows[i].size()>0&&g[i][*prev(rows[i].end())]=='E'){
                toRemove.emplace_back(i,*prev(rows[i].end()));
                rows[i].erase(prev(rows[i].end()));
            }
            trav(c,toRemove){
                ans++;
                cols[c.second].erase(c.first);
                q.emplace(c.second,1);
            }
        } else {
            while(cols[i].size()>0 && g[*cols[i].begin()][i]=='N'){
                toRemove.emplace_back(*cols[i].begin(),i);
                cols[i].erase(cols[i].begin());
            }
            while(cols[i].size()>0 && g[*prev(cols[i].end())][i]=='S'){
                toRemove.emplace_back(*prev(cols[i].end()),i);
                cols[i].erase(prev(cols[i].end()));
            }
            trav(c,toRemove){
                ans++;
                rows[c.first].erase(c.second);
                q.emplace(c.first,0);
            }
        }
    }
    cout<<ans<<endl;
}