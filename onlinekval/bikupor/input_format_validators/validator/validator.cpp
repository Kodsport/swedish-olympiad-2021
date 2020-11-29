#include "validator.h"
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;

bool connected(vector<vector<int> > &graph, int n){
	vector<bool> seen(n,0);
	queue<int> Q;
	int nodes = 1;
	Q.push(0);
	seen[0] = 1;
	while(!Q.empty()){
		int a = Q.front();
		Q.pop();
		trav(y, graph[a]){
			if(!seen[y]){
				nodes++;
				seen[y] = 1;
				Q.push(y);
			}
		}
	}
	return (nodes == n);
}

void run() {
	int max_n = Arg("max_n");
	int max_m = Arg("max_m");
	int max_k = Arg("max_k");

	int n = Int(2, max_n);
	Space();
	int m = Int(1, max_m);
	Space();
	int k = Int(1, min(n-1,max_k));
	Endl();

	vector<vector<int> > graph(n, vector<int>());
	set<pair<int,int> > edges;

	for(int c1 = 0; c1 < m; c1++){
		int a = Int(1, n);
		Space();
		int b = Int(1, n);
		Endl();
		a--;
		b--;
		assert(a != b);
		if(a > b)swap(a,b);
		assert(edges.find({a,b}) == edges.end());
		edges.insert({a,b});
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	assert(connected(graph, n));

}
