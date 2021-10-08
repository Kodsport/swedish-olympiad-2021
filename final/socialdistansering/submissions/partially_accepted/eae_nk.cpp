//@EXPECTED_GRADES@ TLE AC AC TLE TLE TLE
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
	intvs.emplace_back(LLONG_MAX, LLONG_MAX);
	sort(intvs.begin(), intvs.end());
	
	auto possible = [&] (ll dist) {
		ll lastPos = -dist;
		ll intvIndex = 0;
		for (ll i = 0; i < n; i++) {
			ll nextPos = lastPos + dist;
			while (true) {
				while (intvs[intvIndex].second < nextPos)
					intvIndex++;
				if (intvs[intvIndex].first > nextPos)
					break;
				nextPos = intvs[intvIndex].second + 1;
			}
			if (nextPos >= k)
				return false;
			lastPos = nextPos;
		}
		return true;
	};
	
	ll dist = 1;
	while (possible(dist)) {
		dist++;
	}
	
	cout << (dist - 1) << "\n";
}
