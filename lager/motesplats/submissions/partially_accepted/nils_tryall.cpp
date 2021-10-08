#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int n,m;
const int lim = 499999;
const int MAXN = 25000;
int score[MAXN] = {0};

int ask(int a, int b, int c){
    cout << "? " << a+1 << " " << b+1 << " " << c+1 << "\n";
    fflush(stdout);
    int res;
    cin >> res;
    return res-1;
}

int main() {
    cin >> n >> m;
    assert(n <= 99);
    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = c1+1; c2 < n; c2++){
            for(int c3 = c2+1; c3 < n; c3++){
                int d = ask(c1,c2,c3);
                score[d]++;
            }
        }
    }
    int ma_score = 0;
    int ans = 0;
    for(int c1 = 0; c1 < n; c1++){
        if(score[c1] > ma_score){
            ma_score = score[c1];
            ans = c1;
        }
    }
    cout << "! " << ans+1 << "\n";
    fflush(stdout);

    return 0;
}
