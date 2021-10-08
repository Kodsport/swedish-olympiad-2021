#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(ll i = a; i<ll(b);i++)
#define rrep(i,a,b) for(ll i = b-1; i>=ll(a);i--)
#define trav(x,s) for(auto &x: s)
#define all(v) v.begin(),v.end()
#define sz(v) ll(v.size())

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;

ll n,b,W;
vi c;
vi e;
vi w;

bool test(double f){
    vector<vector<double>> dp(n+1,vector<double>(b+1));
    vector<vector<pii>> p(n+1,vector<pii>(b+1));

    

    rep(i,0,n){
        rep(j,0,b+1){
            dp[i+1][j] = dp[i][j];
            p[i+1][j] = {i,j};
            if(j>=c[i]){
                double x = dp[i][j-c[i]]+e[i]-f*w[i];
                if(x>dp[i][j]){
                    p[i+1][j] = {i,j-c[i]};
                    dp[i+1][j] = x;
                }
            }
        }
    }

    /*pii a = {n,b};
    ll q = 0;
    while(a != make_pair(0ll,0ll)){
        q+=a.second !=p[a.first][a.second].second;
        a = p[a.first][a.second];
    }
    cout<<q<<endl;*/

    return dp[n][b]>W*f;
}

int main(){
    cin>>n>>b>>W;
    c.resize(n);
    e.resize(n);
    w.resize(n);

    rep(i,0,n){
        cin>>e[i]>>w[i]>>c[i];
    }

    double l = 0;
    double r = 1e9;
    while(l+1e-4<r){
        double mid = (l+r)/2;
        if(test(mid)) l = mid;
        else r = mid;
    }
    cout<<fixed<<setprecision(18)<<(l+r)/2<<endl;
}
