#include "jngen.h"
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(int argc, char *argv[]) {
  registerGen(argc, argv);
  parseArgs(argc, argv);

  int n, q;
  string type;
  getNamed(n,q,type);

  Tree t;
  if(type == "random") {
    t = Tree::random(n);
  }
  else if(type == "prim") {
    int elong = getOpt("elong", 0);
    t = Tree::randomPrim(n, elong);
  }
  else if(type == "kruskal") {
    t = Tree::randomKruskal(n);
  }
  else if(type == "bamboo") {
    t = Tree::bamboo(n);
  }
  else if(type == "star") {
    t = Tree::star(n);
  }
  else if(type == "caterpillar") {
    int len = getOpt("len", n/2);
    t = Tree::caterpillar(n,len);
  }
  else if(type == "binary") {
    t = Tree::binary(n);
  }
  else if(type == "broom") {
    int len = getOpt("len", n/2);
    t = Tree::bamboo(len).link(0, Tree::star(n-len), 0);
  }
  else if(type == "dumbbell") {
    int len = getOpt("len", sqrt(n));
    int n1 = (n-len)/2, n2 = n-len-n1;
    t = Tree::bamboo(len).link(0, Tree::star(n1), 0).link(len-1, Tree::star(n2), 0);
  }
  else assert(false);

  auto relabel = Array::id(n);

  string labeling = getOpt("labeling", "shuffled");
  if(labeling == "shuffled") {
    relabel.shuffle();
  }
  else if(labeling == "none") {
    // do nothing
  }
  else if(labeling == "reverse") {
    relabel.reverse();
  }
  else if(labeling == "alternate") {
    rep(i,0,n) {
      if(i%2) relabel[i] = i/2;
      else relabel[i] = n-(i/2)-1;
    }
  }


  assert(t.n() == n);
  cout << n << " " << q << endl;
  for(auto [x,y] : t.edges()) {
    cout << relabel[x]+1 << " " << relabel[y]+1 << endl;
  }
}
