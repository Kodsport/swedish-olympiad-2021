#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


struct UF {
  vi e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b]; e[b] = a;
    return true;
  }
};

void run() {
  int q = Arg("q");
  int maxn = Arg("maxn");
  bool line = Arg("line");

  int n = Int(3,maxn); Space();
  Int(q,q); Endl();
  assert(n%2 == 1);

  UF uf(n);
  vi deg(n);

  rep(i,1,n) {
    int a = Int(1,n); Space();
    int b = Int(1,n); Endl();
    --a,--b;
    assert(uf.join(a,b));
    ++deg[a];
    ++deg[b];
  }
  Eof();

  if(line) assert(*max_element(all(deg)) <= 2);
}

