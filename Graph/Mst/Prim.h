#include "../../template.h"
#include "../../DataStructure/DSU/Dsu.h"

struct Edge {
	int u, v, w;
	Edge() {}
	Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
};

pair<ll, vector<Edge>> prim(int s, int n, vector<vector<pii>> &g) {
	ll ans = 0;
	vector<int> par(n+1);
	vector<Edge> MST;
	vector<int> vis(n+1);
	vector<ll> d(n+1, 1e18);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	d[s] = 0;
	pq.push({d[s], s});
	while (!pq.empty()) {
		auto [dist, u] = pq.top(); pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		ans += dist;
		if (s != u) {
			MST.emplace_back(u, par[u], dist);
		}
		for (auto [v, w] : g[u]) {
			if (!vis[v] && d[v] > w) {
				d[v] = w;
				pq.push({d[v], v});
			}
		}
	}
	return {ans, MST};
}