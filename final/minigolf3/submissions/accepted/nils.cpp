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

int r,c,k;
vector<set<pii> > rows, cols;
vi row_ind, col_ind;
set<int> blocked;
int start, goal;
int dist[1000001] = {0};
bool mark[1000001] = {0};
queue<int> Q;

void add_to_queue(int i, int x, set<pii> &S){
    auto it = S.lower_bound({x, i});

    vector<pii> news;

    while(it != S.end()){
        pii p = *it;
        if(abs(p.first - x) > k)break;
        if(dist[p.second] == -1)dist[p.second] = 1 + dist[i];
        news.push_back(p);
        it++;
    }

    it = S.lower_bound({x, i});
    while(it != S.begin()){
        it--;
        pii p = *it;
        if(abs(p.first - x) > k)break;
        if(dist[p.second] == -1)dist[p.second] = 1 + dist[i];
        news.push_back(p);
    }

    trav(p, news){
        Q.push(p.second);
        S.erase(p);
    }
}

void process(int i){
    if(mark[i])return;
    mark[i] = 1;
    add_to_queue(i, i%c, rows[row_ind[i]]);
    add_to_queue(i, i/c, cols[col_ind[i]]);
    rows[row_ind[i]].erase({i%c, i});
    cols[col_ind[i]].erase({i/c, i});
}

int main() {
    cin >> r >> c >> k;
    rep(c1,0,r){
        string s;
        cin >> s;
        rep(c2,0,c){
            dist[c1*c+c2] = -1;
            row_ind.push_back(-1);
            col_ind.push_back(-1);
            if(s[c2] == '#'){
                blocked.insert(c1*c+c2);
            }
            if(s[c2] == 'S'){
                start = c1*c+c2;
            }
            if(s[c2] == 'G'){
                goal = c1*c+c2;
            }
        }
    }
    rep(c1,0,r){
        set<pii> temp;
        rows.push_back(temp);
        rep(c2,0,c){
            int i = c1*c+c2;
            if(blocked.find(i) != blocked.end()){
                if(sz(rows.back()) > 0){
                    set<pii> temp;
                    rows.push_back(temp);
                }
            }
            else{
                rows.back().insert({c2,i});
                row_ind[i] = sz(rows)-1;
            }
        }
    }
    rep(c2,0,c){
        set<pii> temp;
        cols.push_back(temp);
        rep(c1,0,r){
            int i = c1*c+c2;
            if(blocked.find(i) != blocked.end()){
                if(sz(cols.back()) > 0){
                    set<pii> temp;
                    cols.push_back(temp);
                }
            }
            else{
                cols.back().insert({c1,i});
                col_ind[i] = sz(cols)-1;
            }
        }
    }

    dist[start] = 0;
    Q.push(start);
    while(!Q.empty()){
        int i = Q.front();
        Q.pop();
        process(i);
    }
    cout << dist[goal] << "\n";
    return 0;
}
