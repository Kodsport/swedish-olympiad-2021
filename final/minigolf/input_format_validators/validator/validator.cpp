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


const int large = 1'000'000;

void run() {
  ll r = Int(Arg("min_r", 1), Arg("max_r", large)); Space();
  ll c = Int(1, Arg("max_c", large)); Space();
  ll k = Int(1, Arg("max_k", large)); Endl();
  ll max_rc = Arg("max_rc",large);
  if(r*c > max_rc) die_line("r*c too large");
  if(Arg("k_infty",0) && k < max(r,c)) die_line("k < max(r,c)");

  vi char_cnt(256);

  rep(i,0,r) {
    string s = Line();
    if(sz(s) != c) die_line("grid does not have c columns");
    rep(j,0,c) char_cnt[s[j]]++;
  }
  Eof();

  if(char_cnt['S'] != 1) die_line("grid does not have exactly 1 S");
  if(char_cnt['G'] != 1) die_line("grid does not have exactly 1 G");
  if(char_cnt['.'] + char_cnt['#'] + 2 != r*c) die_line("grid is not well-formed");
  if(Arg("empty",0) && char_cnt['#'] != 0) die_line("grid should be empty");


  // TODO: verify possible to solve?
}

