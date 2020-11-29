#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const vi digit = {6,2,5,5,4,5,6,3,7,6};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll target;
    cin>>target;
    vi use(100);
    rep(i,0,100) use[i] = digit[i%10] + digit[i/10];

    auto at = [&](ll x) { return use[x%60] + use[x/60%60] + use[x/60/60]; };

    const ll up = 24*60*60;
    ll l = 0, r = 0, energy = 0, ans = 0;
    while(l < up) {
        while(energy < target && r < up) energy += at(r++);
        if(energy == target) ++ans;
        energy -= at(l++);
    }

    cout << ans << endl;
}
