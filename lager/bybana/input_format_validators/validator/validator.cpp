#include "validator.h"

struct UF {
	vector<int> t;
	int components;
	UF(int n){
		t.resize(n, -1);
		components = n;
	}
	int find(int a){
		return t[a] < 0 ? a : t[a] = find(t[a]);
	}
	void uni(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return;
		--components;
		if(t[a] < t[b]) swap(a, b);
		t[b] += t[a];
		t[a] = b;
	}
};

void run(){
	int max_M = Arg("max_M");
	int N = Int(2, Arg("max_N"));
	Space();
	int L = Int(1, Arg("max_L"));
	Endl();
	UF uf(N);
	int sum = 0;
	for(int i = 0; i < L; ++i){
		int M = Int(2, min(max_M,N));
		Space();
		sum += M;
		vector<int> ls = SpacedInts(M, 1, N);
		AssertUnique(ls);
		for(auto x : ls) uf.uni(x-1, ls[0]-1);
	}
	assert(sum <= (int)Arg("max_sum_M"));
	assert(uf.components == 1); // nätverket ska vara sammanhängande
	Eof();
}
