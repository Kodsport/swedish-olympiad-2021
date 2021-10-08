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

int get_dx(){
    int mi = 100000000;
    int ma = -mi;
    rep(c1,0,n){
        mi = min(mi, X[c1]);
        ma = max(ma, X[c1]);
    }
    return ma-mi;
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
        vi moves, all_moves;
        sort(all(X));
        int ma = X[n-1] - X[0] - 1;
        int lo = X[0];
        int hi = X[n-1]+1;
        int lim = 2*n + d;
        rep(x, lo-d+1, hi){
            make_move(x);
            int dx = get_dx();
            if(dx < ma && dx > lim){
                ma = dx;
                moves.clear();
            }
            if(dx == ma && dx > lim){
                moves.push_back(x);
            }
            all_moves.push_back(x);
            make_move(x);
        }

        int choose = all_moves[rand()%sz(all_moves)];
        if(sz(moves) > 0){
            choose = moves[rand()%sz(moves)];
        }
        make_move(choose);

        //cerr << get_dx() << "/" << n-1 << "\n";

        ANS.push_back(choose);
        if(get_dx() == n-1)break;
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
