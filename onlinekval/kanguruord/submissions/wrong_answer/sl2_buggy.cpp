#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	string s;
	cin >> s;
	int N;
	cin >> N;
	int M = (int)s.size();
	vector<array<int, 26>> jump(M+1);
	fill(jump[M].begin(), jump[M].end(), -1);
	for (int i = M-1; i >= 0; i--) {
		jump[i] = jump[i + 1];
		jump[i][s[i] - 97] = i;
	}
	int res = 0;
	int total = 0;
	for (int i = 0; i < N; i++) {
		cin >> s;
		int at = 0;
		char prevc = 0;
		bool multi = false;
		for (char c : s) {
			int at2 = jump[at][c - 97];
			if (at2 == -1) goto next; // not a joey word
			if (prevc) {
				int at3 = jump[at][prevc - 97];
				if (at3 != -1 && at3 < at2) multi = true;
			}
			at = at2 + 1;
			prevc = c;
		}
		assert(prevc);
		// if (jump[at][prevc - 97] != -1) multi = true;
		if (multi) res++;
		total++;
next:;
	}
	cout << res << endl;
	cerr << res << " / " << total << " / " << N << endl;
}
