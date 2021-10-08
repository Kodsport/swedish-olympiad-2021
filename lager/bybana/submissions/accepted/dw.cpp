#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	int n, l;
	cin >> n >> l;

	vector<vi> ls(l);
	trav(v, ls){
		int m;
		cin >> m;
		v.resize(m);
		trav(x, v) cin >> x;
	}

	vector<vector<pii>> gr(n + l);
	
	rep(j,0,l) rep(i,0,sz(ls[j])){
		int x = ls[j][i]-1;
		int y = n + j;
		int d = min(i, sz(ls[j])-1-i);
		gr[x].emplace_back(y, d);
		gr[y].emplace_back(x, d);
	}
	priority_queue<pii> pq;
	pq.push({-0, 0});

	vi dist(n + l, 1e7);
	dist[0] = 0;

	while(!pq.empty()){
		pii p = pq.top();
		pq.pop();

		int v = p.second;
		if(dist[v] != -p.first) continue;

		trav(e, gr[v]) if(dist[e.first] > dist[v] + e.second){
			dist[e.first] = dist[v] + e.second;
			pq.push({-dist[e.first], e.first});
		}
	}
	cout << dist[n-1] << endl;
}
