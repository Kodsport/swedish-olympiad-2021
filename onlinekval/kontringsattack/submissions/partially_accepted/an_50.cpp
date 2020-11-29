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

    set<int> k = {0}; 
    vector<int> both; 
    rep(i, 0, n){
        int x, y; 
        cin >> x >> y; 
        both.push_back(x-y);
        if (x <= y){
            k.insert(abs(x-y));  
        }
    }

    int mx = INT_MIN; 
    int best_index = 0; 
    while (sz(k) > 0){
        auto first = k.begin(); 
        
        int wins = 0; 

        rep(i, 0, n){
            if (abs(both[i]) > *first){
                if (both[i] < 0){
                    wins--;
                }
                else if (both[i] > 0){
                    wins++; 
                }
            }
        }
        if (wins > mx){
            mx = wins; 
            best_index = *first; 
        }
        k.erase(first); 
    }
    cout << best_index << endl; 
}