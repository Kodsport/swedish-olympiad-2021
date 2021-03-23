#include "validator.h"

void run(){
	int N = Int(1, Arg("max_N"));
	Space();
	int K = Int(1, Arg("max_K"));
	Endl();
	if(Arg("N_even")) assert(N%2==0);
	
	vector<int> a = SpacedInts(N, 1, K);
	vector<int> f(K+1);
	for(int ai: a) f[ai] += 1;
	int odds = 0;
	for(int fi: f) odds += (fi%2);
	assert(odds<=1);
	Eof();
}
