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

bool operator<(const A& a, const A& b) {
	return a.mul > b.mul;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	vector<A> as(N);
	rep(i,0,N) {
		A& a = as[i];
		cin >> a.mul >> a.add >> a.size;
	}
	sort(all(as));
	vector<ll> dp(N+1, -(1LL << 60));
	dp[0] = 0;
	ll ans = LLONG_MIN;
	vector<ll> ones(N);
	rep(i,0,N) {
		ones[i] = as[i].mul + as[i].add;
	}
	sort(all(ones), greater<ll>());
	rep(ind,0,N) {
		A a = as[ind];
		auto it = find(all(ones), a.mul + a.add);
		ones.erase(it);
		// try group of partial size, the rest being zeroes
		int oneit = 0, git = 1;
		ll acc = a.add + a.mul;
		ans = max(ans, dp[N-1] + acc);
		for (int i = N-2; i >= 0; i--) {
			if (oneit == sz(ones) && git == a.size) break;
			if (git == a.size || (oneit < sz(ones) && ones[oneit] > a.mul))
				acc += ones[oneit], oneit++;
			else
				acc += a.mul, git++;
			ans = max(ans, dp[i] + acc);
		}
		// try group of full size
		for (int i = N; i >= a.size; i--) {
			dp[i] = max(
				dp[i],
				dp[i - a.size] + a.mul * a.size + a.add
			);
		}
	}
	cout << ans << endl;
	exit(0);
}
