#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;

int n;
int score[1000001] = {0};

int main() {
    cin >> n;
    int tot = 0;
    rep(c1,0,n){
        int a,b;
        cin >> a >> b;
        score[abs(a-b)] += (a>b) - (a<b);
        tot += (a>b) - (a<b);
    }
    int ans = 0;
    int best = -10000000;
    rep(c1,0,1000001){
        tot -= score[c1];
        if(tot > best){
            best = tot;
            ans = c1;
        }
    }
    cout << ans << "\n";
    return 0;
}
