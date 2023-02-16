#include "validator.h"

void run(){
	int N = Int(1, 2000);
	Space();
	int M = Int(1, 2000);
	Endl();
	for(int c1 = 0; c1 < N; c1++){
		string s = Line();
		assert(s.length() == M);
	}
	Eof();
}
