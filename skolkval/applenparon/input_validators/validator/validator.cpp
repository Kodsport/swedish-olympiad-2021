#include "validator.h"

typedef long long ll;

void run() {
  bool noeq = Arg("noeq", 0);


  int n = Int(0, 1000);
  Space();
  int k = Int(0, 1000);
  if (noeq) assert(n*7!=k*13);
  Endl();
  Eof();
}
