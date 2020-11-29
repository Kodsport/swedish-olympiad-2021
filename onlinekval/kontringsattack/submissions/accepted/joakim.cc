#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin>>n;
    vector<pii> v(n);
    map<ll,vi> event;
    rep(i,0,n) {
        cin>>v[i].first>>v[i].second;
        if(v[i].first != v[i].second)
            event[abs(v[i].first - v[i].second)].emplace_back(i);
    }
    ll ans = 0;
    ll delta = 0;
    for(auto [t, e] : event) {
        for(auto i : e) {
            if(v[i].first > v[i].second) ++delta;
            else --delta;
        }
        if(delta < 0) ans = t, delta = 0;
    }
    cout << ans << endl;
}
