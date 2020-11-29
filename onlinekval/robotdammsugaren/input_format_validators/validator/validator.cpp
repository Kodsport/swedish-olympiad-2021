#include "validator.h"

typedef long long ll;

void run() {
	int max_r  = Arg("max_r");
	if (max_r == -1) max_r = 2000;

	ll max_rcn  = Arg("max_rcn");
	if (max_rcn == -1) max_rcn = 2000ll*2000ll*2000ll;

	int r = Int(3, max_r);
	Space();
	int c = Int(3, 2000);
	Space();
	int n = Int(1, 2000);
	Endl();

	assert(ll(r)*ll(c)*ll(n)<=max_rcn);

	for (int j = 0; j < n; j++) {
		char ch = Char();
		assert(ch=='<'||ch=='v'||ch=='^'||ch=='>');
	}
	Endl();

	int num_O = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char ch = Char();
			if(i==0||j==0||i==r-1||j==c-1) assert(ch=='#');
			assert(ch == '#' || ch == '.' || ch=='O');
			num_O += (ch=='O');
		}
		Endl();
	}

	assert(num_O==1);
}
