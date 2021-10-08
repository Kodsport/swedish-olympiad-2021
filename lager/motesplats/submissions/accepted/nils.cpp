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
int q = 0;

int ask(int a, int b, int c){
    cout << "? " << a+1 << " " << b+1 << " " << c+1 << "\n";
    q++;
    assert(q <= lim);
    fflush(stdout);
    int res;
    cin >> res;
    return res-1;
}

int bad[MAXN] = {0};


bool solve(){

    if(q > lim/2){
        int most_bad = 0;
        int how_bad = 0;
        rep(c1,0,n){
            if(bad[c1] > how_bad){
                how_bad = bad[c1];
                most_bad = c1;
            }
        }
        cout << "! " << most_bad+1 << "\n";
        return 1;
    }

    int i = rand()%n;
    int j = rand()%n;
    while(i == j){
        i = rand()%n;
        j = rand()%n;
    }
    vi sub(n, 0);
    sub[i]++;
    sub[j]++;
    vi path;
    path.push_back(i);
    path.push_back(j);
    rep(c1,0,n){
        if(c1 != i && c1 != j){
            int a = ask(i,j,c1);
            sub[a]++;
            if(sub[a] > (n+1)/2){
                bad[a]++;
                return 0;
            }
            if(a == c1)path.push_back(a);
        }
    }

    if(n-sub[i] < (n+1)/2){
        cout << "! " << i+1 << "\n";
        return 1;
    }
    if(n-sub[j] < (n+1)/2){
        cout << "! " << j+1 << "\n";
        return 1;
    }

    while(1){
        assert(sz(path) > 2);
        int r = rand()%sz(path);
        while(path[r] == i || path[r] == j){
            r = rand()%sz(path);
        }
        int k = path[r];
        int lw = sub[i];
        int rw = 0;
        vi L, R;
        L.push_back(k);
        L.push_back(i);
        R.push_back(k);
        trav(p, path){
            if(p != i && p != k){
                int d = ask(i,k,p);
                if(d == p){
                    lw += sub[p];
                    L.push_back(p);
                }
                else{
                    rw += sub[p];
                    R.push_back(p);
                }
            }
        }
        if(lw < (n+1)/2 && rw < (n+1)/2){
            cout << "! " << k+1 << "\n";
            return 1;
        }
        if(rw > lw){
            sub[k] += lw;
            path = R;
            i = k;
        }
        else{
            sub[k] += rw;
            path = L;
            j = k;
        }
    }
    assert(0);
    return 0;
}

int main() {
    cin >> n >> m;
    while(!solve()){}
    return 0;
}
