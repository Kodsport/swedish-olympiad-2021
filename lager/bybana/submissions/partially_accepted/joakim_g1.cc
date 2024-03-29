// @EXPECTED_GRADES@ AC WA WA WA WA

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
  int n, l;
  cin >> n >> l;
  int ans = 1e9;
  rep(i,0,l) {
    int a = -1, b = -1, m;
    cin>>m;
    rep(j,0,m) {
      int x;
      cin>>x;
      if(x == 1 && a == -1) a = j;
      if(x == n && b == -1) b = j;
      if(x == 1 && b != -1) {
        ans = min(ans, min(j, m-j-1) + min(b, m-b-1));
      }
      if(x == n && a != -1) {
        ans = min(ans, min(a, m-a-1) + min(j, m-j-1));
      }
    }
  }
  cout << ans << endl;
}
