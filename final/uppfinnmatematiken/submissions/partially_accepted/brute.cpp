#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
ll C,n,T;
vi v,t;
vector<vi> a;

vector<vi> outed;
vi indeg;

vi ans;
ll score = 0;

ll getScore(vi testans){
    ll timesum = 0;
    ll score = 0;
    vector<bool> proven(n);
    rep(i,0,testans.size()) {
        trav(ai,a[testans[i]])
            if(!proven[ai])
		        return -1e18;
         
        timesum += t[testans[i]];
        score += v[testans[i]];
        proven[testans[i]] = true;
    }
	if(timesum>T){
		return -1e18;
	}
	return score;
}

void solveBrute(){
    pii best = {-1e18,-1};
    rep(mask,0,(1<<n)){
        vi testans;
        rep(i,0,n) if((mask>>i)&1) testans.push_back(i);
        best = max(best,make_pair(getScore(testans),mask));
    }
    rep(i,0,n) if((best.second>>i)&1) ans.push_back(i);
}

int main() {

    cin >> C >> n>>T;
    v.resize(n);
    t.resize(n);
    a.resize(n);
	rep(i,0,n){
        int k;
        cin >> t[i]>>v[i]>>k;
        a[i].resize(k);
        rep(j,0,k) cin>>a[i][j];
    }

    outed.resize(n);
    indeg.resize(n);
    rep(i,0,n){
        trav(ai,a[i]) outed[ai].push_back(i);
        indeg[i] = sz(a[i]);
    }

    if(n<=22){
        solveBrute();
    }
    cout<<ans.size()<<endl;
    sort(all(ans));
    trav(ai, ans) cout<<ai<<" ";
    cout<<endl;
    cerr << C << ": " << score << "\n";
    return 0;
}
