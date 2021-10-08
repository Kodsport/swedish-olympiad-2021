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
	
	vector<pair<ll, ll>> okIntv;
	ll prevR = -1;
	for (ll i = 0; i < m; i++) {
		if (prevR + 1 != intvs[i].first)
			okIntv.emplace_back(prevR + 1, intvs[i].first - 1);
		prevR = intvs[i].second;
	}
	if (prevR + 1 < k)
		okIntv.emplace_back(prevR + 1, k - 1);
	
	auto possible = [&] (ll dist) {
		ll lastPos = -dist;
		ll numPlaced = 0;
		for (ll i = 0; i < (ll)okIntv.size(); i++) {
			ll firstPos = max(lastPos + dist, okIntv[i].first);
			if (firstPos > okIntv[i].second) continue;
			
			ll numToPlace = max(okIntv[i].second - firstPos, 0LL) / dist + 1;
			numPlaced += numToPlace;
			if (numPlaced >= n)
				return true;
			lastPos = firstPos + dist * (numToPlace - 1);
		}
		return false;
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
