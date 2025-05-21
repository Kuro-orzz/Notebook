#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../template.h"
#include "EulerTour/EulerTour.h"
#include "../DataStructure/Fenwick/Fenwick.h"

void solve() {
	int n, q; cin >> n >> q;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<int>> adj(n);
	for (int i = 1; i < n; i++) {
		int x; cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	vector<int> st, en;
	vector<int> tour = EulerTour(st, en, adj);
	Fenwick<ll> BIT((int)tour.size() + 1);
	for (int i = 0; i < n; i++) BIT.update(st[i], a[i]);
	while (q--) {
		int type; cin >> type;
		if (type == 0) {
			int u, x; cin >> u >> x;
			BIT.update(st[u], x);
		} else if (type == 1) {
			int u; cin >> u;
			cout << BIT.get(st[u], en[u]) << '\n';
		}
	}
}