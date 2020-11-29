#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < int(b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define D(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main(){
	cin.sync_with_stdio(false); cin.tie(0);

	ll n,k,h;
	cin>>n>>k>>h;

	ll ans = 0;
	rep(i,0,n-1) {
		ll d;
		cin>>d;
		ans += d*h;
	}
	cout<<ans<<endl;
}
