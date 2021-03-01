#include <vector>
#include <algorithm>
#include "validate.h"

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

void check_case(){
    int n,d;
    vi X;
    judge_in >> n >> d;
    for(int c1 = 0; c1 < n; c1++){
        int x;
        judge_in >> x;
        X.push_back(x);
    }

    int size_c, size_j;
    if(!(author_out >> size_c)){
        wrong_answer("Could not read first number of contestants output.\n");
    }
    judge_ans >> size_j;

    if(size_c == -1){
        if(size_j != -1){
            wrong_answer("Contestant printed '-1' but an answer existed.\n");
        }
        return;
    }

    if(size_c < 0 || size_c > 100000){
        wrong_answer("Invalid number of moves: %d.\n", size_c);
    }

    for(int c1 = 0; c1 < size_c; c1++){
        int L;
        if(!(author_out >> L)){
            wrong_answer("Could not read %d:th item in output.\n", c1+1);
        }
        for(int c2 = 0; c2 < n; c2++){
            if(X[c2] >= L && X[c2] - (d-1) <= L){
                X[c2] = L + d - 1 - (X[c2] - L);
            }
        }
    }

    sort(all(X));
    if(X[n-1] - X[0] != n-1){
        wrong_answer("Items were not together, distance: %d.\n", X[n-1] - X[0]);
    }

    if(size_j == -1){
        judge_error("Judge says '-1' but contestants solution was valid.\n");
    }
}

int main(int argc, char **argv) {
  init_io(argc, argv);
  check_case();

  /* Check for trailing output. */
  string trash;
  if (author_out >> trash) {
      wrong_answer("Trailing output\n");
  }

  accept();
  return 0;
}
