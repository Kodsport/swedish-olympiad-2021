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
    string s;
    cin>>n>>s;
    assert(sz(s) == n);
    int ans = n+1;
    rep(i,0,n) if(s[i] == '.') {
        rep(j,i+1,n) if(s[j] == '.') {
            ans = min(ans,  j-i-1);
        }
    }
    cout << ans << endl;
}

