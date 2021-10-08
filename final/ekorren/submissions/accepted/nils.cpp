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

int main() {
    int n,k;
    cin >> n >> k;
    vector<vi> C(n, vi());
    vector<bool> mark(n,0);
    vi deg(n,0);
    rep(c1,0,k){
        int a;
        cin >> a;
        mark[a-1] = 1;
    }
    rep(c1,0,n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        C[a].push_back(b);
        C[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    int edges = n-1;
    vi leaves;
    rep(c1,1,n){
        if(!mark[c1] && deg[c1] == 1){
            leaves.push_back(c1);
        }
    }
    while(!leaves.empty()){
        int a = leaves.back();
        leaves.pop_back();
        edges--;
        mark[a] = 1;
        trav(y, C[a]){
            deg[y]--;
            if(y != 0 && deg[y] == 1 && !mark[y]){
                leaves.push_back(y);
            }
        }
    }
    cout << 2*edges << "\n";

    return 0;
}
