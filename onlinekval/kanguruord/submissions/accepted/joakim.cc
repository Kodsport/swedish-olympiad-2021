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
    string s;
    cin>>s;
    int n;
    cin>>n;

    string rs = s;
    reverse(all(rs));

    auto get_pos = [&](string s) {
        vector<vi> pos(30);
        rep(i,0,sz(s)) pos[s[i]-'a'].push_back(i); 
        return pos;
    };
    auto pos = get_pos(s);
    auto rpos = get_pos(rs);

    auto get_idx = [&](string& k, auto& pos) -> vi {
        vi fnd;
        int cur = -1;
        rep(i,0,sz(k)) {
            auto &p = pos[k[i]-'a'];
            auto it = upper_bound(all(p), cur);
            if(it == end(p)) return {};
            cur = *it;
            fnd.push_back(cur);
        }
        return fnd;
    };

    int ans = 0;
    rep(i,0,n) {
        string k;
        cin>>k;
        string rk = k;
        reverse(all(rk));
        auto a = get_idx(k, pos);
        auto b = get_idx(rk, rpos);
        assert((sz(a)==0) == (sz(b)==0));
        reverse(all(b));
        rep(i,0,sz(b)) b[i] = sz(s)-b[i]-1;
        if(sz(a) && a != b) ++ans;
    }

    cout << ans << endl;
}
