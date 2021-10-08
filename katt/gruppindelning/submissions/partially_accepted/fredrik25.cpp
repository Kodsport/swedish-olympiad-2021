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
    ll n; cin>>n;
    vi a(n);
    vi b(n);
    vi c(n);
    rep(i,0,n) cin>>a[i]>>b[i]>>c[i];
    
    vector<vi> dp(n+1,vi(2*n+20,-1e18));
    dp[0][n] = 0;

    rep(i,0,n){
        
        rep(e,0,2*n+10){
            dp[i+1][e] = dp[i][e+1];
            ll best = -1e18;
            rep(x,max(0ll,e-c[i]+1),e+1) best = max(best, dp[i][x]-a[i]*x);
        
            dp[i+1][e] = max(dp[i+1][e], best+a[i]*(e+1)+b[i]);
        }
    }

    cout<<dp[n][n]<<endl;
}