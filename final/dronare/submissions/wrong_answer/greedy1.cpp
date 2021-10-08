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

ll n,b,W;
vi c;
vi e;
vi w;

int main(){
    cin>>n>>b>>W;

    vector<tuple<double,ll,ll,ll>> batteries;

    rep(i,0,n){
        ll e,w,c;
        cin>>e>>w>>c;
        batteries.emplace_back(double(e)/w,e,w,c);
    }
    
    sort(all(batteries));
    reverse(all(batteries));
    double totW = W;
    double totE = 0;

    trav(bat,batteries){
        auto [ign,e,w,c] = bat;
        if(b>=c && (totE+e)/(totW+w)>totE/totW){
            b-=c;
            totW += w;
            totE += e;
        }
    }
    cout<<fixed<<setprecision(18)<<totE/totW<<endl;
}