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
    int n,k;
    cin>>n>>k;
    vi v(n);
    multiset<pii> low;
    rep(i,0,n) {
        cin>>v[i];
        low.insert({v[i],i});
        if(sz(low) > k) low.erase(--end(low));
    }
    assert(sz(low) == k);

    int ans = 0;
    int mn = 1e9, mx = -1e9;
    for(auto [x,y] : low) {
        ans += x;
        mn = min(mn, y);
        mx = max(mx, y);
    }
    assert(mn != 1e9 && mx != -1e9);
    ans += mx - mn;
    cout << ans << endl;
}
