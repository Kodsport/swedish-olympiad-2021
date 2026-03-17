#include "validator.h"

void run(){
	string bmode = Arg("b");
	int N = Int(1, Arg("n"));
	Endl();

	for (int i = 0; i < N; i++) {
		Int(-1'000'000'000, 1'000'000'000);
		Space();
		int b = Int(-1'000'000'000, 1'000'000'000);
		Space();
		Int(1, N);
		Endl();
		if (bmode == "-") assert(b <= 0);
		else if (bmode == "+") assert(b >= 0);
		else assert(bmode == "+-");
	}
}
