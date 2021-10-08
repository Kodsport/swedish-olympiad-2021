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

ll swapsSort(vi a){
    ll ans = 0;
    rep(_,0,sz(a)) rep(i,0,sz(a)-1){
        if(a[i]>a[i+1]){
            swap(a[i],a[i+1]);
            ans++;
        }
    }
    return ans;
}

vector<pii> makeUnique(vi a){
    map<ll,ll> m;
    vector<pii> b;
    trav(ai,a) b.emplace_back(ai,m[ai]++);
    return b;
}

ll swapsReorder(vi a, vi b){
    vector<pii> ap = makeUnique(a);
    vector<pii> bp = makeUnique(b);
    map<pii, ll> m;
    ll c = 0;
    trav(bi,bp) m[bi] = c++;
    vi toSort;
    trav(ai,ap) toSort.emplace_back(m[ai]);
    return swapsSort(toSort);
}

int main(){
    ll n,k;
    cin>>n>>k;
    k++;
    vi a(n);
    trav(ai,a) cin>>ai;
    vi p = a;
    ll ans = 1e18;
    sort(all(p));
    do {
        bool sym = true;
        rep(i,0,n) sym &= (p[i]==p[n-1-i]);
        if(sym) ans = min(ans, swapsReorder(a,p));
    } while(next_permutation(all(p)));
    cout<<ans<<endl;
}