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
    ll n; cin>>n;
    string s; cin>>s;
    ll l = -1e18;
    ll ans = 1e18;
    rep(i,0,n){
        if(s[i]=='.') {
            ans = min(ans,i-l);
            l = i;
        }
    }
    cout<<ans-1<<endl;
}

