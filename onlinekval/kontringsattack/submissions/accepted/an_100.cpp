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

    vector<int> filip; 
    vector<int> maria; 
    vector<int> both; 
    rep(i, 0, n){
        int x, y; 
        cin >> x >> y; 
        if (x > y){
            filip.push_back(x-y);
            both.push_back(x-y); 
        }
        else if (x < y){
            maria.push_back(y-x); 
            both.push_back(y-x); 
        }
    }

    both.emplace_back(0);

    sort(all(filip)); 
    sort(all(maria)); 
    sort(all(both)); 

    int maria_index = 0; 
    int filip_index = 0; 
    int mx = INT_MIN; 
    int best_index = 0; 
    rep(i, 0, sz(both)){
        while (maria_index < sz(maria)){
            if (maria[maria_index] <= both[i]) maria_index++; 
            else break;
        }
        while (filip_index < sz(filip)){
            if (filip[filip_index] <= both[i]) filip_index++; 
            else break; 
        }
        int filip_wins = sz(filip)-filip_index; 
        int maria_wins = sz(maria)-maria_index; 
        int wins = filip_wins-maria_wins; 
        if (wins > mx){
            mx = wins; 
            best_index = both[i]; 
        }
    }
    cout << best_index << endl;
}
