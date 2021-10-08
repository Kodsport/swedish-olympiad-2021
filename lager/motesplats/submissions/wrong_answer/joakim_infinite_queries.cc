#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<>(a,b-1)(rng) // [a,b)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, q;
    cin>>n>>q;

    map<vi, int> _queries;
    auto query = [&](int a, int b, int c) {
        vi v = {a,b,c};
        sort(all(v));
        if(v[0] == v[1] || v[1] == v[2]) return v[1];

        cout << "? " << v[0]+1 << " " << v[1]+1 << " " << v[2]+1 << endl;
        int x;
        cin >> x;
        return _queries[v] = x-1;
    };

    auto rnd = [&]() { return uid(0,n); };
    while(true) query(rnd(),rnd(),rnd());
}
