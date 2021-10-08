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

struct DequeErase{
    deque<ll> dq;
    ll s = 0;
    vector<bool> rem;
    DequeErase(ll n){ rem.resize(n); };

    ll back(){
        while(rem[dq.back()]) dq.pop_back();
        return dq.back();
    }
    ll front(){
        while(rem[dq.front()]) dq.pop_front();
        return dq.front();
    }
    void push_back(ll v){
        dq.push_back(v);
        s++;
    }
    ll size(){return s;};
    void erase(ll v){
        s-=!rem[v];
        rem[v]=true;
    };
};

int main(){
    ll n,m;
    cin>>n>>m;

    vector<DequeErase> rows(n,DequeErase(m));
    vector<DequeErase> cols(m,DequeErase(n));
    vector<string> g(n);
    rep(i,0,n){
        cin>>g[i];
        rep(j,0,m){
            if(g[i][j]!='.'){
                rows[i].push_back(j);
                cols[j].push_back(i);
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
            if(rows[i].size()==0) continue;
            if(g[i][rows[i].front()]=='W')
                toRemove.emplace_back(i,rows[i].front());
            if(g[i][rows[i].back()]=='E')
                toRemove.emplace_back(i,rows[i].back());
        } else {
            if(cols[i].size()==0) continue;
            if(g[cols[i].front()][i]=='N')
                toRemove.emplace_back(cols[i].front(),i);
            if(g[cols[i].back()][i]=='S')
                toRemove.emplace_back(cols[i].back(),i);
        }
        trav(c,toRemove){
            ans++;
            rows[c.first].erase(c.second);
            cols[c.second].erase(c.first);
            q.emplace(c.first,0);
            q.emplace(c.second,1);
        }
    }
    cout<<ans<<endl;
}