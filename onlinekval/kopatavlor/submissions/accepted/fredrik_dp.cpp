#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define trav(a,c) for(auto a: c)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

int main(){
    cin.sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    vi a(n);
    rep(i,0,n) cin>>a[i];

    vector<vi> dp(n,vi(k+1,1e18));

    ll ans = 1e18;
    rep(i,0,n){
        dp[i][1] = a[i];
        rep(j,0,k+1){
            if(i>0) dp[i][j] = min(dp[i][j],1+dp[i-1][j]);
            if(i>0 && j>0) dp[i][j] = min(dp[i][j],1+a[i]+dp[i-1][j-1]);
        }
        ans = min(ans,dp[i][k]);
    }
    cout<<ans<<endl;
}

