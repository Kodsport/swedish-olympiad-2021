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

    ll ans = 1e18;
    rep(i,0,n){
        multiset<ll> kSmallest;
        ll sum = 0;
        rep(j,i,n){
            kSmallest.insert(a[j]);
            sum += a[j];
            while(kSmallest.size()>k){
                sum -= *prev(kSmallest.end());
                kSmallest.erase(prev(kSmallest.end()));
            }
            if(kSmallest.size()==k){
                ans = min(ans,j-i+sum);
            }
        }
    }
    cout<<ans<<endl;
}

