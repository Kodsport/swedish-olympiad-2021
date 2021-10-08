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

ll DP2[MAXN][MAXN] = {0};
void dp2(){
    vl AB;
    for(int i = n-1; i >= 0; i--){
        int i2 = ind[i];
        vl CS = {0};
        int better = 0;
        for(int j = 0; j < sz(AB); j++){
            CS.push_back(CS[j]+AB[j]);
            if(AB[j] > A[i2])better++;
        }

        for(int space = 0; space < n; space++){
            DP2[i][space] = -big*big;
            ll need = n-space-1;
            ll ans = A[i2] + B[i2];
            if(C[i2]-1 + n-1-i < need){
                ans = -big*big;
            }
            else{
                if(need <= better){
                    ans += CS[need];
                }
                else{
                    ans += CS[better];
                    need -= better;
                    if(need <= C[i2]-1){
                        ans += need*A[i2];
                    }
                    else{
                        ans += (C[i2]-1)*A[i2];
                        need -= C[i2]-1;
                        ans += CS[need+better] - CS[better];
                    }
                }
            }
            DP2[i][space] = ans;
        }

        ll last = A[i2] + B[i2];
        for(int j = 0; j < sz(AB); j++){
            if(AB[j] < last){
                ll temp = last;
                last = AB[j];
                AB[j] = temp;
            }
        }
        AB.push_back(last);

    }
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
                if(space + C[i2] <= n)DP[i][space] = max(DP[i][space], A[i2]*C[i2] + B[i2] + DP[i+1][space+C[i2]]);
                DP[i][space] = max(DP[i][space], DP2[i][space]);
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
    dp2();
    dp();
    cout << DP[0][0] << "\n";


    return 0;
}
