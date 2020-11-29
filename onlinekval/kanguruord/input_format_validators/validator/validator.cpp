#include "validator.h"

string word() {
	string ret;
	for (;;) {
		char c = Char();
		if (c == '\n') break;
		assert('a' <= c && c <= 'z');
		ret += c;
	}
	assert(!ret.empty());
	return ret;
}

void run() {
	int maxSum = Arg("sum");
	int maxLen = Arg("len");
	bool allMessy = Arg("allmessy");
	string s = word();
	int M = (int)s.size();
	assert(M <= maxLen);
	set<string> words;
	words.insert(s);

	vector<array<int, 26>> jump(M+1);
	fill(jump[M].begin(), jump[M].end(), -1);
	for (int i = M-1; i >= 0; i--) {
		jump[i] = jump[i + 1];
		unsigned o = s[i] - 97;
		assert(o < 26);
		jump[i][o] = i;
	}

	int n = Int(1, Arg("n"));
	Endl();

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		s = word();
		words.insert(s);
		sum += (int)s.size();

		if (allMessy) {
			int at = 0;
			char prevc = 0;
			for (char c : s) {
				int at2 = jump[at][c - 97];
				if (at2 == -1) goto next; // not a joey word
				if (prevc) {
					int at3 = jump[at][prevc - 97];
					if (at3 != -1 && at3 < at2) goto next; // messy, if a joey word at all
				}
				at = at2 + 1;
				prevc = c;
			}
			assert(prevc);
			if (jump[at][prevc - 97] != -1) goto next; // messy
			die("Joey word is not messy");
next:;
		}
	}

	assert(sum <= maxSum);
	assert((int)words.size() == n + 1);
}
