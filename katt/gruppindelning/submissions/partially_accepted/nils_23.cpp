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

const int MAXN = 4001;
const ll big = 1000000007;
int n;
vl A,B,C;
vi ind;

bool comp(int i, int j){
    return A[i] > A[j];
}

ll DP[MAXN][2*MAXN] = {0};

void dp(){
    for(int i = n; i >= 0; i--){
        for(int space = 0; space <= n; space++){
            if(i == n){
                DP[i][space] = -(space != n) * big * big;
            }
            else{
                int i2 = ind[i];
                DP[i][space] = -big*big;
                DP[i][space] = max(DP[i][space], DP[i+1][space]);
                ll extra = min(C[i2], (ll)n-space);
                DP[i][space] = max(DP[i][space], A[i2]*extra + B[i2] + DP[i+1][space+extra]);
            }
        }
    }
}

int main() {
    cin >> n;
    rep(c1,0,n){
        ll a,b,c;
        cin >> a >> b >> c;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        ind.push_back(c1);
    }
    sort(all(ind), comp);
    dp();
    cout << DP[0][0] << "\n";


    return 0;
}
