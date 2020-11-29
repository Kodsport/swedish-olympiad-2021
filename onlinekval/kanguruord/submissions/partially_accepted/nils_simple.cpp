#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;

const int MAXN = 100001;
int n,q;
string s;
int nex[MAXN][26] = {0};

bool solve(string &t){
    int a = 0;
    for(int c1 = 0; c1 < sz(t); c1++){
        if(nex[a][t[c1]-'a'] == n)return 0;
        a = nex[a][t[c1]-'a']+1;
    }
    return 1;
}

int main() {
    cin >> s;
    n = sz(s);
    for(int c1 = 0; c1 < 26; c1++){
        nex[n][c1] = n;
    }
    for(int c1 = n-1; c1 >= 0; c1--){
        for(int c2 = 0; c2 < 26; c2++){
            nex[c1][c2] = nex[c1+1][c2];
        }
        nex[c1][s[c1]-'a'] = c1;
    }
    cin >> q;
    int ans = 0;
    for(int c1 = 0; c1 < q; c1++){
        string t;
        cin >> t;
        if(solve(t))ans++;
    }
    cout << ans << "\n";

    return 0;
}
