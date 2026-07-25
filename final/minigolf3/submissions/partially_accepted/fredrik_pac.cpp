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

int main(){
    ll h,w,p;
    cin>>h>>w>>p;

    vector<string> g(h);
    pii start;
    pii goal;
    rep(i,0,h) {
        cin>>g[i];
        rep(j,0,w){
            if(g[i][j]=='G') goal = {i,j};
            if(g[i][j]=='S') start = {i,j};
        }
    }

    queue<tuple<ll,ll,ll>> q;
    q.emplace(0,start.first,start.second);
    vector<vector<bool>> seen(h,vector<bool>(w));
    while(q.size()){
        ll d,r,c;
        tie(d,r,c) = q.front();
        q.pop();
        if(seen[r][c]) continue;
        seen[r][c] = true;
        if(r==goal.first&&c==goal.second){
            cout<<d<<endl;
            return 0;
        }
        vi dr = {0,1,0,-1};
        vi dc = {1,0,-1,0};
        rep(i,0,4){
            rep(j,1,p+1){
                ll r1 = r+j*dr[i];
                ll c1 = c+j*dc[i];
                if(r1<0||r1>=h||c1<0||c1>=w||g[r1][c1]=='#') break;
                q.emplace(d+1,r1,c1);
            }
        }
    }
}