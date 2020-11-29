#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define trav(a,c) for(auto a: c)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

vi a;
ll k;

ll intervalScore(ll l, ll r){
    if(r-l+1<k) return 1e18;
    vi b;
    rep(i,l,r+1) b.push_back(a[i]);
    sort(all(b));
    ll ans = r-l;
    //cout<<sz(b)<<" "<<r-l+1<<" "<<k<<endl;
    rep(i,0,k) ans += b[i];
    return ans; 
}

int main(){
    cin.sync_with_stdio(false);
    ll n;
    cin>>n>>k;
    a.resize(n);
    rep(i,0,n) cin>>a[i];

    vector<vi> dp(n,vi(k+1,1e18));

    ll ans = 1e18;
    rep(i,0,n) rep(j,i,n) ans = min(ans,intervalScore(i,j));

    cout<<ans<<endl;
}

