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

void w0(){
    vector<vector<double>> dp(n+1,vector<double>(b+1));
    rep(i,0,n){
        rep(j,0,b+1){
            dp[i+1][j] = dp[i][j];
            if(j>=c[i]){
                double x = dp[i][j-c[i]]+e[i];
                if(x>dp[i][j]){
                    dp[i+1][j] = x;
                }
            }
        }
    }
    cout<<dp[n][b]/W<<endl;
    exit(0);
}

void sameprice(){
    double l = 0;
    double r = 1e18;
    while(l+1e-7<r){
        double mid = (l+r)/2;

        vector<double> batteries;
        rep(i,0,n) batteries.push_back(e[i]-mid*w[i]);
        sort(all(batteries));
        reverse(all(batteries));
        
        ll cb = b;
        double s = 0;
        rep(i,0,n){
            if(cb>=c[0] && batteries[i]>0){
                cb-=c[0];
                s += batteries[i];
            }
        }

        if(s>W*mid) l = mid;
        else r = mid;
    }
    cout<<fixed<<setprecision(18)<<(l+r)/2<<endl;
    exit(0);
}

int main(){
    cin>>n>>b>>W;

    e.resize(n);
    c.resize(n);
    w.resize(n);

    vector<tuple<double,ll,ll,ll>> batteries;

    bool weights0 = true;
    set<ll> cs;
    rep(i,0,n){
        cin>>e[i]>>w[i]>>c[i];
        cs.insert(c[i]);
        batteries.emplace_back(double(e[i])/w[i],e[i],w[i],c[i]);
        weights0 &= w[i]==0;
    }
    
    if(weights0){
        w0();
    }

    if(cs.size()==1){
        sameprice();
    }

    sort(all(batteries));
    reverse(all(batteries));

    n = min(n,23ll);
    double best = 0;
    rep(mask,0,(1<<n)){
        double totW = W;
        double totE = 0;
        ll cb = b;
        rep(i,0,n){
            auto [ign,e,w,c] = batteries[i];
            if((mask>>i) &1){
                totW += w;
                totE += e;
                cb -= c;
            }
        }
        if(cb>=0)
            best = max(best,totE/totW);
    }



    cout<<fixed<<setprecision(18)<<best<<endl;
}