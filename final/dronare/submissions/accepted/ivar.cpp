#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(ll i = a; i<ll(b);++i)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define trav(a,c) for(auto a: c)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

ll n, b, w0;

vector<tuple<ll, ll, ll>> drones;
double guessed_length;

// Maximerar uttrycket energy - guessed_length * battery_weights. Om detta är mindre än 
// w0 * guessed_length så är denna längd omöjlig att uppnå.  

vector<vector<double>> mem;
double max_possible(ll ind, ll money) {
    
    if (ind == n) return 0;
    if (mem[ind][money] > -1) return mem[ind][money];

    ll ne, nw, nc;
    tie(ne, nw, nc) = drones[ind];
    // Köp inte batteriet
    mem[ind][money] = max_possible(ind+1, money);
    // Köp batteriet (om möjligt) och ta max av dessa
    if (money >= nc)
        mem[ind][money] = max(
            mem[ind][money], 
            max_possible(ind+1, money-nc) + (double)ne - (double)nw*guessed_length);
    
    return mem[ind][money];
}



int main() {
    cin >> n >> b >> w0;
    // Kom ihåg att budgeten innehåller b! alltså är andra längden på inre vektorn b+1
    mem.assign(n, vector<double>(b+1, -2.0));
    ll e, w, c;
    rep(i,0,n) {
        cin >> e >> w >> c;
        drones.emplace_back(e, w, c);    
    }

    // Eftersom längd = (energi / vikt) < (energi / w0) < (energi) < (100000 * 1000000)
    double l = 0.0, h = 1000000000000000.0;
    while (h - l > 1e-7) {
        double m = (h + l) * 0.5;
        guessed_length = m;
        
        mem.assign(n, vector<double>(b+1, -2.0));
        
        if (max_possible(0, b) < w0 * guessed_length)
            h = m;
        else l = m;
    }
    cout << setprecision(20);
    cout << l << endl;
}