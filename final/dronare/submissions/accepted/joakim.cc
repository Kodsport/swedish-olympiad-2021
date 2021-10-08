
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef __int128_t ll;
using ld = long double;
typedef long long llo;
typedef pair<int, int> pii;
typedef vector<ll> vi;

struct Frac { ll p, q; };

Frac fracBS(auto&& f) {
  bool dir = 1, A = 1, B = 1;
  Frac lo{0, 1}, hi{1, 0};
  if (f(lo)) return lo;
  assert(f(hi));
  while (A || B) {
    ll adv = 0, step = 1; // move hi if dir, else lo
    for (int si = 0; step; (step *= 2) >>= si) {
      adv += step;
      Frac mid{lo.p * adv + hi.p, lo.q * adv + hi.q};
      if (dir == !f(mid)) {
        adv -= step; si = 2;
      }
    }
    hi.p += lo.p * adv;
    hi.q += lo.q * adv;
    dir = !dir;
    swap(lo, hi);
    A = B; B = !!adv;
  }
  return dir ? hi : lo;
}

const ll inf = 1e30;

void answer(Frac f) {
  cerr << llo(f.p) << " / "  << llo(f.q) << endl;
  cout << setprecision(14) << fixed;
  cout << (ld(f.p) / ld(f.q)) << endl;
  exit(0);
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  llo n, b, w;
  cin >> n >> b >> w;
  vi energy(n), weight(n), cost(n);
  rep(i,0,n) {
    llo e,w,c;
    cin >> e >> w >> c;
    energy[i] = e, weight[i] = w, cost[i] = c;
  }

  auto test = [&](Frac f) { // return true if f >= ans
    vi reach(b+1, -inf);
    reach[0] = -f.p*w;
    rep(i,0,n) {
      ll k = f.q*energy[i] - f.p*weight[i];
      for(int j = b; j >= cost[i]; --j)
        reach[j] = max(reach[j], reach[j-cost[i]] + k);
    }
    ll q = *max_element(all(reach));
    if(q == 0) answer(f);
    return q <= 0;
  };

  fracBS(test);
  assert(false);
}
