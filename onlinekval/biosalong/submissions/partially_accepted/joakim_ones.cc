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
    string s;
    cin>>s;
    vi ones;
    rep(i,0,sz(s)) if(s[i] == '.') ones.push_back(i);
    int ans = n;
    for(int x : ones) for(int y : ones) if(x != y)
        ans = min(ans, abs(x-y)-1);
    cout << ans << endl;
}
