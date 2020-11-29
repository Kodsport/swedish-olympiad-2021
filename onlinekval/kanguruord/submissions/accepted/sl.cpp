#include <bits/stdc++.h>
using namespace std;

// This code is duplicated in validator.cpp

vector<vector<int>> buildJumps(const string& s) {
	int M = (int)s.size();
	vector<vector<int>> jump(M+1);
	jump[M].assign(26, -1);
	for (int i = M-1; i >= 0; i--) {
		jump[i] = jump[i + 1];
		jump[i][s[i] - 97] = i;
	}
	return jump;
}

vector<int> findSubsequence(const string& s, const vector<vector<int>>& jump) {
	vector<int> ret;
	int at = 0;
	for (char c : s) {
		at = jump[at][c - 97];
		if (at == -1) return {};
		ret.push_back(at);
		at++;
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit | cin.badbit);
	string s;
	cin >> s;
	int N;
	cin >> N;
	int M = (int)s.size();
	auto jump = buildJumps(s);
	reverse(s.begin(), s.end());
	auto jump2 = buildJumps(s);
	int res = 0;
	int total = 0;
	for (int i = 0; i < N; i++) {
		cin >> s;
		vector<int> inds = findSubsequence(s, jump);
		if (inds.empty()) continue; // not a joey word
		reverse(s.begin(), s.end());
		vector<int> inds2 = findSubsequence(s, jump2);
		reverse(inds2.begin(), inds2.end());
		assert(inds.size() == s.size());
		assert(inds2.size() == s.size());
		bool messy = false;
		for (int i = 0; i < (int)s.size(); i++) {
			if (inds[i] != M-1 - inds2[i]) messy = true;
		}
		if (messy) res++;
		total++;
	}
	cout << res << endl;
	cerr << res << " / " << total << " / " << N << endl;
}
