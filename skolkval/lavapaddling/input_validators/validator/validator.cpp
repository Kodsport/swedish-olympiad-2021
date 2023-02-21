#include "validator.h"

typedef long long ll;

void run() {
  ll n = Int(1, 20);
  Space();
  ll k  = Int(1, Arg("max_k", 15));
  Space();
  ll h  = Int(1, Arg("max_h", 1000000000000));
  Endl();
  SpacedInts(n-1,1,1000);
  Eof();
}
