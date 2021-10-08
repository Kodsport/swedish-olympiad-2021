// @EXPECTED_GRADES@ WA WA WA WA WA

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
  int r,c,k;
  cin>>r>>c>>k;
  int x0, y0;
  int x1, y1;
  rep(i,0,r) {
    string row;
    cin>>row;
    rep(j,0,c) {
      if(row[j] == 'S') x0 = i, y0 = j;
      if(row[j] == 'G') x1 = i, y1 = j;
    }
  }
  cout << 2+((abs(x0-x1))/k +(abs(y0-y1))/k) << endl;
}
