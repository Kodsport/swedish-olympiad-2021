#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(ll i = a; i<ll(b);i++)
#define rrep(i,a,b) for(ll i = b-1; i>=ll(a);i--)
#define trav(x,s) for(auto &x: s)
#define all(v) v.begin(),v.end()
#define sz(v) ll(v.size())

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;

struct Tree {
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a+b; } // (any associative fn)
	vector<T> s; ll n;
	Tree(ll n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(ll pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(ll b, ll e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

ll swapsSort(vi a){
    //trav(ti,a) cout<<ti<<" ";
    //cout<<endl;
    Tree st(sz(a));
    ll ans = 0;
    trav(ai,a){
        ans += st.query(ai,sz(a));
        st.update(ai,1);
    }
    return ans;
}

vector<pii> makeUnique(vi a){
    map<ll,ll> m;
    vector<pii> b;
    trav(ai,a) b.emplace_back(ai,m[ai]++);
    return b;
}

ll swapsReorder(vi a, vi b){
    vector<pii> ap = makeUnique(a);
    vector<pii> bp = makeUnique(b);

    map<pii, ll> m;
    ll c = 0;
    trav(bi,bp) m[bi] = c++;
    vi toSort;
    trav(ai,ap) toSort.emplace_back(m[ai]);
    return swapsSort(toSort);
}

int main(){
    ll n,k;
    cin>>n>>k;
    k++;
    vi a(n);
    trav(ai,a) cin>>ai;
    vi f(k);
    trav(ai,a) f[ai]++;
    ll odd = -1;
    rep(i,0,k) {
        if(f[i]%2==1) odd = i;
        f[i]/=2;
    }
    vi target;

    trav(ai,a){
        if(f[ai]>0){
            f[ai]--;
            target.push_back(ai);
        }
    }
    if(odd!=-1) target.push_back(odd);
    rrep(i,0,n/2) target.push_back(target[i]);

    //trav(ti,target) cout<<ti<<" ";
    //cout<<endl;
    cout<<swapsReorder(a,target)<<endl;
}