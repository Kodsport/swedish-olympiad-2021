#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  string s;
  cin>>s;
  int yyyy = stoi(s.substr(0,2));
  int mm = stoi(s.substr(2,2));
  int dd = stoi(s.substr(4,2));
  int xxxx = stoi(s.substr(7,4));

  while(2020-yyyy > 200) yyyy += 100;
  while(s[6] == '-' && 2020-yyyy > 100) yyyy += 100;

  cout << setfill('0');
  cout << setw(4) << yyyy;
  cout << setw(2) << mm;
  cout << setw(2) << dd;
  cout << setw(4) << xxxx << endl;
}
