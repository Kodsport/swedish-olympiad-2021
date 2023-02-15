#include "validator.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void run() {
	ll maxN = Arg("maxn");
	ll maxM = Arg("maxm");
	ll maxK = Arg("maxk");
	
	ll maxNKM = Arg("maxnkm", LLONG_MAX);
	ll maxNM = Arg("maxnm", LLONG_MAX);
	
	ll n = Int(2, maxN);
	Space();
	ll m = Int(0, maxM);
	Space();
	ll k = Int(n, maxK);
	Endl();
	
	assert(n * m * k <= maxNKM);
	assert(n * m <= maxNM);
	
	if (m > 0) {
		vector<pair<ll, ll>> intvs(m);
		for (ll i = 0; i < m; i++) {
			intvs[i].first = Int(0, k - 1);
			Space();
			intvs[i].second = Int(0, k - 1);
			Endl();
			assert(intvs[i].second >= intvs[i].first);
		}
		sort(intvs.begin(), intvs.end());
		
		ll totalOk = intvs[0].first + k - intvs.back().second - 1;
		for (ll i = 1; i < intvs.size(); i++) {
			assert(intvs[i].first > intvs[i - 1].second);
			totalOk += intvs[i].first - intvs[i - 1].second - 1;
		}
		cerr << totalOk << "\n";
		assert(totalOk >= n);
	}
}
