#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define trav(a,c) for(auto a: c)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

pair<ll,ll> getDir(char c){
    switch(c){
        case 'v': return {1,0}; break;
        case '<': return {0,-1}; break;
        case '>': return {0,1}; break;
        case '^': return {-1,0}; break;
    }
}

int main(){
    cin.sync_with_stdio(false);
    ll r,c,n;
    cin>>r>>c>>n;
    string commands;
    cin>>commands;
    vector<string> grid(r);
    ll ri = -1;
    ll ci = -1;
    rep(i,0,r) {
        cin>>grid[i];
        rep(j,0,c)
            if(grid[i][j]=='O') {
                ri = i;
                ci = j;
            }
    }

    trav(c,commands){
        ll dr,dc;
        tie(dr,dc) = getDir(c);
        while(grid[ri+dr][ci+dc]!='#'){
            ri += dr; ci += dc;
            grid[ri][ci] = ' ';
        }
    }
    
    ll ans = 0;
    rep(i,0,r) rep(j,0,c) ans += (grid[i][j]==' ' || grid[i][j]=='O');

    //rep(i,0,r) cout<<grid[i]<<endl;

    cout<<ans<<endl;
}

