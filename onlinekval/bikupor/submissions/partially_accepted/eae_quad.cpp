//@EXPECTED_GRADES@ TLE AC AC TLE TLE
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for (int st = 0; st < n; st++) {
		vector<int> owner(n, 0);
		for (int i = n - k; i < n; i++)
			owner[i] = 1;
		int next0 = n - k;
		
		vector<int> toTake;
		toTake.push_back(st);
		while (!toTake.empty()) {
			int nxt = toTake.back();
			toTake.pop_back();
			if (owner[nxt] == 2)
				continue;
			while (next0 >= 0 && owner[next0] != 0)
				next0--;
			if (next0 >= 0 && owner[nxt] == 1) {
				owner[next0] = 1;
				for (int nei : adj[next0]) {
					if (owner[nei] == 2) {
						toTake.push_back(next0);
						break;
					}
				}
			}
			owner[nxt] = 2;
			for (int nei : adj[nxt]) {
				if (owner[nei] == 1) {
					toTake.push_back(nei);
				}
			}
		}
		
		int numTaken = count(owner.begin(), owner.end(), 2);
		if (n - numTaken >= k) {
			cout << numTaken << "\n";
			for (int i = 0; i < n; i++) {
				if (owner[i] == 2) {
					cout << (i + 1) << " ";
				}
			}
			cout << "\n";
			return 0;
		}
	}
	cout << "-1\n";
}
