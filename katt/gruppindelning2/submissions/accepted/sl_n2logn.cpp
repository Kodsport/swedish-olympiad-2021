#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct A {
	ll mul, add;
	int size;
};

vector<A> as;
vector<ll> dp;
int N;
ll ans = LLONG_MIN;

void updateDp(int ind) {
	A a = as[ind];
	// try group of size 1, and also of full size
	for (int i = N; i >= a.size; i--) {
		dp[i] = max({
			dp[i],
			dp[i - 1] + a.mul + a.add,
			dp[i - a.size] + a.mul * a.size + a.add
		});
	}
	for (int i = a.size - 1; i > 0; i--) {
		dp[i] = max(
			dp[i],
			dp[i - 1] + a.mul + a.add
		);
	}
}

void rec(int lo, int hi) {
	if (lo + 1 == hi) {
		// try any size for the last group
		A a = as[lo];
		rep(i,1,a.size+1) {
			ans = max(ans, dp[N-i] + a.mul * i + a.add);
		}
		return;
	}
	vector<ll> old = dp;
	int mid = (lo + hi) / 2;
	rep(i,lo,mid) {
		updateDp(i);
	}
	rec(mid, hi);
	dp = old;
	rep(i,mid,hi) {
		updateDp(i);
	}
	rec(lo, mid);
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	cin >> N;
	as.resize(N);
	rep(i,0,N) {
		A& a = as[i];
		cin >> a.mul >> a.add >> a.size;
	}
	dp.assign(N+1, -(1LL << 60));
	dp[0] = 0;
	rec(0, N);
	cout << ans << endl;
	exit(0);
}
