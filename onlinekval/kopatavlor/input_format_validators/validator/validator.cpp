#include "validator.h"

typedef long long ll;

void run() {
	int max_n = Arg("max_n");
	if(max_n==-1) max_n = 2000;

	int n = Int(1, max_n);
	Space();
	int k = Int(1, n);
	Endl();
	int fixed_k = Arg("k");
	if(fixed_k != -1) assert(k==fixed_k);

	SpacedInts(n,1,1000);
  Eof();
}
