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

int n,m,k;
vector<vi> graph;

void check_case(){
    judge_in >> n >> m >> k;
    graph.assign(n, vi());
    for(int c1 = 0; c1 < m; c1++){
        int a,b;
        judge_in >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
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

    if(size_c <= 0 || size_c > n-k){
        wrong_answer("Invalid number of vertices: %d.\n", size_c);
    }

    vector<int> answer;
    vector<int> picked(n,0);
    for(int c1 = 0; c1 < size_c; c1++){
        int i;
        if(!(author_out >> i)){
            wrong_answer("Could not read %d:th item in output.\n", c1+1);
        }
        if(i <= 0 || i > n){
            wrong_answer("Invalid number %d at %d:th item in output.\n", i, c1+1);
        }
        i--;
        if(picked[i] > 0){
            wrong_answer("Duplicate elements (%d) at index %d and %d.\n", i+1, picked[i], c1+1);
        }
        picked[i] = c1+1;
    }

    vector<int> bad;
    for(int c1 = n-1; c1 >= 0; c1--){
        if(picked[c1] == 0){
            bad.push_back(c1);
            if(sz(bad) == k)break;
        }
    }
    assert(sz(bad) == k);

    for(int c1 = 0; c1 < sz(bad); c1++){
        int i = bad[c1];
        for(int c2 = 0; c2 < sz(graph[i]); c2++){
            int j = graph[i][c2];
            if(picked[j] != 0){
                wrong_answer("Bad vertex %d is adjacent to picked vertex %d.\n", i+1, j+1);
            }
        }
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
