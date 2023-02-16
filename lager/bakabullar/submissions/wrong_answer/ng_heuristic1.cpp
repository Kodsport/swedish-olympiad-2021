#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

vi ANS, X;
int n,d;
const int MOVES = 100000;

void make_move(int L){
    rep(c1,0,n){
        if(X[c1] >= L && X[c1] <= L + d - 1)X[c1] = L + d - 1 - (X[c1] - L);
    }
}

int main() {

    cin >> n >> d;
    rep(c1,0,n){
        int x;
        cin >> x;
        X.push_back(x);
    }
    sort(all(X));
    rep(c1,0,MOVES){
        vi moves;
        int ma = 12392391;
        int lo = X[0];
        int hi = X[n-1]+1;
        rep(x, lo, hi){
            make_move(x);
            sort(all(X));
            int dx = X[n-1] - X[0];
            if(dx < ma){
                ma = dx;
                moves.clear();
            }
            if(dx == ma){
                moves.push_back(x);
            }
            make_move(x);
        }
        int choose = moves[rand()%sz(moves)];
        make_move(choose);
        sort(all(X));
        ANS.push_back(choose);
        if(X[n-1] - X[0] == n-1)break;
    }
    if(sz(ANS) == MOVES){
        cout << "-1\n";
    }
    else{
        cout << sz(ANS) << "\n";
        trav(y, ANS){
            cout << y << "\n";
        }
    }

    return 0;
}
