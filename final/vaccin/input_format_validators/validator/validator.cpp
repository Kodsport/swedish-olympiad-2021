#include "validator.h"

typedef long long ll;

void run() {
	int max_n  = Arg("max_n");
	if (max_n == -1) max_n = 100000;
	int max_k  = Arg("max_k");
	if (max_k == -1) max_k = 100000;
	int n = Int(1, 100000);
	Space();
	int k = Int(1, 100000);
	Endl();

	for (int j = 0; j < n; j++) {
		int a = Int(0, 15);
		Space();
	}
	Endl();
	for (int j = 0; j < k; j++) {
		int a = Int(0, 1000000);
		Space();
	}
	Endl();
}