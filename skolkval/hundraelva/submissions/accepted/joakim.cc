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
    ll n, ans = 0;
    cin>>n;
    while(n) {
        ll k = 1;
        while(k*10+1 <= n) k = k*10+1;
        ++ans;
        n -= k;
    }
    cout << ans << endl;
}
