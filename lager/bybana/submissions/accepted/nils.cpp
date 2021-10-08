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

const int MAXN = 100001;
int n,m;
vector<vi> C(MAXN, vi());
vector<vl> CW(MAXN, vl());

ll dist[MAXN] = {0};
bool mark[MAXN] = {0};

void add_edge(int i, int j, int w){
    C[i].push_back(j);
    C[j].push_back(i);
    CW[i].push_back(w);
    CW[j].push_back(w);
}

void dijkstra(int start){
    rep(c1,0,n){
        dist[c1] = -1;
        mark[c1] = 0;
    }
    priority_queue<pll> pq;
    pq.push({0,start});
    dist[start] = 0;
    while(!pq.empty()){
        int a = pq.top().second;
        pq.pop();
        if(!mark[a]){
            mark[a] = 1;
            rep(c1,0,sz(C[a])){
                int b = C[a][c1];
                ll w = CW[a][c1];
                if(dist[b] == -1 || dist[b] > dist[a] + w){
                    dist[b] = dist[a]+w;
                    pq.push({-dist[b],b});
                }
            }
        }
    }
}

int main() {
    int a,b,c;
    cin >> n >> m;
    rep(c1,0,m){
        cin >> a;
        vi L;
        rep(c2,0,a){
            cin >> b;
            b--;
            L.push_back(b);
        }
        add_edge(L[0], L.back(), 0);
        rep(c2,1,a-1){
            add_edge(L[0], L[c2], a-c2-1);
            add_edge(L.back(), L[c2], c2);
        }
    }
    dijkstra(0);
    cout << dist[n-1] << "\n";
    return 0;
}
