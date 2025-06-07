#include "../../template.h"
#include "../../DataStructure/DSU/Dsu.h"

struct Edge {
	int u, v, w;
	Edge() {}
	Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
};

ll kruskal(int n, vector<Edge> &edges) {
	auto cmp = [&](Edge a, Edge b) {
		return a.w < b.w;
	};
	sort(all(edges), cmp);
	Dsu g(n);
	ll ans = 0;
	for (auto [u, v, w] : edges) {
		if (g.find(u) != g.find(v)) {
			ans += w;
			g.merge(u, v);
		}
	}
	return ans;
}