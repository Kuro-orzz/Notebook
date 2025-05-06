#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"

#include "../template.h"
#include "DSU/Dsu.h"

void solve() {
	int n, q; cin >> n >> q;
	Dsu g(n);
	while (q--) {
		int tv, u, v; cin >> tv >> u >> v;
		if (tv == 0) {
			int x; cin >> x;
			cout << (g.mergePotential(u, v, x, mod) ? 1 : 0) << "\n";
		} else {
			cout << g.getDiff(u, v, mod) << '\n';
		}
	}
}