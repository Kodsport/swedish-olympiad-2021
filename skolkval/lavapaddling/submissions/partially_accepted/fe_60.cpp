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

	vi d(n-1);

	rep(i,0,n-1) cin>>d[i];

	ll start = 24;

	while(true){
		ll paddles = start;
		rep(i,0,n-1){
			paddles = min(paddles*k-d[i]*h,paddles);
			if(paddles<0) goto next;
		}
		cout<<start<<endl;
		return 0;

		next:
		start++;
	}
}
