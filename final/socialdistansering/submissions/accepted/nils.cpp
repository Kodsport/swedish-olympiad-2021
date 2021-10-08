#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef vector<ll> vl;

const ll big = 1000000000000000LL;
ll n,m,k;
vi L,R,ind;
vi L2, R2;

bool comp(ll i, ll j){
    return R[i] < R[j];
}

bool test(ll x){
    ll i = 0;
    ll last = -big-1;
    ll people = 0;
    for(ll c1 = 0; c1 < sz(L2); c1++){
        ll start = max(L2[c1], last+x);
        if(R2[c1] < start)continue;
        people += 1 + (R2[c1] - start) / x;
        last = R2[c1] - (R2[c1] - start)%x;
    }
    return (people >= n);
}

int main() {
    cin >> n >> m >> k;
    for(ll c1 = 0; c1 < m; c1++){
        ll a,b;
        cin >> a >> b;
        L.push_back(a);
        R.push_back(b);
        ind.push_back(c1);
    }
    sort(all(ind), comp);
    ll x = 0;
    for(ll c1 = 0; c1 < m; c1++){
        ll i = ind[c1];
        ll y = L[i]-1;
        if(x <= y){
            L2.push_back(x);
            R2.push_back(y);
        }
        x = R[i]+1;
    }
    if(x <= k-1){
        L2.push_back(x);
        R2.push_back(k-1);
    }
    ll l = 1;
    ll r = big;
    while(l < r-1){
        ll mid = (l+r)/2;
        if(test(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << l << "\n";
    return 0;
}
