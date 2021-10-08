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

const int MAXB = 200001;
const ll big = 1000000007;
ll n, B, W;
vl energy, weight, cost;
double DP[MAXB][2] = {0};

bool test(double x){
    rep(c1,0,B+1){
        DP[c1][0] = -(c1 != 0)*big*big;
        DP[c1][1] = -(c1 != 0)*big*big;
    }
    rep(i,0,n){
        double y = energy[i] - x * weight[i];
        rep(b,0,B+1){
            DP[b][i%2] = DP[b][(i+1)%2];
            if(b >= cost[i])DP[b][i%2] = max(DP[b][(i+1)%2], y + DP[b-cost[i]][(i+1)%2]);
        }
    }
    rep(b,0,B+1){
        if(DP[b][(n+1)%2] >= x*W)return 1;
    }
    return 0;
}

int main() {
    cin >> n >> B >> W;
    rep(c1,0,n){
        ll e,w,c;
        cin >> e >> w >> c;
        energy.push_back(e);
        weight.push_back(w);
        cost.push_back(c);
    }
    double L = 0.0;
    double R = big*big;
    rep(_,0,200){
        double mid = (L+R)/2.0;
        if(test(mid)){
            L = mid;
        }
        else{
            R = mid;
        }
    }
    cout << setprecision(18) << L << "\n";
    return 0;
}
