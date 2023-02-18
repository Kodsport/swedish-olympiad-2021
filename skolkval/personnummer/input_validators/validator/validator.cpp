#include "validator.h"

typedef long long ll;

void run() {
  bool noplus = Arg("noplus", 0);

  // Lousy validation cause who cares
  string input = Line();
  assert(input.size()==11);
  if (noplus) assert(input.find("+")==string::npos);
  Eof();
}
