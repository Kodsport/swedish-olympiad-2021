#include "validator.h"

typedef long long ll;

vector<vector<int>> e;
vector<bool> seen;

void run() {
	int maxn = Arg("maxn");
	int maxw = Arg("maxw");
	int sameprice = Arg("sameprice");
	int n = Int(1, maxn);
	Space();
	int b = Int(1, 100000);
	Space();
	int w = Int(1, 1000);
	Endl();
	assert(n*b >= 1 && n*b <= 200000);

	seen.resize(n);
	e.resize(n);
	set<int> cs;
	for (int j = 0; j < n; j++) {
		int e = Int(0,1000);
		Space();
		int w = Int(0,maxw);
		Space();
		int c = Int(0,b);
		Endl();

		cs.insert(c);
	}
	Eof();

	if(sameprice) assert(cs.size()==1);
}
