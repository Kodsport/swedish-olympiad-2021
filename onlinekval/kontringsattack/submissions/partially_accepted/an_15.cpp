#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define trav(a,c) for(auto a: c)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

int main(){
    cin.sync_with_stdio(0);
    int n; 
    cin >> n; 

    vector<int> both; 
    rep(i, 0, n){
        int x, y; 
        cin >> x >> y; 
        both.push_back(x-y); 
    }

    int mx = INT_MIN; 
    int best_index = 0; 
    rep(i, 0, 400){        
        int wins = 0; 

        rep(j, 0, n){
            if (abs(both[j]) > i){
                if (both[j] < 0){
                    wins--;
                }
                else if (both[j] > 0){
                    wins++; 
                }
            }
        }
        if (wins > mx){
            mx = wins; 
            best_index = i; 
        }
    }
    cout << best_index << endl; 
}