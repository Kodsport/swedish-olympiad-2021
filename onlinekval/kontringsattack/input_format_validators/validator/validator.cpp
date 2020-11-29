#include "validator.h"

typedef long long ll;

void run() {
	int max_n  = Arg("max_n");
	if (max_n == -1) max_n = 100000;

	int max_score  = Arg("max_score");
	if (max_score == -1) max_score = 1000000;

	int n = Int(1, max_n);
	Endl();

	for (int j = 0; j < n; j++) {
		int a = Int(0, max_score);
		Space();
		a = Int(0, max_score);
		Endl();
	}
}