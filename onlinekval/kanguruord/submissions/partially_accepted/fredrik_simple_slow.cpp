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
        if(s.size()>M) continue;
        bool allSame = true;
        for(int j = 0; j<s.size()-1; j++) allSame &= (s[i]==s[i+1]);

        for(int j = allSame?s.size():1; j<=s.size(); j++){ //Lets check all prefixes for no reason
            int at = 0;
            for(int k = 0; k<j;k++){
                int at2 = jump[at][s[k] - 97];
                if (at2 == -1) goto next; // not a joey word
                at = at2 + 1;
            }
        }
		res++;
next:;
	}
	cout << res << endl;
}
