#include "validator.h"

void run() {
	int C = Int(0, 10);
	assert(C == (int)Arg("c"));
	Endl();
	int N = Int(1, 100000);
	Space();
	int T = Int(1, 10000000);
	Endl();
	for(int i = 0; i < N; i++){
		int t = Int(0,10000);
		Space();
		int v = Int(0,10000);
		Space();
		int k = Int(0,10000);
		Endl();
		auto a = SpacedInts(k,0,i-1);
		AssertUnique(a);
	}
}
