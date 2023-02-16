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

vi moves;
void move(vi &x, ll a, ll d){
    moves.push_back(a);
    trav(xi,x){
        if(a<=xi && xi<=a+d-1){
            xi = a+d-1-(xi-a);
        }
    }
}

void movesteps(vi &x, ll xi, ll s, ll d){
    if(s==0) return;
    if(s%2!=d%2) move(x, xi+(s+1)/2-d/2,d); 
    if(s%2==0 && d%2==0){
        movesteps(x,xi,s-1,d);
        movesteps(x,xi+s-1,1,d);
    }
}

void solve(ll l, vi x, ll d, ll n){
    moves.clear();
    vi res;
    rep(p,l,l+n){
        rep(i,0,x.size()){
            ll stepsup = (p+(d-1)*1000000-x[i])%(d-1);
            if(stepsup%2==1 && d%2==1) continue;
            move(x, x[i],d);
            movesteps(x,x[i],stepsup,d);
            while(x[i]>p) move(x, x[i]-d+1,d);
            res.push_back(x[i]);
            x.erase(x.begin()+i);
            break;
        }
    }
    sort(all(res));
    rep(i,0,n-1) if(res[i]+1!=res[i+1]) return;
    cout<<sz(moves)<<endl;
    trav(ai,moves) cout<<ai<<endl;
    exit(0);
}

int main(){
    ll n,d;
    cin>>n>>d;
    vi x(n);
    rep(i,0,n) cin>>x[i];

    solve(-300,x,d,n);
    solve(-301,x,d,n);
    cout<<-1<<endl;
}