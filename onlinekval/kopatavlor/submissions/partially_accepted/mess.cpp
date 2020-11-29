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
ll n,k;

ll intervalScore(ll l, ll r){
    if(r>=n) return 1e18;
    if(r-l+1<k) return 1e18;
    vi b;
    rep(i,l,r+1) b.push_back(a[i]);
    sort(all(b));
    ll ans = r-l;
    rep(i,0,k) ans += b[i];
    return ans; 
}

int main(){
    cin.sync_with_stdio(false);
    cin>>n>>k;
    a.resize(n);
    rep(i,0,n) cin>>a[i];

    vector<vi> dp(n,vi(k+1,1e18));

    ll ans = 1e18;

    ll sq = sqrt(n)+10;

    rep(i,0,sq) rep(j,n-sq,n) ans = min(ans,intervalScore(i,j));

    ll l = 0;
    ll r = 0;
    while(l<n){
        ll currScore = intervalScore(l,r+1);
        ans = min(ans,currScore);
        if(currScore>intervalScore(l,r)){
            r++;
        } else{
            l++;
        }
    }

    vector<pii> s;
    rep(i,0,n) s.emplace_back(a[i],i);
    sort(all(s));
    ll mn = 1e18;
    ll mx = 0;
    ll sum = 0;
    rep(i,0,k){
        mn = min(mn,s[i].second);
        mx = max(mx,s[i].first);
        sum += s[i].first;
    }
    ans = min(ans,sum);

    cout<<ans<<endl;
}

