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

int n,m;
const int lim = 499999;
const int MAXN = 25000;
int score[MAXN] = {0};

int ask(int a, int b, int c){
    cout << "? " << a+1 << " " << b+1 << " " << c+1 << "\n";
    fflush(stdout);
    int res;
    cin >> res;
    return res-1;
}

bool comp(int i, int j){
    return score[i] > score[j];
}

vi ind, ind_rand;
int upd[MAXN] = {0};
int latest = 0;

bool try_centroid(int i){
    if(upd[i] != latest)return 0;
    vector<bool> mark(n, 0);
    rep(c1,0,n){
        int j = ind_rand[c1];
        if(mark[j])continue;
        if(j != i){
            vi ST;
            ST.push_back(j);
            int subtree = 1;
            rep(c2,0,n){
                if(c2 != i && c2 != j){
                    int temp = ask(i,j,c2);
                    if(temp != i){
                        subtree++;
                        ST.push_back(c2);
                        mark[c2] = 1;
                    }
                }
            }
            if(subtree > n/2){
                latest++;
                trav(y, ST){
                    upd[y] = latest;
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    cin >> n >> m;

    for(int c1 = 0; c1 < lim/2; c1++){
        int a,b,c;
        a = rand()%n;
        b = rand()%n;
        c = rand()%n;
        while(a == b || b == c || c == a){
            a = rand()%n;
            b = rand()%n;
            c = rand()%n;
        }

        int d = ask(a,b,c);
        score[d]++;
    }

    rep(c1,0,n){
        ind.push_back(c1);
        ind_rand.push_back(c1);
    }
    sort(all(ind), comp);
    random_shuffle(all(ind_rand));
    int ans = -1;
    rep(c1,0,n){
       if(try_centroid(c1)){
            ans = c1;
            break;
       }
    }

    cout << "! " << ans+1 << "\n";
    fflush(stdout);

    return 0;
}
