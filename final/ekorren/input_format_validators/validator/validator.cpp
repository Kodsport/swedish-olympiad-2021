#include "validator.h"

typedef long long ll;

vector<vector<int>> e;
vector<bool> seen;

void dfs(int v){
	if(seen[v]) return;
	seen[v] = true;
	for(int u: e[v]) dfs(u);
}

void run() {
	int n = Int(1, Arg("max_n"));
	Space();
	int k = Int(1, n);
	Endl();
	auto v = SpacedInts(k,1,n);
	AssertUnique(v);

	seen.resize(n);
	e.resize(n);

	bool line = Arg("line");
	for (int j = 0; j < n-1; j++) {
		int a = Int(1,n);
		Space();
		int b = Int(1,n);
		Endl();
		e[a-1].push_back(b-1);
		e[b-1].push_back(a-1);

		if(line){
			assert(a==j+1);
			assert(b==j+2);
		}
	}
	Eof();

	dfs(0);
	for (int j = 0; j < n; j++) assert(seen[j]);
}
