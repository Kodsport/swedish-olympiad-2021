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
	for (int i = 0; i < N; i++) {
		cin >> s;
		int at = 0;
		for (char c : s) {
			int at2 = jump[at][c - 97];
			if (at2 == -1) goto next; // not a joey word
			at = at2 + 1;
		}
		res++;
next:;
	}
	cout << res << endl;
}
