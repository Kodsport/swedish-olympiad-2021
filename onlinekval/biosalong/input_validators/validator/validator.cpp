#include "validator.h"

typedef long long ll;

void run() {
	int n = Int(2, Arg("max_n"));
	Endl();

	int numFree = 0;
	for (int j = 0; j < n; j++) {
		char ch = Char();
		assert(ch=='#'||ch=='.');
		numFree += ch=='.';
	}
	assert(numFree>=2);
	Endl();
}
