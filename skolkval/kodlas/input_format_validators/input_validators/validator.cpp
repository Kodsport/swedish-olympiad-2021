#include "validator.h"

typedef long long ll;

void run() {
  int max_n  = Arg("max_n", int(12));
  int max_m  = Arg("max_m", int(12));
  int max_dots_per_row = Arg("max_dots_per_row", int(12));

  int n = Int(2, max_n);
  Space();
  int m = Int(0, max_m);
  Endl();
  for(int i = 0; i < n; ++i) {
    int dots = 0;
    for(int j = 0; j < m; ++j) {
      char c = Char();
      if(c != '#' && c != '.')
        die_line("Expected \'.\' or \'#\'; got \'" + string(1,c) + "\'");
      if(c == '.') ++dots;
    }
    if(dots > max_dots_per_row)
      die_line("Expected only " + to_string(max_dots_per_row) + " \'.\' in row " + to_string(i) + "; found " + to_string(dots));
    Endl();
  }
  Eof();
}
