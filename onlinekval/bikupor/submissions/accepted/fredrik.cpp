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

struct UF {
	vi e;
    multiset<ll> s;
	UF(ll n) : e(n, -1) {}
	bool sameSet(ll a, ll b) { return find(a) == find(b); }
	ll size(ll x) { return -e[find(x)]; }
	ll find(ll x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(ll a, ll b) {
		a = find(a), b = find(b);
		if (a == b) return false;
        s.erase(s.find(size(a)));
        s.erase(s.find(size(b)));
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
        s.insert(size(a));
		return true;
	}
};

int main(){
    ll n,m,k;
    cin>>n>>m>>k;

    vector<vi> e(n);
    rep(i,0,m){
        ll a,b;
        cin>>a>>b;
        --a; --b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    set<ll> availableLow;
    rep(i,0,n) availableLow.insert(i);

    UF uf(n);
    rrep(v,0,n){
        availableLow.erase(v);
        uf.s.insert(1);
        trav(u,e[v]) {
            if(u>v)
                uf.join(u,v);
            availableLow.erase(u);
        }

        if(n-v>=k && sz(availableLow)>0){
            cout<<1<<endl;
            cout<<*availableLow.begin()+1<<endl;
            return 0;
        }
        ll smallestComp = *uf.s.begin();
        if(n-v-smallestComp>=k){
            vector<vi> comps(n);
            rep(i,v,n) comps[uf.find(i)].push_back(i);
            rep(i,0,n){
                if(sz(comps[i])==smallestComp){
                    cout<<sz(comps[i])<<endl;
                    trav(ci,comps[i]) cout<<ci+1<<" ";
                    cout<<endl;
                    return 0;
                }
            }
            assert(false);
        }
    }
    cout<<-1<<endl;
}