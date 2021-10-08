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

const int MAXN = 200001;
const ll big = 1000000007;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};

int n,k;
vi A;
vector<vi> C(MAXN, vi());
vi B;
vi P1, P2;
ll F2[MAXN] = {0};

int main() {
    cin >> n >> k;
    rep(c1,0,n){
        int a;
        cin >> a;
        A.push_back(a);
        C[a].push_back(c1);
        B.push_back(-1);
    }
    ll a = 0;
    rep(c1,0,k+1){
        rep(c2,0,sz(C[c1])){
            int i = C[c1][c2];
            if(sz(C[c1])%2 == 1 && c2 == sz(C[c1])/2){
                B[i] = 1;
            }
            else{
                if(2*c2 < sz(C[c1])){
                    B[i] = 0;
                }
                else{
                    B[i] = 2;
                }
            }
        }
        a += sz(C[c1])/2;
    }

    rep(c1,0,n){
        if(B[c1] == 0)P1.push_back(A[c1]);
        if(B[c1] == 2)P2.push_back(A[c1]);
    }

    ll F[3] = {0};
    ll ans = 0;
    rep(c1,0,n){
        if(B[c1] == 0)ans += F[1] + F[2];
        if(B[c1] == 1)ans += F[2];
        F[B[c1]]++;
    }
    reverse(all(P2));
    unordered_map<ll,ll> M;
    rep(c1,0,n/2){
        a = MAXN * P2[c1] + F2[P2[c1]];
        M[a] = c1;
        F2[P2[c1]]++;
    }
    rep(c1,0,k+1){
        F2[c1] = 0;
    }
    rep(c1,0,n/2){
        a = MAXN * P1[c1] + F2[P1[c1]];
        F2[P1[c1]]++;
        P1[c1] = M[a];
    }

    FT ft(n+1);
    rep(c1,0,n/2){
        ans += (c1 - ft.query(P1[c1]+1));
        ft.update(P1[c1], 1);
    }
    cout << ans << "\n";

    return 0;
}
