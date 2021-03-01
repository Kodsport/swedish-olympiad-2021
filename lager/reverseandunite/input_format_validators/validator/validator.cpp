#include "validator.h"
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;

void run() {
	int max_n = Arg("max_n");
	int max_x = Arg("max_x");
	int max_d = Arg("max_d");

	int n = Int(2, max_n);
	Space();
	int d = Int(2, max_d);
	Endl();

	bool seen[2000] = {0};

	for(int c1 = 0; c1 < n; c1++){
		int x = Int(1, max_x);
		assert(!seen[x]);
		seen[x] = 1;
		if(c1 < n-1){
			Space();
		}
		else{
			Endl();
		}

	}
}
