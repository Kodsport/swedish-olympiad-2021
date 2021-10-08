//@EXPECTED_GRADES@ AC AC AC TLE TLE TLE
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	
	vector<pair<ll, ll>> intvs(m);
	for (ll i = 0; i < m; i++) {
		cin >> intvs[i].first >> intvs[i].second;
	}
	sort(intvs.begin(), intvs.end());
	
	auto isBlocked = [&] (ll x) {
		auto it = lower_bound(intvs.begin(), intvs.end(), make_pair(x, LLONG_MAX));
		return it != intvs.begin() && x <= (it - 1)->second;
	};
	
	auto possible = [&] (ll dist) {
		ll lastPos = 0;
		while (isBlocked(lastPos))
			lastPos++;
		for (ll i = 1; i < n; i++) {
			ll nextPos = lastPos + dist;
			if (nextPos >= k)
				return false;
			while (nextPos < k && isBlocked(nextPos))
				nextPos++;
			if (nextPos >= k)
				return false;
			lastPos = nextPos;
		}
		return true;
	};
	
	ll lo = 1;
	ll hi = k;
	while (hi > lo) {
		ll mid = lo + (hi - lo) / 2;
		if (possible(mid)) {
			lo = mid + 1;
		} else {
			hi = mid;
		}
	}
	
	cout << lo - 1 << "\n";
}
