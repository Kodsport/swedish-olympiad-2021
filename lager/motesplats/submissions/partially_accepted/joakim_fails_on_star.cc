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
        if(_queries.count(v)) return _queries[v];

        cout << "? " << v[0]+1 << " " << v[1]+1 << " " << v[2]+1 << endl;
        int x;
        cin >> x;
        return _queries[v] = x-1;
    };
    auto answer = [&](int a) {
        cout << "! " << a+1 << endl;
        cerr << "used " << sz(_queries) << " queries" << endl;

        //ofstream o;
        //o.open("/tmp/motesplats", ios::out | ios::app);
        //o << "used " << sz(_queries) << " queries" << endl;
        //o.close();

        exit(0);
    };

    vi alive, weight(n,1);
    rep(i,0,n) alive.emplace_back(i);

    auto find_heavy_subtree = [&](int x) { // vote majority algorithm
        int majority = x;
        int cnt = 0;
        for(int y : alive) if(y != x) {
            int up = query(x,y,majority);
            if(up != x) { // (y, majority) are in the same subtree
                cnt += weight[y];
            }
            else { // (y, majority) are in different subtrees
                cnt -= weight[y];
                if(cnt < 0) {
                    cnt = -cnt;
                    majority = y;
                }
            }
        }
        return majority;
    };

    auto rnd = [&]() { return alive[uid(0,sz(alive))]; };
    auto compress = [&]() {
        int x = rnd(); // BUG: bad pivot
        int y = find_heavy_subtree(x);

        vi new_alive = {x};
        for(int z : alive) if(z != x) {
            int up = query(x,y,z);
            if(up != x) new_alive.push_back(z);
            else weight[x] += weight[z];
        }
        alive = move(new_alive);
        if(2*weight[x] >= n) answer(x);
    };

    while(true) compress();

}
